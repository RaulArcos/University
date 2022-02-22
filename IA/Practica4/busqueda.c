/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"
int comprobarcerrado(LISTA c,tNodo *actual);
int heuristica(tNodo *actual);
int comprobarordenado(LISTA c);
LISTA ordenacionvoraz(LISTA c);

void solucionFin(int res){
   printf("\nFin de la busqueda\n");
    if (res)
      printf("Se ha llegado al objetivo\n");
   else
      printf("No se ha llegado al objetivo\n");
}
void dispNodo(tNodo *nodo){
    dispEstado(nodo->estado);
    printf("\n");
}
void dispCamino(tNodo *nodo){
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
        
        dispOperador(nodo->operador);
        
        dispEstado(nodo->estado);
        
    }
}

void dispSolucion(tNodo *nodo){
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}


/* Crea el nodo ra�z. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}

LISTA expandir(tNodo *nodo){
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;
    for (op=1; op<=NUM_OPERADORES;op++){
      if (esValido(op,nodo->estado)){
                        //s=(tEstado *)calloc(1,sizeof(tEstado));
          s=aplicaOperador(op,nodo->estado);
          nuevo->estado=s;
          nuevo->padre=nodo;
          nuevo->operador=op;
          nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
          nuevo->profundidad=nodo->profundidad+1;
          nuevo->valHeuristica = heuristica(nodo);
          InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
      }
  }
return sucesores;
}

int busqueda(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();
    tNodo *nodo;
    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados = VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    printf("\nHay %i huecos mal",heuristica(Inicial));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        
    if(!comprobarcerrado(Cerrados,Actual)){
        objetivo=testObjetivo(Actual->estado);
        visitados++;
    
        if (!objetivo){
            Sucesores = expandir(Actual);
            Abiertos= Concatenar(Abiertos,Sucesores);
            ordenacionvoraz(Abiertos);
            InsertarUltimo(&Cerrados,  (tNodo *) Actual, (sizeof (tNodo)));
            
      }
    }
   }//while
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    free(Cerrados);
    return objetivo;
}

int comprobarcerrado(LISTA c,tNodo *actual)
{   
    int flag=0;
    if(!esVacia(c))
    {
        while(c != NULL)
        {
            
            tNodo *nodo=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(c,nodo, sizeof(tNodo));
                if(iguales(nodo->estado,actual->estado))
                {
                    flag =1;
                
                }
                c=c->next; 
        }
        
    }
   
    return flag;
}

int heuristica(tNodo *actual)
{
    int Nmal=0;
   
    tEstado *objetivo = estadoObjetivo();
   
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {           
            if(actual->estado->celdas[i][j] != objetivo->celdas[i][j])
            {
                Nmal++;
            }
        }
    }
    return Nmal;
}

LISTA ordenacionvoraz(LISTA c)
{
    LISTA aux=VACIA;  
    if(!esVacia(c))
    {   
        while(c!=NULL)
        {
            tNodo *nodo1=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(c,nodo1, sizeof(tNodo));
            tNodo *nodo2=(tNodo*) calloc(1,sizeof(tNodo));
            aux = c->next;
            ExtraerPrimero(c,nodo2, sizeof(tNodo));

            if(nodo1->valHeuristica > nodo2->valHeuristica)
            {                
                aux = c;
                c=c->next;
                c->next = aux;
            }
        c=c->next;
        }
        if(!comprobarordenado(c))
        {
            return ordenacionvoraz(c);
        } 
    }
}

int comprobarordenado(LISTA c)
{
     LISTA aux=VACIA; 
     while(c!=NULL)
     {
            tNodo *nodo1=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(c,nodo1, sizeof(tNodo));
            tNodo *nodo2=(tNodo*) calloc(1,sizeof(tNodo));
            aux = c->next;
            ExtraerPrimero(c,nodo2, sizeof(tNodo));
    
             if(nodo1->valHeuristica < nodo2->valHeuristica)
             {
                 return 0;
             }
             
             c = c->next;
     }
     return 1;
}
LISTA ordenaciona(LISTA c)
{
    int padre1,padre2;
    LISTA aux=VACIA; 
     while(c!=NULL)
     {
            tNodo *nodo1=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(c,nodo1, sizeof(tNodo));
            padre1 = nodos_padre(nodo1);
            tNodo *nodo2=(tNodo*) calloc(1,sizeof(tNodo));
            aux = c->next;
            ExtraerPrimero(c,nodo2, sizeof(tNodo));
            padre2 = nodos_padre(nodo1);
            if(nodo1->valHeuristica+padre1 < nodo2->valHeuristica+padre2)
             {
                 return 0;
             }
             
             c = c->next;
     }
     return 1;



}

int nodos_padre(tNodo *nodo)
{
    int padre=0;
    while(nodo->estado!=NULL)
    {
        if(nodo->padre != NULL)
        {
            padre++;
        }
    }
    return padre;
}