#include "estructuras.h"    //Incluimos las librerias necesarias para el funcionamiento del codigo
#include "menu_partida.h"

//Declaramos las funciones que van a ser utilizadas
void espera(jugador **, int , configurar **);
void inicio_juego(jugador **, int, configurar **);
void logueo_jugador(jugador **, int, configurar **);
void inicio_juego(jugador **j, int x, configurar **c);
void espera(jugador **j, int x, configurar **c);
void comenzar_partida(jugador **, int , configurar **, mapita **, tormenta **);
void movimiento_random (int* , int*, configurar **);
void mostrar_menu(jugador **, int, mapita **, int, configurar **, tormenta **);

// void inicio_juego(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Inicializamos la opción para que el jugador pueda iniciar una partida
void inicio_juego(jugador **j, int x, configurar **c){
  int i, vivos=0;
  int op;
  char est[4] = "EE";
  char adm[4] = "ADM";

     // Mostramos las opciones sobre jugar una partida
    for(i=0; i<numero_jugadores; i++){
        if(strcmp((*j)[x].estado, "EJ")==0){
            vivos++;
        }
    }
    if(vivos!=0 && strcmp((*j)[x].estado, "EJ")!=0){
        printf("HAY UNA PARTIDA EN JUEGO\n Debera esperar a la proxima partida\n");
    } else if(vivos!=0 && strcmp((*j)[x].estado, "EJ")==0) {
        mostrar_menu(&pjugador, x, &pmapa, vivos, &pconfigurar, &ptormenta);
    } else if(strcmp((*j)[x].estado, est)==0){
        espera(&pjugador, x, &pconfigurar);
    }
    else{
    do{
    printf("\n\t%c%cDesea Jugar una partida?%c\n\n\t[1] SI\n\n\t[2] NO. Volver al menu principal\n", 254,168,254);
    scanf("%d", &op);

    switch(op){ // Ejecutamos las opciones

        case 1: espera(&pjugador, x, &pconfigurar); break; // Opción esperar
        case 2: if(strcmp((*j)[x].perfil, adm)==0) logueo_adm(&pjugador, x, &pconfigurar); // Comprobamos si el perfil es JGD o ADM
                else logueo_jugador(&pjugador, x, &pconfigurar);
        default: system("cls"); printf("OPCION INCORRECTA");

        }
    }while(op<1 || op>2); // Hasta introducir una opción válida
    }


}

// void espera(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Inicializa el tiempo de espera para empezar la partida
void espera(jugador **j, int x, configurar **c){
  int op=0;
  system("cls"); // Limpiamos pantalla
  int jesp=0, i;
  char est[4] = "EE";
  char adm[4] = "ADM";

    printf("--JUGADORES EN ESPERA--\n"); // Mostramos que hay jugadores en espera

    for(i=0; i<numero_jugadores; i++){ // Comprobamos cuantos jugadores hay en espera

        if(strcmp((*j)[i].estado, est)==0){ // Mostramos por pantalla

            printf("%s\n", (*j)[i].nick);
            jesp++;

        }
    }

    printf("\nSU ESTADO ACTUAL ES: EN ESPERA\n\n");// Notificamos del estado actual
    strcpy((*j)[x].estado, est);

    if(jesp<(*c)[0].minimo){ // Vemos si el nº de jugadores es suficiente para iniciar
        printf("\nNo hay jugadores suficientes para comenzar todavia una partida\n");
        system("PAUSE");
    }
    else{ // Vemos si el nº de jugadores es suficiente
        printf("\nHay Jugadores suficientes para comenzar una partida\n\n"); // Vemos que podemos comenzar
        if(strcmp((*j)[x].perfil, adm)==0){
            printf("Si deseas iniciar una partida, pulse [1]\nSi desea volver al menu principal, pulse [2]\n"); // Si es suficiente el ADM puede iniciar la partida o volver al menu principal
            do{
                scanf("%d", &op);
                switch(op){
                    case 1: comenzar_partida(&pjugador, x, &pconfigurar, &pmapa, &ptormenta); break;
                    case 2: logueo_adm(&pjugador, x, &pconfigurar); break;
                    default: printf("Tecla Incorrecta\n");
                }
            }while(op<1 || op>2);


        } else {printf("SOLO LOS ADMINISTRADORES PUEDEN INICIAR LA PARTIDA\n\n"); system("PAUSE");}
    }
    // Comprobamos si el perfil es JGD o ADM
    if(strcmp((*j)[x].perfil, adm)==0) logueo_adm(&pjugador, x, &pconfigurar);
    else logueo_jugador(&pjugador, x, &pconfigurar);
}
//void comenzar_partida(jugador **j, int x, configurar **c, mapita **mp, tormenta **t)
// {P} Estructura jugador, configuracion, mapita, y tormenta inicializadas y la posicion x del jugador en la estructura
// {Q} Crea la partida con los ajustes necesarios y enseña el menu de partida
void comenzar_partida(jugador **j, int x, configurar **c, mapita **mp, tormenta **t){
int i=0, n=0, vivos=0;
char jug[8]="Jugador";
    for(n=0; n<numero_jugadores; n++){ //Bucle for para comprobar los jugadores que estan en EE
        if(strcmp((*j)[n].estado, "EE")==0){ //Si estan en EE, se les cambia una seria de datos, y se copian a las diferentes estructuras
            strcpy((*mp)[i].tipo, jug);
            strcpy((*mp)[i].nick, (*j)[n].nick);
            movimiento_random(&(*mp)[i].posx, &(*mp)[i].posy, &pconfigurar);
            strcpy((*j)[n].estado, "EJ");
            vivos++;
            i++;
        }  //Si no, pasa al siguiente
    }
    guardar_mapa(&pmapa);           //Se guarda el mapa.txt, se crea una tormenta y se manda a tormenta.txt y se muestra el menu
    tormenta_aleatoria(&pconfigurar);
    cargar_storm(&ptormenta);
    mostrar_menu(&pjugador, x, &pmapa, vivos, &pconfigurar, &ptormenta);
}
// void movimiento_random (int *posx , int *posy, configurar **c)
// {P} Estructura configurar inicializada y la posx y posy de la estructura mapa
// {Q} Crea una posicion X,Y aleatoria para cada jugador que vaya a jugar la partida
void movimiento_random (int *posx , int *posy, configurar **c){
	 *posx=-(*c)[0].tamano + rand() % (((*c)[0].tamano+1) + (*c)[0].tamano);
	 *posy=-(*c)[0].tamano + rand() % (((*c)[0].tamano+1) + (*c)[0].tamano);
}




