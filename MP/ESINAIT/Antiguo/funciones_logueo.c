#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "main.h"


//Declaramos las funciones que vamos a utilizar.
void menu_logueo();
void login(jugador **);
void introducir_contrasena(jugador **,int);
void logueo_jugador(jugador **, int, configurar **);
void registar_usuario(jugador **);
void ver_perfil(jugador **,int);
void logueo_adm(jugador**,int, configurar**);
void opciones_adm(jugador **, int, configurar**);
void inicio_juego(jugador **, int, configurar**);
void configuracion_partida(configurar **,int);
void espera(jugador **,int,configurar**);
void cambiar_datos(jugador**,int);

//cabecera: void menu_logueo
//precondicion: estructura cargada.
//postcondicion: Ofrece opciones de inicio al usuario.
void menu_logueo(){

  system("cls") ;

  title();

  int opcion_logueo ;

  int opcion_perfil;
//Enseña en pantalla las opciones para el jugador
	do {
		printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Iniciar Sesion\n\n\t[2] Salir del  Sistema/Guardar datos \n", 254, 168, 254);
		scanf("%i", &opcion_logueo);

	} while ( opcion_logueo<1 && opcion_logueo>2 ) ;
//EL jugador puede elegir entre estas 2 opciones
		switch (opcion_logueo) {

			case 1:
				system("cls") ;
        //Inicia la funcion login con el puntero a estructura
				login(&pjugador);
				break ;

            case 2:
            guardar_jugador(&pjugador);
                printf("\nGracias por probar ESINITE\n");
                break ;
		}
}

//cabecera: void login(jugador **j)
//precondicion: menu_logueo().
//postcondicion: Inicia el logueo del usuario.
void login(jugador **j){
system("cls");
char opcion_logueo;
char usuario[20];
int x;
//x = numero_jugadores(&pjugador);
printf("\nIntroduce tu Usuario : ");
scanf("%s",usuario);
//Recorre el numero de jugadores registrados en la estrucura, si encuentra el usuario introducido, pasa a la función para introducir contraseña
  for(x=0;x<numero_jugadores+1;x++){

    if (strcmp((*j)[x].nick, usuario ) == 0){

      introducir_contrasena(&pjugador,x);

      break;
//Si no se encuentra ningun usuario relacionado, se lo hara saber.
}

  }

if(x>numero_jugadores){

    printf("\nUsuario no encontrado\n");

      do {

          printf("\n[1] Reintentar\n[2] Registar Un Nuevo Usuario\n[3] Volver al Menu principal\n");

          scanf("%i", &opcion_logueo);

        } while ( opcion_logueo<1 && opcion_logueo>3 ) ;

          switch (opcion_logueo){

              case 1:
                login(&pjugador);
                break;

              case 2:
                registar_usuario(&pjugador);
                break;
              case 3:
              system("cls") ;
                menu_logueo();
                break;
              }

            }
}

//cabecera: void introducir_contrasena(jugador **j,int x)
//precondicion: login().
//postcondicion: Acceder al usuario a su cuenta.
void introducir_contrasena(jugador **j,int x){
  char contra[20];
  char adm[4] = "ADM";
  char opcion_contrasena;

  printf("\n Contrasena : ");

  scanf("%s",contra);

   if(strcmp((*j)[x].contrasena, contra) == 0)  {
        if(strcmp((*j)[x].perfil, adm)==0){
            logueo_adm(&pjugador,x,&pconfigurar);
        } else logueo_jugador(&pjugador ,x, &pconfigurar);
   }

   else {
     printf("\nContrase%ca incorrecta\n", 164);

     do {

     printf("\n[1] Volver a introducir contrase%ca\n[2] Introducir un Nuevo Usuario\n[3] Salir del Sistema\n", 164);
     scanf("%i", &opcion_contrasena) ;

     } while ( opcion_contrasena != 1 && opcion_contrasena !=2 ) ;

     switch	(opcion_contrasena) {

       case 1:

         introducir_contrasena (&pjugador,x) ;
         break ;

        case 2:
          system("cls") ;
           login(&pjugador);
           break ;

       case 3:

         printf("\nGracias por utilizar ESINITE\n");
         break;
     }
   }
}

