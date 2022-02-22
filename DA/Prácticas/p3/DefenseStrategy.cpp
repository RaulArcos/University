// ###### Config options ################



// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"
#include "cronometro.h"
#include <vector>

using namespace Asedio;  




Vector3 cellCenterToPosition (int i, int j, float cellWidth, float cellHeight){ 
    return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); 
}

bool factibilidad (int fila, int col, std::list<Object*> obstacles, std::list<Defense*> defenses, float mapWidth, float mapHeight, int nCellsWidth, int nCellsHeight, float radio){

    //Declaramos las variables cellWidth y cellHeight
    float cellWidth = mapWidth / nCellsWidth, cellHeight = mapHeight / nCellsHeight, distance;

    Vector3 pos = cellCenterToPosition(fila, col, cellWidth, cellHeight);

    //Si la posición x o y (contando con el radio) sobrepasa el mapa, no es factible
    if (pos.x+radio <= mapWidth && pos.x-radio >= 0 && pos.y+radio <= mapHeight && pos.y-radio >= 0)
    {
        //Apuntamos a la primera defensa y objeto disponible de la lista.
        List<Object*>::iterator currentObstacles = obstacles.begin();
        List<Defense*>::iterator currentDefense = defenses.begin();

        //Recorremos la lista de obstáculos buscando colisiona alguno con la celda actual.
        while(currentObstacles != obstacles.end())
        {
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

float defaultCellValue(int row, int col, bool** freeCells, int nCellsWidth, int nCellsHeight
    , float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {
    	
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    Vector3 cellPosition((col * cellWidth) + cellWidth * 0.5f, (row * cellHeight) + cellHeight * 0.5f, 0);
    	
    float val = 0;
    for (List<Object*>::iterator it=obstacles.begin(); it != obstacles.end(); ++it) {
	    val += _distance(cellPosition, (*it)->position);
    }

    return val;
}

struct Cell
{
    float valor;
    int row;
    int col;
};

//ORDENACIÓN POR FUSIÓN
void fusionFinal(Cell cell[], int i, int k, int j, int N){
    int n = j-i+1;
    int p = i, q = k+1;
    Cell aux[N];
    for (int a = 0; a <= n; a++){
        if (p <= k && (q > j || cell[p].valor >= cell[q].valor)){
            aux[a] = cell[p];
            p++;
        } else {
            aux[a] = cell[q];
            q++;
        }
        cell[i+a]=aux[a];
    }
}

void ordenacionFusion(Cell cell[], int i, int j, int N){
    if (i<j){
        int k=(i+j)/2;
        ordenacionFusion(cell, i, k, N);
        ordenacionFusion(cell, k + 1, j, N);
        fusionFinal(cell, i, k, j, N);
    }
}





//ORDENACIÓN RÁPIDA
void CellRapida (Cell *cell, int i, int j){
    if (i<j){

        //Pivote
        int p = i; 
        Cell aux = cell[i];
	    for (int k = i+1; k<=j; k++)
		    if (cell[k].valor > aux.valor)
            {
			    p++;
			    std::swap(cell[p], cell[k]);	
		    }
	    
        cell[i] = cell[p];
	    cell[p] = aux;
        //End-Pivote
        CellRapida(cell, i, p-1);
        CellRapida(cell, p + 1, j);
    }
}

//ORDENACIÓN POR MONTÍCULO.
void finalMonticulo(Cell *cell, int n, int i) {
    int padre = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && cell[izq].valor > cell[padre].valor)
        padre = izq;

    if (der < n && cell[der].valor > cell[padre].valor)
        padre = der;

    if (padre != i) {
        std::swap(cell[i], cell[padre]);
        finalMonticulo(cell, n, padre);
    }
}

void CellMonticulo(Cell *cell, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        finalMonticulo(cell, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(cell[0], cell[i]);
        finalMonticulo(cell, i, 0);
    }
}

//FUNCIÓN VORAZ ADAPTADA COPIADA DE LA PRÁCTICA 1
Vector3 voraz(bool** freeCells,Cell *cell,int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses, float radio, int id,int N)
{
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight; 
    float cellValues[nCellsWidth][nCellsHeight];
    float max = 0;
    Vector3 pos;

    for(int i = 0; i < N; i++){
            if(factibilidad(cell[i].row, cell[i].col, obstacles, defenses, mapWidth, mapHeight, nCellsWidth, nCellsHeight, radio))
            {             
                if (cell[i].valor > max)
                {
                    max = cell[i].valor;
                    pos = cellCenterToPosition(cell[i].row, cell[i].col, cellWidth, cellHeight);
                }
            }
        
    }
    return pos;
}

void DEF_LIB_EXPORTED placeDefenses3(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight
              , List<Object*> obstacles, List<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight; 

    List<Defense*>::iterator currentDefense = defenses.begin();
    Vector3 pos;
    
    float cellValues[nCellsWidth][nCellsHeight],max = 0;

    const int N = nCellsWidth*nCellsHeight;
    Cell cell[N];
    
    const double e_abs = 0.01, e_rel = 0.001; 

    
    int aux = 0;
    for(int row = 0; row < nCellsWidth; row++)
        for(int col = 0; col < nCellsHeight; col++){
            cell[aux].col = col;
            cell[aux].row = row;
            cell[aux].valor = defaultCellValue(row, col, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
            aux++;
        }
    /*
    //PRIMER MÉTODO: SIN PRE-ORDENACIÓN.
    cronometro c;
    long int r = 0;
    c.activar();
    int row, col;
    do 
    {	
        //Recorremos todas las celdas por cada defensa y cogemos la mejor disponible.
        while(currentDefense != defenses.end()) {
            pos = voraz(freeCells,cell,nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses, (*currentDefense)->radio,(*currentDefense)->id,N);
            (*currentDefense)->position.x = pos.x;
            (*currentDefense)->position.y = pos.y;
            (*currentDefense)->position.z = 0; 
            ++currentDefense;
        }	
        //Se repite hasta superar el error relativo y absoluto para tener una medida correcta.
		r++;
    } while(c.tiempo() < e_abs / e_rel + e_abs);
    c.parar();
    
    
    
    //Creamos un vector de Cell y lo llenamos con la posición y valor por defecto.
    aux = 0;
    for(int row = 0; row < nCellsWidth; row++)
        for(int col = 0; col < nCellsHeight; col++){
            cell[aux].col = col;
            cell[aux].row = row;
            cell[aux].valor = defaultCellValue(row, col, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
            aux++;
        }

    //SEGUNDO MÉTODO: CON PRE-ORDENACIÓN.
    cronometro c2;
    long int r2 = 0;
    c2.activar();

    do
    {
        ordenacionFusion(cell, 0, N-1, N);

       while(currentDefense != defenses.end()) {
            pos = voraz(freeCells,cell,nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses, (*currentDefense)->radio,(*currentDefense)->id,N);
            (*currentDefense)->position.x = pos.x;
            (*currentDefense)->position.y = pos.y;
            (*currentDefense)->position.z = 0; 
            ++currentDefense;
        }	
        
        r2++;
    }while(c2.tiempo() < e_abs / e_rel + e_abs);
    c2.parar();
    

    //Creamos un vector de Cell y lo llenamos con la posición y valor por defecto.
    aux = 0;
    for(int row = 0; row < nCellsWidth; row++)
        for(int col = 0; col < nCellsHeight; col++){
            cell[aux].col = col;
            cell[aux].row = row;
            cell[aux].valor = defaultCellValue(row, col, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
            aux++;
    }
    
    //TERCER MÉTODO: ORDENACIÓN RÁPIDA.
    cronometro c3;
    long int r3 = 0;
    c3.activar();
    do{
        */
        CellRapida(cell, 0, N-1);

       while(currentDefense != defenses.end()) {
            pos = voraz(freeCells,cell,nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses, (*currentDefense)->radio,(*currentDefense)->id,N);
            (*currentDefense)->position.x = pos.x;
            (*currentDefense)->position.y = pos.y;
            (*currentDefense)->position.z = 0; 
            ++currentDefense;
        }	
    /* 
        ++r3;
    }while(c3.tiempo() < e_abs / e_rel + e_abs);
    c3.parar();
    
    //Creamos un vector de Cell y lo llenamos con la posición y valor por defecto.
    aux = 0;
    for(int row = 0; row < nCellsWidth; row++)
        for(int col = 0; col < nCellsHeight; col++){
            cell[aux].col = col;
            cell[aux].row = row;
            cell[aux].valor = defaultCellValue(row, col, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
            aux++;
        }
    /*
    cronometro c4;
    long int r4 = 0;
    c4.activar();
    do{
        
        CellMonticulo(cell, N);

        while(currentDefense != defenses.end()) {
            pos = voraz(freeCells,cell,nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses, (*currentDefense)->radio,(*currentDefense)->id,N);
            (*currentDefense)->position.x = pos.x;
            (*currentDefense)->position.y = pos.y;
            (*currentDefense)->position.z = 0; 
            ++currentDefense;
        }	 
        ++r4;
    }while(c4.tiempo() < e_abs / e_rel + e_abs);
    c4.parar();

    std::cout << (nCellsWidth * nCellsHeight) << '\t' << c.tiempo() / r << '\t' << c2.tiempo() / r2 << '\t' << c3.tiempo() / r3 << '\t' << c4.tiempo() / r4 << std::endl;
    */
}

