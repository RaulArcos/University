/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"



tNodo *PSEUDOminimax(tNodo *t) {
     int mejorJugada = -1;
     int puntos = -2;
     int i, temp;
     tNodo *intento=malloc(sizeof(tNodo));
     printf("\n Mi turno: \n");
     for(i = 0; i < 9; ++i){
      if (esValida(t,i)) {
            intento=aplicaJugada(t,1,i); //Intenta jugada
            temp =terminal(intento); // Calcula el valor minimax
            if(temp > puntos) {
              puntos = temp;
              mejorJugada = i;
            }
      }}//for
      t=aplicaJugada(t,1,mejorJugada);
      return t;
}

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}

tNodo *minimax(tNodo *nodo,int jugador)
{
      int max,max_actual,jugada,mejorjugada;  
      tNodo intento;
      tNodo *intento=(tNodo*) calloc(1,sizeof(tNodo));
      max=-10000;
      
      for(int i = 0; i<N; i++)
      {
            if(esValida(nodo,jugada))
            {
              tNodo *intento=aplicaJugada(nodo,jugador,jugada);
              max_actual= ValorMin(intento);
              if(max_actual>max)
              {
                    max=max_actual;
                    mejorjugada=jugada;
              }
            }

      }
      nodo = aplicaJugada(nodo,jugador,mejorjugada);
}
//Numero de columnas filas y diagonales con x y sin 0 - numero de columnas, filas y diagonales con 0 y sin X

int heuristica(tNodo *nodo)
{
      int heuristica = 0;
      int x,O;
      //Numero de columnas filas y diagonales con x y sin 0
      if(nodo->celdas[0,1,2] != -1 && (nodo->celdas[0] == 1 || nodo->celdas[1] == 1 || nodo->celdas[2] == 1)) x++; //fila 1
      if(nodo->celdas[3,4,5] != -1 && (nodo->celdas[3] == 1 || nodo->celdas[4] == 1 || nodo->celdas[5] == 1)) x++; //fila 2
      if(nodo->celdas[6,7,8] != -1 && (nodo->celdas[6] == 1 || nodo->celdas[7] == 1 || nodo->celdas[8] == 1)) x++; //fila 3
      if(nodo->celdas[0,3,6] != -1 && (nodo->celdas[0] == 1 || nodo->celdas[3] == 1 || nodo->celdas[6] == 1)) x++; //columna 1
      if(nodo->celdas[1,4,7] != -1 && (nodo->celdas[1] == 1 || nodo->celdas[4] == 1 || nodo->celdas[7] == 1)) x++; //columna 2
      if(nodo->celdas[2,5,8] != -1 && (nodo->celdas[2] == 1 || nodo->celdas[5] == 1 || nodo->celdas[8] == 1)) x++; //columna 3
      if(nodo->celdas[0,4,8] != -1 && (nodo->celdas[0] == 1 || nodo->celdas[4] == 1 || nodo->celdas[8] == 1)) x++; //diagonal 1
      if(nodo->celdas[2,4,6] != -1 && (nodo->celdas[2] == 1 || nodo->celdas[4] == 1 || nodo->celdas[6] == 1)) x++; //diagonal 2
       //Numero de columnas filas y diagonales con 0 y sin x
      if(nodo->celdas[0,1,2] != 1 && (nodo->celdas[0] == -1 || nodo->celdas[1] == -1 || nodo->celdas[2] == -1)) O++; //fila 1
      if(nodo->celdas[3,4,5] != 1 && (nodo->celdas[3] == -1 || nodo->celdas[4] == -1 || nodo->celdas[5] == -1)) O++; //fila 2
      if(nodo->celdas[6,7,8] != 1 && (nodo->celdas[6] == -1 || nodo->celdas[7] == -1 || nodo->celdas[8] == -1)) O++; //fila 3
      if(nodo->celdas[0,3,6] != 1 && (nodo->celdas[0] == -1 || nodo->celdas[3] == -1 || nodo->celdas[6] == -1)) O++; //columna 1
      if(nodo->celdas[1,4,7] != 1 && (nodo->celdas[1] == -1 || nodo->celdas[4] == -1 || nodo->celdas[7] == -1)) O++; //columna 2
      if(nodo->celdas[2,5,8] != 1 && (nodo->celdas[2] == -1 || nodo->celdas[5] == -1 || nodo->celdas[8] == -1)) O++; //columna 3
      if(nodo->celdas[0,4,8] != 1 && (nodo->celdas[0] == -1 || nodo->celdas[4] == -1 || nodo->celdas[8] == -1)) O++; //diagonal 1
      if(nodo->celdas[2,4,6] != 1 && (nodo->celdas[2] == -1 || nodo->celdas[4] == -1 || nodo->celdas[6] == -1)) O++; //diagonal 2

      heuristica = x-O;
      return heuristica;

}