//
//
//
void logueo_jugador(jugador **j,int x, configurar **c){

    system("cls") ;

    title();
    int opcion_logueo ;
  //Enseña en pantalla las opciones para el jugador
  	do {
      printf("\n\tBienvenido %s \n",(*j)[x].nick);

    	printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Cambiar Usuario\n\n\t[2] Iniciar/Continuar un Juego\n\n\t[3] Comprar Objeto\n\n\t[4] Ver Perfil\n\n\t[5] Salir del Sistema / Guardar Partida\n", 254, 168, 254);

  		scanf("%i", &opcion_logueo);

  	} while ( opcion_logueo<1 && opcion_logueo>5 ) ;
  //EL jugador puede elegir entre estas 5 opciones
  		switch (opcion_logueo) {

        case 1:
          //Incia la funcion login con el puntero a estructura
            login(&pjugador);
            break ;

        case 2:
            system("cls");
            inicio_juego(&pjugador, x, &pconfigurar);
            break ;

        case 3:
            system("cls") ;
            printf("Comprar objeto");
            break ;

        case 4:
            system("cls") ;
            ver_perfil(&pjugador,x);
            break ;

        case 5:
            guardar_jugador(&pjugador);
            printf("\nGracias por probar ESINITE\n");
            break ;
  		}

}

//
//
//
void logueo_adm(jugador **j, int x, configurar **c){
system("cls") ;
int n;
    title();

    int opcion_logueo ;
  //Enseña en pantalla las opciones para el jugador
  	do {
      printf("\n\tBienvenido ADMINISTRADOR %s \n",(*j)[x].nick);

printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Cambiar Usuario\n\n\t[2] Iniciar/Continuar un Juego\n\n\t[3] Comprar Objeto\n\n\t[4] Ver Perfil\n\n\t[5] Opciones Administrador\n\n\t[6] Guardar Datos\n\n\t[7] Salir del  Sistema\n", 254, 168, 254);

  		scanf("%i", &opcion_logueo);

  	} while ( opcion_logueo<1 && opcion_logueo>6 ) ;
  //EL jugador puede elegir entre estas 5 opciones
  		switch (opcion_logueo) {

        case 1:
          //Incia la funcion login con el puntero a estructura
            login(&pjugador);
            break ;

        case 2:
            system("cls");
            inicio_juego(&pjugador, x, &pconfigurar);
            break ;

        case 3:
            system("cls");
            printf("Comprar objeto");
            break ;

        case 4:
            system("cls");
            ver_perfil(&pjugador,x);
            break ;

        case 5:
            system("cls");
            opciones_adm(&pjugador, x, &pconfigurar);
            break;

        case 6:

            guardar_jugador(&pjugador);
            printf("\nDatos Guardados con Exito");
            printf("\nPulse 1 para volver al menu");
            scanf("%i",&n);
            if(n==1) logueo_adm(&pjugador,x,&pconfigurar);
            break ;

        case 7:
        printf("Gracias por usar ESINITE");
        break;
  		}

}

