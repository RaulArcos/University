// Incluimos las librerías necesarias para la ejecución del código
#include "estructuras.h"
#include "tienda.h"
#include "main.h"


// Declaramos las funciones que vamos a utilizar.
void menu_logueo();
void login(jugador **);
void introducir_contrasena(jugador **,int);
void logueo_jugador(jugador **, int, configurar **);
void registar_usuario(jugador **);
void ver_perfil(jugador **,int);
void opciones_adm(jugador **, int, configurar**);
void configuracion_partida(configurar **c, int x) ;
void logueo_adm(jugador **j, int x, configurar **c) ;
void inicio_juego(jugador **j, int x, configurar **c) ;
void espera(jugador **j, int x, configurar **c) ;
void cambiar_datos(jugador**,int);

// void menu_logueo()
// {P} Ninguna
// {Q} Muestra el menu logueo y lleva al jugador hacia alguna opción
void menu_logueo(){

  system("cls"); // Limpiamos pantalla

  title(); // Llamamos a la función que muestra el título

  int opcion_logueo ;
  int opcion_perfil;

	do { // Repetimos hasta introducir una opción válida

    // Mostramos las opciones del menu
		printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Iniciar Sesion\n\n\t[2] Salir del  Sistema / Guardar Partida\n", 254, 168, 254);
		scanf("%i", &opcion_logueo);

	} while ( opcion_logueo<1 && opcion_logueo>2 ) ;


		switch (opcion_logueo) { // Ejecutamos la opción dependiendo del caso

			case 1:

				system("cls") ;
				login(&pjugador); // Iniciamos la función de login gracias al puntero a la estrucutra del jugador
				break ;

      case 2:

        guardar_jugador(&pjugador); // Inicializamos la funcion de guardar_jugador gracias al puntero a la estructura del jugador
        printf("\nGracias por probar ESINITE\n");
        break ;

		}
}

// void login(jugador **j)
// {P} Estructura jugador inicializada
// {Q} Realiza el logueo del jugador, que debe introducir usuario y contraseña
void login(jugador **j){

  system("cls");
  char opcion_logueo;
  char usuario[20];
  int x;

  printf("\nIntroduce tu Usuario : "); // Pedimos un usuario
  scanf("%s",usuario);

  for(x=0;x<numero_jugadores+1;x++){ // Recorremos los jugadores registrados en la estructura

    if (strcmp((*j)[x].nick, usuario ) == 0){ // Si encuentra el usuario, llama a la función para introducir contraseñas

      introducir_contrasena(&pjugador,x);
      break;

    }

  }

  if(x>numero_jugadores){ // Si no se encuentra el usuario en el sistema se notifica

    printf("\nUsuario no encontrado\n");

      do { // Mostramos las opción tras no haber un usuario como el introducido

          printf("\n[1] Reintentar\n[2] Registar Un Nuevo Usuario\n[3] Volver al Menu principal\n");

          scanf("%i", &opcion_logueo);

        } while ( opcion_logueo<1 && opcion_logueo>3 ) ; // Repetimos hasta introducir una opción válida

      switch (opcion_logueo){ // Ejecutamos las opciones

          case 1:

                login(&pjugador); // Llamamos a la función para volver a loguearse
                break;

          case 2:

                registar_usuario(&pjugador); // Llamamos a la función para registrar un jugador
                break;

          case 3:

                system("cls") ;
                menu_logueo();
                break;
      }
  }

}

// void introducir_contrasena(jugador **j,int x)
// {P} Estructura jugador inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Logue al usuario de manera satisfactoria
void introducir_contrasena(jugador **j,int x){

  char contra[20];
  char adm[4] = "ADM";
  char opcion_contrasena;

  printf("\n Contrasena : ");

  scanf("%s",contra);

  if(strcmp((*j)[x].contrasena, contra) == 0)  { // Comparamos las contraseñas

        if(strcmp((*j)[x].perfil, adm)==0){ // Miramos si la contraseña corresponde con un perfil administrador

            logueo_adm(&pjugador,x,&pconfigurar); // Llamamos a la función de logueo satisfactorio

        }

        else {

          logueo_jugador(&pjugador,x, &pconfigurar); // Llamamos a la función para loguear de nuevo

        }

   }

   else { // Si la contraseña es incorrecta

     printf("\nContrase%ca incorrecta\n", 164);

     do { // Repetimos hasta introducir una opción válida

     printf("\n[1] Volver a introducir contrase%ca\n[2] Introducir un Nuevo Usuario\n[3] Salir del Sistema\n", 164);
     scanf("%i", &opcion_contrasena) ;

     } while ( opcion_contrasena != 1 && opcion_contrasena !=2 ) ;

     switch	(opcion_contrasena) { // Ejecutamos las opciones

       case 1: // Opción volver a introducir contraseña

         introducir_contrasena (&pjugador,x) ; // Llamamos a la función para volver a introducir la contraseña
         break ;

        case 2: // Opción para volver a loguear el usuaroi

           system("cls") ;
           login(&pjugador); // Llama a la función para hacer el logueo desde el principio
           break ;

       case 3: // Opción salir del sistema

         printf("\nGracias por utilizar ESINITE\n");
         break;
     }

   }

}

