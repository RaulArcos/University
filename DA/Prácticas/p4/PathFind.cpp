// ###### Config options ################

#define PRINT_PATHS 1

// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

#ifdef PRINT_PATHS
#include "ppm.h"
#endif

using namespace Asedio;

Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight){ 
    return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); 
}

void DEF_LIB_EXPORTED calculateAdditionalCost(float** additionalCost
                   , int cellsWidth, int cellsHeight, float mapWidth, float mapHeight
                   , List<Object*> obstacles, List<Defense*> defenses) {

    float cellWidth = mapWidth / cellsWidth;
    float cellHeight = mapHeight / cellsHeight;

    for(int i = 0 ; i < cellsHeight ; ++i) {
        for(int j = 0 ; j < cellsWidth ; ++j) {
            Vector3 cellPosition = cellCenterToPosition(i, j, cellWidth, cellHeight);
            float cost = 0;
            if( (i+j) % 2 == 0 ) {
                cost = cellWidth * 100;
            }
            
            additionalCost[i][j] = cost;
        }
    }
}

//Distancia directa entre los vértices.
float estimatedDistance(Vector3 a, Vector3 b){
    return (sqrt(pow((a.x-b.x), 2) + pow((a.y-b.y), 2)));
}

//Pertenencia de un nodo en un vector de nodos.

bool perteneceNodo (std::vector<AStarNode*> vnodo, AStarNode* nodo){
    
    for (std::vector<AStarNode*>::iterator i = vnodo.begin(); i != vnodo.end(); ++i)
        if ((*i) == nodo)
            return true;

    return false;
}

bool condition (AStarNode* a, AStarNode* b){
    return (a->H > b->H);
}

void DEF_LIB_EXPORTED calculatePath(AStarNode* originNode, AStarNode* targetNode
                   , int cellsWidth, int cellsHeight, float mapWidth, float mapHeight
                   , float** additionalCost, std::list<Vector3> &path) {

    //Para resolver esta práctica utilizaremos el algoritmo A* facilitado en las diapositivas del tema 4.

    AStarNode* current = originNode; //Cur
    std::vector<AStarNode*> o; //Opened
    std::vector<AStarNode*> c; //Closed
    bool found = false;

    current->G = 0;
    //estimatedDistance((cur,target) + additional cost)
    current->H = (estimatedDistance(current->position, targetNode->position)) + additionalCost[(int)(current->position.x/cellsWidth)][(int)(current->position.y/cellsHeight)];
   
    current->parent = NULL;
    current->F = current->G + current->H;

    //Comienzo del algoritmo A*
    std::make_heap(o.begin(), o.end(), condition);
    o.push_back(current);
    while(!found && !o.empty()){
        current = o.back();
        o.pop_back();
        c.push_back(current);
        if(current == targetNode)
            found = true;
        else{
            for(List<AStarNode*>::iterator it = current->adjacents.begin(); it != current->adjacents.end(); it++)
            {
                if(!perteneceNodo(c,(*it)))
                    if(!perteneceNodo(o,(*it))){
                        (*it)->parent = current;
                        (*it)->G = current->G + estimatedDistance(current->position,(*it)->position);
                        (*it)->H = estimatedDistance((*it)->position, targetNode->position) + additionalCost[(int)(*it)->position.x/cellsWidth][(int)(*it)->position.y/cellsHeight];
                        (*it)->F = (*it)->G + (*it)->H;
                        o.push_back((*it));
                        std::make_heap(o.begin(), o.end(), condition);
                        std::sort_heap(o.begin(), o.end(), condition);
                    }
                    else
                        if((*it)->G > current->G + estimatedDistance(current->position, (*it)->position)){
                            
                            (*it)->parent = current;
                            (*it)->G = current->G + estimatedDistance(current->position, (*it)->position);
                            (*it)->F = (*it)->G + (*it)->H;
                            std::make_heap(o.begin(), o.end(), condition);
                            std::sort_heap(o.begin(), o.end(), condition);
                        }
            }
                
        }
    }

    
    //Recuperanción del camino obtenido
    current = targetNode;
    path.push_front(targetNode->position);

    while(current->parent != originNode && current->parent != NULL){
        current = current->parent;
        path.push_front(current->position);
    }
           
}