//
//
//
void registar_usuario(jugador **j){

  system("cls") ;

  numero_jugadores++;

  int opcion_registro;
  int x=numero_jugadores-1,n,i;
  char opcion_administrador;
  char adm[4] = "ADM";
  char jgd[4] = "JGD";
  char estado_offline[4] = "OFF";
  char aux[20];

  int pin;

  printf("\nVamos a Ponerlo Todo a Punto!\n");

    printf("\nIntroduce un Nick Nuevo : ");

      scanf("%s",aux);

      for(i=0;i<numero_jugadores;i++){

        if (strcmp((*j)[i].nick, aux ) == 0){

          printf("\nEl Usuario Introducido Ya Existe\n");

          do {

            printf("\n\n[1] Iniciar Sesion\n[2] Registrar Otro Usuario\n");

            scanf("%i", &opcion_registro);

          } while ( opcion_registro != 1 && opcion_registro !=2) ;

          //EL jugador puede elegir entre estas 5 opciones
            switch (opcion_registro) {

              case 1:
                //Incia la funcion login con el puntero a estructura
              login(&pjugador);

              break ;

              case 2:

              registar_usuario(&pjugador);
              break;

          }

          break;
    //Si no se encuentra ningun usuario relacionado, se lo hara saber.
    }

      }

    if(i>numero_jugadores-1){

      strcpy ((*j)[x].nick,aux);

      printf("\nIntroduce tu Nombre : ");

      scanf("%s",(*j)[x].nombre);

      printf("\nIntroduce tu Nueva Contrasena : ");

        scanf("%s",(*j)[x].contrasena);


      do {

        printf("\nEres ADMINISTRADOR o JUGADOR : \n[1] ADMINISTRADOR\n[2] JUGADOR\n");

        scanf("%i", &opcion_administrador) ;

    } while ( opcion_administrador != 1 && opcion_administrador !=2 ) ;

      switch	(opcion_administrador) {

        case 1:
        printf("\nIntroduce el PIN de ADMINISTRADOR : ");



          do{

            scanf("%i",&pin);

            if(pin == pin_admin) {

              printf("\n Ahora eres ADMINISTRADOR\n");

              strcpy ((*j)[x].perfil,adm);

            } else (printf("\nPIN INCORRECTO, Introduce el PIN de Nuevo\n"));

          }while (pin != 1234);

          break ;

         case 2:

          printf("\n Ahora eres JUGADOR\n");

          strcpy ((*j)[x].perfil,jgd);
          break;
      }



      (*j)[x].nivel = 01;

      (*j)[x].vida = 100;

      (*j)[x].escudo = 0;

      (*j)[x].cartera= 100;

      (*j)[x].pjugadas = 0;

      (*j)[x].pganadas = 0;


  strcpy ((*j)[x].estado,estado_offline);


 // printf("%s/%s/%i/%i/%i/%s/%i/%i/%i/%s/%s/\n",(*j)[x].nick,(*j)[x].nombre,(*j)[x].nivel,(*j)[x].vida,(*j)[x].escudo,(*j)[x].estado,(*j)[x].cartera,(*j)[x].pjugadas,(*j)[x].pganadas,(*j)[x].perfil,(*j)[x].contrasena);

 }
 printf("\nUsuario Registrado con Exito, Pulsa 1 para ir al menu principal\n");

 scanf("%i",&n);

  if (n == 1 ){
    menu_logueo();
  }

      }

//
//
//
void ver_perfil(jugador **j,int x){
  char adm[4] = "ADM";
  char jgd[4] = "JGD";

int opcion_perfil2;

printf("Nick : %s\nNombre : %s\nNivel : %i\nCartera : %i Monedas\nPartidas Jugadas : %i Partidas\nPartidas Ganadas : %i Partidas\n",(*j)[x].nick,(*j)[x].nombre,(*j)[x].nivel,(*j)[x].cartera,(*j)[x].pjugadas,(*j)[x].pganadas);


do {


  printf("\n\n[1]volver al Menu Principal\n");

  scanf("%i", &opcion_perfil2);

} while ( opcion_perfil2 != 1 ) ;
    if(opcion_perfil2==1){
      if(strcmp((*j)[x].perfil, adm)==0){
        logueo_adm(&pjugador,x,&pconfigurar);
    } else logueo_jugador(&pjugador ,x, &pconfigurar);}
}

//
//
//
void opciones_adm(jugador **j, int x, configurar **c){
system("cls");
int op;

    do{
        printf("\n\t%cEDITOR DEL JUEGO. %cQue ajustes deseas realizar?%c\n\n\t[1] Iniciar Partida\n\n\t[2] Cambiar configuracion Partida\n\n\t[3] Datos Jugadores\n\n\t[4]Salir al Menu Principal\n", 254, 168, 254);
        scanf("%i", &op);

        switch(op){
            case 1: printf("Iniciar Partida"); break;
            case 2: configuracion_partida(&pconfigurar, x); break;
            case 3: cambiar_datos(&pjugador,x); break;
            case 4: logueo_adm(&pjugador, x, &pconfigurar); break;
            default: system("cls"); printf("Opcion Incorrecta\n");
        }
    }while(op<1 || op>4);

}