// void logueo_jugador(jugador **j,int x, configurar **c)
// {P} Estructura de jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Muestra el menu que ve el jugador una vez se ha logueado con éxito
void logueo_jugador(jugador **j,int x, configurar **c){

    njugador = x;

    system("cls") ; // Limpiamos pantalla
    title(); // Llamamos a la función para mostrar el título
    int opcion_logueo ;

  	do { // Enseñamos las opciones que tendrá el jugador una vez logueado

      printf("\n\tBienvenido %s \n",(*j)[x].nick);
    	printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Cambiar Usuario\n\n\t[2] Iniciar/Continuar un Juego\n\n\t[3] Comprar Objeto\n\n\t[4] Ver Perfil\n\n\t[5] Salir del Sistema / Guardar Partida\n", 254, 168, 254);
  		scanf("%i", &opcion_logueo);

  	} while ( opcion_logueo<1 && opcion_logueo>5 ) ; // Repetimos hasta introducir una opción válida

  	switch (opcion_logueo) {

        case 1: // Opción para loguear otro usuario

            login(&pjugador);
            break ;

        case 2: // Opción para iniciar una partida

            system("cls");
            inicio_juego(&pjugador, x, &pconfigurar);
            break ;

        case 3: // Opción para comprar un objeto

            system("cls") ;
            menu_tienda(&pjugador,&pconfigurar,&pobjetos,x);
            break ;

        case 4: // Opción para ver el perfil de un jugador

            system("cls") ;
            ver_perfil(&pjugador,x);
            break ;

        case 5: // Opción para guardar un jugador

            guardar_jugador(&pjugador);
            printf("\nGracias por probar ESINITE\n");
            break ;

  		}

}

// void logueo_adm(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializada
// {Q} Da al administradror las opciones una vez logueado
void logueo_adm(jugador **j, int x, configurar **c){

    njugador = x;

    system("cls") ; // Limpiamos pantalla

    title(); // Llamamos a la función que mostrará el título

    int opcion_logueo,n ;

  	do { // Enseñamos las opciones en pantalla para el administrador

      printf("\n\tBienvenido ADMINISTRADOR %s \n",(*j)[x].nick);

      printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Cambiar Usuario\n\n\t[2] Iniciar/Continuar un Juego\n\n\t[3] Comprar Objeto\n\n\t[4] Ver Perfil\n\n\t[5] Opciones Administrador\n\n\t[6] Guardar Datos\n\n\t[7] Salir del  Sistema\n", 254, 168, 254);

  		scanf("%i", &opcion_logueo);

  	} while ( opcion_logueo<1 && opcion_logueo>7 ) ; // Hasta que se introduzca una opción válida

  	switch (opcion_logueo) { // Ejecutamos las opciones ofrecidas

        case 1: // Opción para loguearse de nuevo

            login(&pjugador);
            break ;

        case 2: // Opción para iniciar una partida

            system("cls");
            inicio_juego(&pjugador, x, &pconfigurar);
            break ;

        case 3: // Opción para comprar un objeto

            system("cls");
            menu_tienda(&pjugador,&pconfigurar,&pobjetos,x);
            break ;

        case 4: // Opción para ver el perfil propio

            system("cls");
            ver_perfil(&pjugador,x);
            break ;

        case 5: // Opción para acceder a las opciones del administrador

            system("cls");
            opciones_adm(&pjugador, x, &pconfigurar);
            break;

        case 6: // Opción para guardar jugador

        guardar_jugador(&pjugador);
        printf("\nDatos Guardados con Exito");
        printf("\nPulse 1 para volver al menu");
        scanf("%i",&n);
        if(n==1) logueo_adm(&pjugador,x,&pconfigurar);
        break ;

        case 7: // Opción para Salir del sistema

        printf("Gracias por usar ESINITE");
        break;
  		}

}

