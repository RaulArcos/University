// ###### Config options ################


// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

using namespace Asedio;

float value (Defense* defense)
{
    //Elegimos la defensa con mas ratio rango-dañoporsegundo y vida.
    return(((defense->range*defense->damage)/defense->attacksPerSecond) * defense->health);
}

void DEF_LIB_EXPORTED selectDefenses(std::list<Defense*> defenses, unsigned int ases, std::list<int> &selectedIDs
            , float mapWidth, float mapHeight, std::list<Object*> obstacles) 
{
    //Compramos la primera defensa (Central)
    std::list<Defense*>::iterator currentDefense = defenses.begin();
    selectedIDs.push_back((*currentDefense)->id);
    ases-=(*currentDefense)->cost;
    currentDefense++;
    
    //Declaramos una matriz dinámica que usaremos como tabla de defensas-ases.
    float** table =  new float*[defenses.size()-1];
    //Creamos un vector para el coste (peso) de cada defensas
    int cost[defenses.size()-1];

    //Inicializamos tanto el vector de coste como la tabla TSR
    for(int i = 0; i < (defenses.size() - 1); i++)
    {
        table[i] = new float[ases];
        cost[i]=(*currentDefense)->cost;
        
        for(int j = 0; j < ases; j++)
            if(j < cost[i])
                //Si no es la primera defensa (Sin contar la central)
                if((*currentDefense)->id != 1) 
                    table[i][j] = table[i-1][j];
                else
                    table[i][j] = 0;  
            else 
                //Si no es la primera defensa (Sin contar la central)   
                if((*currentDefense)->id != 1)
                    table[i][j]=std::max(table[i-1][j], (table[i-1][j-cost[i]]+value((*currentDefense))));
                else
                    table[i][j] = value((*currentDefense));
        currentDefense++;
    }


    int j = ases-2;
    int i;
    
    //Busqueda de la solución
    for(i = defenses.size() - 2; i > 0 ; i--)
    {
        if(table[i][j] != table[i-1][j])
        {
            selectedIDs.push_back(i+1);
            j -= cost[i];
        }
    }
    if(i == 0 && cost[i] <= j)
    {
        selectedIDs.push_back(i+1);
        j -= cost[i];
    }  
}

