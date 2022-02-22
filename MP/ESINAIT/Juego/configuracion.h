#include "estructuras.h" // Incluimos las librerías necesarias para el funcionamiento del código

// Inicializamos los prototipos
void opciones_adm(jugador **, int x, configurar **);
void configuracion_partida(configurar **, int, int);
void cambiar_datos(jugador**,int);
void logueo_adm(jugador **, int, configurar **);
void comenzar_partida(jugador **, int, configurar **, mapita **, tormenta **t);
void tormenta_aleatoria(configurar **);

// void opciones_adm(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Otorga al jugador ADM las respectivas opciones
void opciones_adm(jugador **j, int x, configurar **c){
    system("cls");
    int jesp=0, i, ej=0;
    int op;
    for(i=0; i<numero_jugadores; i++){ // Comprobamos cuantos jugadores hay en espera
                if(strcmp((*j)[i].estado, "EE")==0){ // Mostramos por pantalla
                    jesp++;
                }
                if(strcmp((*j)[i].estado, "EJ")==0){
                    ej++;
                }
            }

    do{ // Pedimos valor para acceder a una opción

        printf("\n\t%cEDITOR DEL JUEGO. %cQue ajustes deseas realizar?%c\n\n\t[1] Iniciar Partida\n\n\t[2] Cambiar configuracion Partida\n\n\t[3] Datos Jugadores\n\n\t[4]Salir al Menu Principal\n", 254, 168, 254);
        scanf("%i", &op);

        switch(op){ // Ejecutmaos dichas opciones
            case 1: if(jesp>=(*c)[0].minimo || ej!=0){ // Vemos si el nº de jugadores es suficiente para iniciar
                        printf("\nHAY UNA PARTIDA EN JUEGO\n");
                        system("PAUSE");
                        opciones_adm(&pjugador, x, &pconfigurar);
                    }
                    else{ // Vemos si el nº de jugadores es suficiente
                        printf("LA PARTIDA VA A COMENZAR\n");
                        system("PAUSE");
                        tormenta_aleatoria(&pconfigurar);
                        cargar_storm(&ptormenta);
                        comenzar_partida(&pjugador, x, &pconfigurar, &pmapa, &ptormenta);
                    } break; // Opción iniciar partida
            case 2: configuracion_partida(&pconfigurar, x, ej); break; // Opción para configurar
            case 3: cambiar_datos(&pjugador,x); break; // Opción para ver los datos de jugadores
            case 4: logueo_adm(&pjugador, x, &pconfigurar); break; // Opción para loguear admin
            default: system("cls"); printf("Opcion Incorrecta\n"); // opción incorrecta
        }
    }while(op<1 || op>4); // Hasta introducir una opción válida

}

// void configuracion_partida(configurar **c, int x)
// {P} Estructura configuración inicializada y cargada
// {Q} Accede a la opción de configuración para el ADM
void configuracion_partida(configurar **c, int x, int ej){

  system("cls");
  int n=0;
  int op;

    if(ej!=0){
            printf("HAY UNA PARTIDA EN JUEGO. NO PUEDE HACER CAMBIOS EN LA CONFIGURACION\n");
            system("PAUSE");
            opciones_adm(&pjugador, x, &pconfigurar);
    } else {

    do{ // Mostramos las opciones para los ajustes a realizar

        printf("\n\t%c%cQue ajustes deseas realizar?%c\n\n\t", 254, 168,254);
        printf("[1] Tama%co mapa\n\n\t[2] Distancia maxima para poder recoger un objeto\n\n\t[3] Distancia Maxima para golpear con el pico\n\n\t[4] Monedas por defecto a cada jugador\n\n\t[5] Jugadores Minimos para Jugar\n\n\t[6] Valor del paso del jugador\n\n\t[7] Tama%co Mochila\n\n\t[8] Minimo de partidas ganadas para subir nivel\n\n\t[9] Numero maximo de acciones de un jugador en un turno\n\n\t[10] Volver Atras\n", 164, 164);
        scanf("%i", &op);

        switch(op){ // Ejecutamos dichas opciones

            case 1: // Opción tamaño
                    printf("Valor actual: %d\n", (*c)[n].tamano);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].tamano);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;
            case 2: // Opción distancia
                    printf("Valor actual: %d\n", (*c)[n].distancia);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].distancia);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;
            case 3: // Opción del pico

                    printf("Valor actual: %d\n", (*c)[n].pico);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].pico);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;
            case 4:  // Opción cartera

                    printf("Valor actual: %d\n", (*c)[n].cartera);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].cartera);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;
            case 5: // Opción valor mínimo

                    printf("Valor actual: %d\n", (*c)[n].minimo);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].minimo);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;

            case 6: // Opción valor del paso
                    printf("Valor actual: %d\n", (*c)[n].paso);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].paso);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;

            case 7: // Opción mochila
                    printf("Valor actual: %d\n", (*c)[n].mochila);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].mochila);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;

            case 8: // Opción experiencia
                    printf("Valor actual: %d\n", (*c)[n].exp);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].exp);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;
            case 9: // Opción número de turnos
                    printf("Valor actual: %d\n", (*c)[n].turnos);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].turnos);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x, ej);
                    break;

            case 10: // Opción para guardar configuración
                    printf("CAMBIOS GUARDADOS"); system("PAUSE");
                    guardar_config(&pconfigurar);
                    opciones_adm(&pjugador, x, &pconfigurar);
                    break;
            default: system("cls"); printf("Opcion Incorrecta"); // Opción de opción incorrrecta
        }
    }while(op<1 || op>10); // Hasta que una opción válida es introducida
    }
}

