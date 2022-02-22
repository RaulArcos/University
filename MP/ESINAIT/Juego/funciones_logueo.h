// Incluimos las librerías necesarias para la ejecución del código
#include "estructuras.h"
#include "main.h"
#include "configuracion.h"
#include "Inicializacion.h"
#include "funciones_tienda.h"
#include "tormenta.h"

// Declaramos las funciones que vamos a utilizar.
void menu_logueo();
void login(jugador **);
void introducir_contrasena(jugador **,int);
void registar_usuario(jugador **);
void ver_perfil(jugador **,int);
void opciones_adm(jugador **, int, configurar**);
void menu_tienda(jugador **, configurar **, objetos **, mochila **,int);


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
    char on[4]="ON";
    char off[4]="OFF";
    int opcion_logueo ;

    system("cls") ; // Limpiamos pantalla
    title(); // Llamamos a la función para mostrar el título

  	do { // Enseñamos las opciones que tendrá el jugador una vez logueado

        if(strcmp((*j)[x].estado, "OFF")==0) strcpy((*j)[x].estado, on);
            printf("\n\tBienvenido %s \n",(*j)[x].nick);
            printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Cambiar Usuario\n\n\t[2] Iniciar/Continuar un Juego\n\n\t[3] Comprar Objeto\n\n\t[4] Ver Perfil\n\n\t[5] Salir del Sistema / Guardar Partida\n", 254, 168, 254);
            scanf("%i", &opcion_logueo);

  	} while ( opcion_logueo<1 && opcion_logueo>5 ) ; // Repetimos hasta introducir una opción válida

  	switch (opcion_logueo) {

        case 1: // Opción para loguear otro usuario
            if(strcmp((*j)[x].estado, "ON")==0) strcpy((*j)[x].estado, off);
            login(&pjugador);
            system("PAUSE");
            break ;

        case 2: // Opción para iniciar una partida
            system("cls");
            inicio_juego(&pjugador, x, &pconfigurar);
            break ;

        case 3: // Opción para comprar un objeto

            system("cls") ;
            menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
            break ;

        case 4: // Opción para ver el perfil de un jugador

            system("cls") ;
            ver_perfil(&pjugador,x);
            break ;

        case 5: // Opción para guardar un jugador
            if(strcmp((*j)[x].estado, "ON")==0) strcpy((*j)[x].estado, off);
            guardar_jugador(&pjugador);
            guardar_config(&pconfigurar);
            guardar_mapa(&pmapa);
            printf("\nGracias por probar ESINITE\n");
            exit(0);

  		}

}

// void logueo_adm(jugador **j, int x, configurar **c)
// {P} Estructura jugador y configuración inicializada y cargada, posición del jugador en la estructura inicializada
// {Q} Da al administradror las opciones una vez logueado
void logueo_adm(jugador **j, int x, configurar **c){
    char on[4]="ON";
    char off[4]="OFF";
    int opcion_logueo,n ;

    system("cls") ; // Limpiamos pantalla
    title(); // Llamamos a la función que mostrará el título

  	do { // Enseñamos las opciones en pantalla para el administrador
       if(strcmp((*j)[x].estado, "OFF")==0) strcpy((*j)[x].estado, on);
            printf("\n\tBienvenido ADMINISTRADOR %s \n",(*j)[x].nick);
            printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Cambiar Usuario\n\n\t[2] Iniciar/Continuar un Juego\n\n\t[3] Comprar Objeto\n\n\t[4] Ver Perfil\n\n\t[5] Opciones Administrador\n\n\t[6] Guardar Datos\n\n\t[7] Salir del  Sistema\n", 254, 168, 254);
            scanf("%i", &opcion_logueo);

  	} while ( opcion_logueo<1 && opcion_logueo>7 ) ; // Hasta que se introduzca una opción válida

  	switch (opcion_logueo) { // Ejecutamos las opciones ofrecidas

        case 1: // Opción para loguearse de nuevo
            if(strcmp((*j)[x].estado, "ON")==0) strcpy((*j)[x].estado, off);
            login(&pjugador);
            break ;

        case 2: // Opción para iniciar una partida
            system("cls");
            inicio_juego(&pjugador, x, &pconfigurar);
            break ;

        case 3: // Opción para comprar un objeto
            system("cls");
            menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
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
            guardar_config(&pconfigurar);
            printf("\nDatos Guardados con Exito\n");
            system("Pause");
            logueo_adm(&pjugador,x,&pconfigurar);
        break ;

        case 7: // Opción para Salir del sistema
            if(strcmp((*j)[x].estado, "ON")==0) strcpy((*j)[x].estado, off);
            guardar_config(&pconfigurar);
            guardar_jugador(&pjugador);
            guardar_mapa(&pmapa);
            printf("Gracias por usar ESINITE");
            exit(0);
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

