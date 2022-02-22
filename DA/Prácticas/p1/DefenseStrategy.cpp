// ###### Config options ################

//#define PRINT_DEFENSE_STRATEGY 1    // generate map images

// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"
#include <vector>
using std::vector;

#ifdef PRINT_DEFENSE_STRATEGY
#include "ppm.h"
#endif

#ifdef CUSTOM_RAND_GENERATOR
RAND_TYPE SimpleRandomGenerator::a;
#endif

using namespace Asedio;

Vector3 vorazCentro (bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses, float radio);
Vector3 voraz(int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses, float radio,int id);

//cellCenterToPosition, sacada del apartado de preguntas frecuentes del campus.
Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight)
{ 
    return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); 
}

// Devuelve la celda a la que corresponde una posición en el mapa, sacada del apartado de preguntas frecuentes del campus.
void positionToCell(const Vector3 pos, int &i_out, int &j_out, float cellWidth, float cellHeight)
{ 
    i_out = (int)(pos.y * 1.0f/cellHeight); j_out = (int)(pos.x * 1.0f/cellWidth); 
}

//Otorga valor a las celdas en función a su posición en el mapa.
float cellValue(int i, int j, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses,bool central)
{
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    float nearObstacle = 0;
    float value = 0;
    List<Defense*>::iterator currentDefense = defenses.begin();
    List<Object*>::iterator currentObstacles = obstacles.begin();

    Vector3 pos =  cellCenterToPosition (i, j, cellWidth, cellHeight);
    Vector3 posCentralMap = cellCenterToPosition (nCellsWidth/2, nCellsHeight/2, cellWidth, cellHeight);
    
    //Calculamos las distancias de la celda a evaluar con el centro, los obstáculos (quedandonos con el más cercano) y con el centro de extracción.
    float distanceCellToCenter = sqrt(((pos.x - posCentralMap.x)*(pos.x - posCentralMap.x)) + ((pos.y - posCentralMap.y)*(pos.y - posCentralMap.y)));
    float distanceCellToObstacle;
    float distanceCellToDefenseZero = sqrt(((pos.x - (*currentDefense)->position.x)*(pos.x - (*currentDefense)->position.x)) + ((pos.y - (*currentDefense)->position.y)*(pos.y - (*currentDefense)->position.y)));

    //Recorremos todos los obstáculos para hallar la celda que menos distancia tenga con alguno.

    while(currentObstacles != obstacles.end())  
    {
        distanceCellToObstacle = sqrt(((pos.x - (*currentObstacles)->position.x)*(pos.x - (*currentObstacles)->position.x)) + ((pos.y - (*currentObstacles)->position.y)*(pos.y - (*currentObstacles)->position.y)));
        //Cuanto más cerca esté de un obstáculo será valorada positivamente.
        if(nearObstacle < (1 - (distanceCellToObstacle)/mapWidth))
        {
            nearObstacle = (1 - (distanceCellToObstacle)/mapWidth);
        }
        currentObstacles++;
    }
    //Para la central, vamos a intentar buscar una posición central del mapa y que no se encuentre pegada a un obstáculo.
    if(central)
        value = (1000 - distanceCellToCenter)/nearObstacle;
    else
    //En cambio para las defensas, buscamos que rodeen a la posición de la central de extracción.
        value = (1000 - distanceCellToDefenseZero);
    
    return value;
}

void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) 
{
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight; 
    List<Defense*>::iterator currentDefense = defenses.begin();
    Vector3 pos;
    
    //Recorremos la lista de defensas y las jocamos en el mapa según la función voraz.
    while(currentDefense != defenses.end()) {
        pos = voraz(nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses, (*currentDefense)->radio,(*currentDefense)->id);
        (*currentDefense)->position.x = pos.x;
        (*currentDefense)->position.y = pos.y;
        (*currentDefense)->position.z = 0; 
        ++currentDefense;
    }

#ifdef PRINT_DEFENSE_STRATEGY

    float** cellValues = new float* [nCellsHeight]; 
    for(int i = 0; i < nCellsHeight; ++i) {
       cellValues[i] = new float[nCellsWidth];
       for(int j = 0; j < nCellsWidth; ++j) {
           cellValues[i][j] = ((int)(cellValue(i, j))) % 256;
       }
    }
    dPrintMap("strategy.ppm", nCellsHeight, nCellsWidth, cellHeight, cellWidth, freeCells
                         , cellValues, std::list<Defense*>(), true);

    for(int i = 0; i < nCellsHeight ; ++i)
        delete [] cellValues[i];
	delete [] cellValues;
	cellValues = NULL;

#endif
}

//Funcion de factibilidad, comrueba que las defensas aparecen dentro del mapa (INCLUIDO SU RADIO)
bool factibilidad (int fila, int jumna, std::list<Object*> obstacles, std::list<Defense*> defenses, float mapWidth, float mapHeight, int nCellsWidth, int nCellsHeight, float radio){

    //Declaramos las variables cellWidth y cellHeight
    float cellWidth = mapWidth / nCellsWidth, cellHeight = mapHeight / nCellsHeight, distance;

    Vector3 pos = cellCenterToPosition(fila, jumna, cellWidth, cellHeight);

    //Si la posición x o y (contando con el radio) sobrepasa el mapa, no es factible
    if (pos.x+radio <= mapWidth && pos.x-radio >= 0 && pos.y+radio <= mapHeight && pos.y-radio >= 0)
    {
        //Apuntamos a la primera defensa y objeto disponible de la lista.
        List<Object*>::iterator currentObstacles = obstacles.begin();
        List<Defense*>::iterator currentDefense = defenses.begin();

        //Recorremos la lista de obstáculos buscando colisiona alguno con la celda actual.
        while(currentObstacles != obstacles.end()){
            distance = sqrt(((*currentObstacles)->position.x - pos.x)*((*currentObstacles)->position.x - pos.x) + ((*currentObstacles)->position.y - pos.y)*((*currentObstacles)->position.y - pos.y));
            if (distance < ((*currentObstacles)->radio + radio))
                return 0;
            ++currentObstacles;
        }
        //Recorremos la lista de defensas buscando si colisiona alguna con la celda actual.
        while(currentDefense != defenses.end()){
            distance = sqrt(((*currentDefense)->position.x - pos.x)*((*currentDefense)->position.x - pos.x) + ((*currentDefense)->position.y - pos.y)*((*currentDefense)->position.y - pos.y));
            if (distance < ((*currentDefense)->radio + radio))
                return 0;
            ++currentDefense;
        }

        //Si ambos while terminan, significa que la celda está libre, por lo que devolvemos 1.
        return 1;  
    }

    return 0;
}
Vector3 voraz(int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses, float radio, int id)
{
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight; 
    float cellValues[nCellsWidth][nCellsHeight];
    float max = 0;
    Vector3 pos;

    for(int i = 0; i < nCellsWidth; i++){
        for(int j = 0; j < nCellsHeight; j++){  
            if(factibilidad(i, j, obstacles, defenses, mapWidth, mapHeight, nCellsWidth, nCellsHeight, radio))
            {             
                //Valor de la celda en el caso de ser la central
                if(id == 0)                
                    cellValues[i][j] = cellValue(i, j, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses,1);           
                //Valor de la celda en caso de ser defensa
                else
                    cellValues[i][j] = cellValue(i, j, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses,0);
                //Guardamos en 'max' la celda con mayor valor.
                if (cellValues[i][j] > max)
                {
                    max = cellValues[i][j];
                    pos = cellCenterToPosition(i, j, cellWidth, cellHeight);
                }
            }
        }
    }
    return pos;
}