//
//
//
void cambiar_datos(jugador **j,int x){
char usuario[20];
int i,n;
char adm[4] = "ADM";
char jgd[4] = "JGD";
char opcion_datos,opcion_datos2;
system("cls") ;
  printf("\n\nIntroduce un Usuario para Cambiar sus Datos : ");
  scanf("%s",usuario);
  //Recorre el numero de jugadores registrados en la estrucura, si encuentra el usuario introducido, pasa a la función para introducir contraseña
    for(i=0;i<numero_jugadores+1;i++){

      if (strcmp((*j)[i].nick, usuario ) == 0){

        printf("\nElige el dato que quieres cambiar sobre : %s",usuario);

          do {

              printf("\n[1] Nick\n[2] Nombre\n[3] Perfil\n[4] contrasena\n[5] Cancelar Operacion\n");

              scanf("%i", &opcion_datos2);

            } while ( opcion_datos2<1 && opcion_datos2>5) ;

              switch (opcion_datos2){

                  case 1:
                  system("cls") ;
                    printf("\nNick Actual : %s\n",usuario);
                    printf("Introduzca un Nuevo Nick : ");
                    scanf("%s",(*j)[i].nick);
                    printf("\nCambio Completado con exito\n\nNick Actual : %s\n",(*j)[i].nick);
                    system("Pause");
                    logueo_adm(&pjugador,x,&pconfigurar);
                    break;

                    case 2:
                    system("cls") ;
                    printf("\nNombre Actual : %s\n",(*j)[i].nombre);
                    printf("Introduzca un Nuevo Nombre : ");
                    scanf("%s",(*j)[i].nombre);
                    printf("\nCambio Completado con exito\n\nNombre Actual : %s\n",(*j)[i].nombre);
                    system("Pause");
                    logueo_adm(&pjugador,x,&pconfigurar);
                    break;

                    case 3:
                    system("cls") ;
                    printf("\nPerfil Actual : %s\n",(*j)[i].perfil);
                    char opcion_cambioperfil;
                    do {

                      printf("\nSeleccione un Perfil Nuevo\n[1] Administrador\n[2] Jugador");

                      scanf("%i", &opcion_cambioperfil) ;

                  } while ( opcion_cambioperfil != 1 && opcion_cambioperfil !=2 ) ;

                    switch	(opcion_cambioperfil) {

                      case 1:

                            printf("\n Ahora %s es Administrador\n",(*j)[i].nick);
                            strcpy ((*j)[x].perfil,adm);
                            system("PAUSE");
                            logueo_adm(&pjugador,x,&pconfigurar);

                        break ;

                       case 2:

                        printf("\n Ahora %s es Jugador\n",(*j)[i].nick);
                        strcpy ((*j)[x].perfil,jgd);
                        system("Pause");
                        logueo_adm(&pjugador,x,&pconfigurar);
                        break;
                    }
                    break;
                    case 4:
                    system("cls") ;
                      printf("\nContrasena Actual : %s\n",(*j)[i].contrasena);
                      printf("Introduzca una Nueva Contrasena : ");
                      scanf("%s",(*j)[i].contrasena);
                      printf("\nCambio Completado con exito\n\nContrasena Actual : %s\n",(*j)[i].contrasena);
                      system("Pause");
                      logueo_adm(&pjugador,x,&pconfigurar);
                      break;

                    case 5:
                    system("cls") ;
                    logueo_adm(&pjugador,x,&pconfigurar);
                    break;

                  }
        break;
  //Si no se encuentra ningun usuario relacionado, se lo hara saber.
  }

    }

  if(x>numero_jugadores){

      printf("\nUsuario no encontrado\n");

        do {

            printf("\n[1] Reintentar\n[2] Volver al Menu principal\n");

            scanf("%i", &opcion_datos);

          } while ( opcion_datos<1 && opcion_datos>2 ) ;

            switch (opcion_datos){

                case 1:
                  system("cls") ;
                  cambiar_datos(&pjugador,x);
                  break;
                  system("cls") ;
                  logueo_adm(&pjugador,x,&pconfigurar);
                case 2:

                  break;

                }

              }


}