// void registar_usuario(jugador **j)
// {P} Estructura de jugadores cargada e inicializada
// {Q} Registra un nuevo usuario en el sistema
void registar_usuario(jugador **j) {

  system("cls") ; // Limpiamos pantalla

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

    printf("\nIntroduce un Nick Nuevo : "); // Pedimos el nick a registrar

      scanf("%s",aux);

      for(i=0;i<numero_jugadores;i++){

        if (strcmp((*j)[i].nick, aux ) == 0){ // Verificamos que no exista

          printf("\nEl Usuario Introducido Ya Existe\n");

          do { // Otorgamos las opciones al nuevo usuario

            printf("\n\n[1] Iniciar Sesion\n[2] Registrar Otro Usuario\n");

            scanf("%i", &opcion_registro);

          } while ( opcion_registro != 1 && opcion_registro !=2) ; // Hasta introducir una opción válida

          switch (opcion_registro) {

              case 1: // Opción para acceder al login

                login(&pjugador);
                break ;

              case 2: // Opción para registrar un nuevo usuario

              registar_usuario(&pjugador);
              break;

          }

          break;

        }

      }

    if(i>numero_jugadores-1){  // Verificamos que ya hayamos introducido el usuario

      strcpy ((*j)[x].nick,aux); // Pedimos el nombre para añadir a la estructura

      printf("\nIntroduce tu Nombre : ");

      scanf("%s",(*j)[x].nombre);

      printf("\nIntroduce tu Nueva Contrasena : "); // Pedimos una contraseña

        scanf("%s",(*j)[x].contrasena);


      do { // Preguntamos para saber si es ADM o JGD

        printf("\nEres ADMINISTRADOR o JUGADOR : \n[1] ADMINISTRADOR\n[2] JUGADOR\n");

        scanf("%i", &opcion_administrador) ;

    } while ( opcion_administrador != 1 && opcion_administrador !=2 ) ; // Hasta introducir una opción válida

      switch	(opcion_administrador) { // Ejecutamos las opciones ofrecidas

        case 1: // Opción si ha elegido que es ADM

          printf("\nIntroduce el PIN de ADMINISTRADOR : ");

          do{ // Pedimos el PIN de ADM

            scanf("%i",&pin);

            if(pin == pin_admin) { // Verificamos que sea correcto

              printf("\n Ahora eres ADMINISTRADOR\n");

              strcpy ((*j)[x].perfil,adm);

            } else (printf("\nPIN INCORRECTO, Introduce el PIN de Nuevo\n"));

          }while (pin != 1234); // Hasta que se haya introducido un pin válido

          break ;

         case 2: // Opción si lo introducido es un JGD

          printf("\n Ahora eres JUGADOR\n");
          strcpy ((*j)[x].perfil,jgd);
          break;
      }


      // Inicializamos nivel, vida, escudo, cartera y estadísticas de partidas a lo predefinido

      (*j)[x].nivel = 01;

      (*j)[x].vida = 100;

      (*j)[x].escudo = 0;

      (*j)[x].cartera= 100;

      (*j)[x].pjugadas = 0;

      (*j)[x].pganadas = 0;


      strcpy ((*j)[x].estado,estado_offline); // Fijamos el estado a OFFLINE como predefinido



    }

    printf("\nUsuario Registrado con Exito, Pulsa 1 para ir al menu principal\n"); // Informamos de que se ha registrado con éxito

    scanf("%i",&n);

    if (n == 1 ) menu_logueo();

}

// void ver_perfil(jugador **j,int x)
// {P} Estructura de jugador cargada e inicializda, posición en la estructura inicializada
// {Q} Enseña el respectivo perfil al jugador
void ver_perfil(jugador **j,int x){

  char adm[4] = "ADM";
  char jgd[4] = "JGD";

int opcion_perfil2;

// Mostramos el perfil del jugador
printf("Nick : %s\nNombre : %s\nNivel : %i\nCartera : %i Monedas\nPartidas Jugadas : %i Partidas\nPartidas Ganadas : %i Partidas\n",(*j)[x].nick,(*j)[x].nombre,(*j)[x].nivel,(*j)[x].cartera,(*j)[x].pjugadas,(*j)[x].pganadas);


  do { // Damos pie a la opción para volver al menu principal

  printf("\n\n[1]volver al Menu Principal\n");

  scanf("%i", &opcion_perfil2);

  } while ( opcion_perfil2 != 1 ) ; // Hasta introducir una opción válida
  if(opcion_perfil2==1){
    if(strcmp((*j)[x].perfil, adm)==0){ //Diferencia entre administrador y juagdor para volver a su menu
      logueo_adm(&pjugador,x,&pconfigurar);
  } else logueo_jugador(&pjugador ,x, &pconfigurar);}
}