//
//
//
void configuracion_partida(configurar **c, int x){
system("cls");
int n=0;
int op;
    do{
        printf("\n\t%c%cQue ajustes deseas realizar?%c\n\n\t", 254, 168,254);
        printf("[1] Tama%co mapa\n\n\t[2] Distancia maxima para poder recoger un objeto\n\n\t[3] Distancia Maxima para golpear con el pico\n\n\t[4] Monedas por defecto a cada jugador\n\n\t[5] Jugadores Minimos para Jugar\n\n\t[6] Valor del paso del jugador\n\n\t[7] Tama%co Mochila\n\n\t[8] Minimo de partidas ganadas para subir nivel\n\n\t[9] Numero maximo de acciones de un jugador en un turno\n\n\t[10] Volver Atras\n", 164, 164);
        scanf("%i", &op);

        switch(op){
            case 1: printf("Valor actual: %d\n", (*c)[n].tamano);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].tamano);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 2: printf("Valor actual: %d\n", (*c)[n].distancia);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].distancia);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 3: printf("Valor actual: %d\n", (*c)[n].pico);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].pico);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 4: printf("Valor actual: %d\n", (*c)[n].cartera);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].cartera);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 5: printf("Valor actual: %d\n", (*c)[n].minimo);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].minimo);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 6: printf("Valor actual: %d\n", (*c)[n].paso);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].paso);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 7: printf("Valor actual: %d\n", (*c)[n].mochila);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].mochila);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 8: printf("Valor actual: %d\n", (*c)[n].exp);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].exp);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 9: printf("Valor actual: %d\n", (*c)[n].turnos);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].turnos);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 10:printf("CAMBIOS GUARDADOS"); system("PAUSE");
                    guardar_config(&pconfigurar);
                    opciones_adm(&pjugador, x, &pconfigurar);
                    break;
            default: system("cls"); printf("Opcion Incorrecta");
        }
    }while(op<1 || op>10);
}

//
//
//
void inicio_juego(jugador **j, int x, configurar **c){
int op;
char adm[4] = "ADM";


    do{
    printf("\n\t%c%cDesea Jugar una partida?%c\n\n\t[1] SI\n\n\t[2] NO. Volver al menu principal\n", 254,168,254);
    scanf("%d", &op);
    switch(op){
        case 1: espera(&pjugador, x, &pconfigurar); break;
        case 2: if(strcmp((*j)[x].perfil, adm)==0) logueo_adm(&pjugador, x, &pconfigurar);
                else logueo_jugador(&pjugador, x, &pconfigurar);
        default: system("cls"); printf("OPCION INCORRECTA");

        }
    }while(op<1 || op>2);

}

//
//
//
void espera(jugador **j, int x, configurar **c){
system("cls");
int jesp=0, n=0, i;
char est[4] = "EE";

    if(jesp<(*c)[n].minimo){
        printf("\nNo hay jugadores suficientes para comenzar todavia una partida\n");
        printf("\nSU ESTADO ACTUAL ES: EN ESPERA\n\n");
        strcpy((*j)[x].estado, est);
        jesp++;
    }
    printf("--JUGADORES EN ESPERA--\n");
    for(i=0; i<numero_jugadores; i++){
        if(strcmp((*j)[i].estado, est)==0)
            printf("%s", (*j)[i].nick);
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
                    printf("\nCambio Completado con exito\n\nNick Actual : %s",(*j)[i].nick);
                    printf("\nPulse 1 para volver al menu");
                    scanf("%i",&n);
                    if(n==1) logueo_adm(&pjugador,x,&pconfigurar);
                    break;

                    case 2:
                    system("cls") ;
                    printf("\nNombre Actual : %s\n",(*j)[i].nombre);
                    printf("Introduzca un Nuevo Nombre : ");
                    scanf("%s",(*j)[i].nombre);
                    printf("\nCambio Completado con exito\n\nNombre Actual : %s",(*j)[i].nombre);
                    printf("\nPulse 1 para volver al menu");
                    scanf("%i",&n);
                    if(n==1) logueo_adm(&pjugador,x,&pconfigurar);

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
                            printf("\nPulse 1 para volver al menu");
                            scanf("%i",&n);
                            if(n==1) logueo_adm(&pjugador,x,&pconfigurar);

                        break ;

                       case 2:

                        printf("\n Ahora %s es Jugador\n",(*j)[i].nick);

                        strcpy ((*j)[x].perfil,jgd);
                        printf("\nPulse 1 para volver al menu");
                        scanf("%i",&n);
                        if(n==1) logueo_adm(&pjugador,x,&pconfigurar);
                        break;
                    }
                    break;
                    case 4:
                    system("cls") ;
                      printf("\nContrasena Actual : %s\n",(*j)[i].contrasena);
                      printf("Introduzca una Nueva Contrasena : ");
                      scanf("%s",(*j)[i].contrasena);
                      printf("\nCambio Completado con exito\n\nContrasena Actual : %s",(*j)[i].contrasena);
                      printf("\nPulse 1 para volver al menu");
                      scanf("%i",&n);
                      if(n==1) logueo_adm(&pjugador,x,&pconfigurar);
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