// void opciones_adm(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Otorga al jugador ADM las respectivas opciones
void opciones_adm(jugador **j, int x, configurar **c){
    system("cls");
    int op;

    do{ // Pedimos valor para acceder a una opción

        printf("\n\t%cEDITOR DEL JUEGO. %cQue ajustes deseas realizar?%c\n\n\t[1] Iniciar Partida\n\n\t[2] Cambiar configuracion Partida\n\n\t[3] Datos Jugadores\n\n\t[4]Salir al Menu Principal\n", 254, 168, 254);
        scanf("%i", &op);

        switch(op){ // Ejecutmaos dichas opciones
            case 1: printf("Iniciar Partida"); break; // Opción iniciar partida
            case 2: configuracion_partida(&pconfigurar, x); break; // Opción para configurar
            case 3: cambiar_datos(&pjugador,x); break; // Opción para ver los datos de jugadores
            case 4: logueo_adm(&pjugador, x, &pconfigurar); break; // Opción para loguear admin
            default: system("cls"); printf("Opcion Incorrecta\n"); // opción incorrecta
        }
    }while(op<1 || op>4); // Hasta introducir una opción válida

}

// void configuracion_partida(configurar **c, int x)
// {P} Estructura configuración inicializada y cargada
// {Q} Accede a la opción de configuración para el ADM
void configuracion_partida(configurar **c, int x){

  system("cls");
  int n=0;
  int op;

    do{ // Mostramos las opciones para los ajustes a realizar

        printf("\n\t%c%cQue ajustes deseas realizar?%c\n\n\t", 254, 168,254);
        printf("[1] Tama%co mapa\n\n\t[2] Distancia maxima para poder recoger un objeto\n\n\t[3] Distancia Maxima para golpear con el pico\n\n\t[4] Monedas por defecto a cada jugador\n\n\t[5] Jugadores Minimos para Jugar\n\n\t[6] Valor del paso del jugador\n\n\t[7] Tama%co Mochila\n\n\t[8] Minimo de partidas ganadas para subir nivel\n\n\t[9] Numero maximo de acciones de un jugador en un turno\n\n\t[10] Volver Atras\n", 164, 164);
        scanf("%i", &op);

        switch(op){ // Ejecutamos dichas opciones

            case 1: // Opción tamaño
                    printf("Valor actual: %d\n", (*c)[n].tamano);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].tamano);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 2: // Opción distancia
                    printf("Valor actual: %d\n", (*c)[n].distancia);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].distancia);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 3: // Opción del pico

                    printf("Valor actual: %d\n", (*c)[n].pico);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].pico);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 4:  // Opción cartera

                    printf("Valor actual: %d\n", (*c)[n].cartera);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].cartera);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 5: // Opción valor mínimo

                    printf("Valor actual: %d\n", (*c)[n].minimo);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].minimo);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;

            case 6: // Opción valor del paso
                    printf("Valor actual: %d\n", (*c)[n].paso);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].paso);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;

            case 7: // Opción mochila
                    printf("Valor actual: %d\n", (*c)[n].mochila);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].mochila);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;

            case 8: // Opción experiencia
                    printf("Valor actual: %d\n", (*c)[n].exp);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].exp);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
                    break;
            case 9: // Opción número de turnos
                    printf("Valor actual: %d\n", (*c)[n].turnos);
                    printf("Valor nuevo: "); scanf("%d", &(*c)[n].turnos);
                    printf("VALOR CAMBIADO\n"); system("PAUSE");configuracion_partida(&pconfigurar, x);
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

// void inicio_juego(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Inicializamos la opción para que el jugador pueda iniciar una partida
void inicio_juego(jugador **j, int x, configurar **c){

  int op;
  char adm[4] = "ADM";


    do{ // Mostramos las opciones sobre jugar una partida

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
// void espera(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Inicializa el tiempo de espera para empezar la partida
void espera(jugador **j, int x, configurar **c){

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

    if(jesp<(*c)[0].minimo){ // Vemos si el nº de jugadores es suficiente para iniciar

        printf("\nNo hay jugadores suficientes para comenzar todavia una partida\n");
        printf("\nSU ESTADO ACTUAL ES: EN ESPERA\n\n"); // Notificamos del estado actual
        strcpy((*j)[x].estado, est);

    }

    else { // Vemos si el nº de jugadores es suficiente

        printf("\nHay Jugadores suficientes para comenzar una partida\n"); // Vemos qe podemos comenzar
        printf("\nSU ESTADO ACTUAL ES: EN ESPERA\n\n");
        strcpy((*j)[x].estado, est);
        if(strcmp((*j)[x].perfil, adm)==0) printf("Si deseas iniciar una partida, pulse [1]\n"); // Si es suficiente el ADM puede empezar, y el JGD puede iniciar
            else printf("SOLO LOS ADMINISTRADORES PUEDEN INICIAR LA PARTIDA\n\n");
    }

    system("PAUSE"); // Comprobamos si el perfil es JGD o ADM
    if(strcmp((*j)[x].perfil, adm)==0) logueo_adm(&pjugador, x, &pconfigurar);
    else logueo_jugador(&pjugador, x, &pconfigurar);
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
