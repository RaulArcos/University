#include "main.h"

void login () ;
void menu_logueo () ;
void introducir_contrasena () ;
void registrar () ;
void login_exitoso () ;
int contador_tamano (char *cadena) ;

//Definimos la estructura
typedef struct{
    char nick[20];
    char nombre[20];
    int nivel;
    int vida;
    int escudo;
    char *estado;
    int cartera ;
    int partidas;
    int ganadas;
    char *perfil;
    char contra[30];
} jugador ;

jugador *jugadores;



int main () {

	system("cls") ;

	title() ;

	menu_logueo () ;

	return 0 ;
}

// void menu_logueo ()
// {P} Ninguna
// {Q} Crea y pide valor para la utilizacion del menu para entrar o salir
void menu_logueo ()  {

	int opcion_logueo ;

	do {

		printf("\n\t%c%cPreparado para la guerra?%c\n\n\t[1] Iniciar Sesion\n\n\t[2] Salir del Sistema\n", 254, 168, 254);

		scanf("%i", &opcion_logueo);

	} while ( opcion_logueo != 1 && opcion_logueo != 2 ) ;

		switch (opcion_logueo) {

			case 1:

				system("cls") ;
				login () ;
				break ;

			case 2:

				printf("\nGracias por probar ESINITE\n");
				break ;
		}

}
// void login ()
// {P}
// {Q}
void login () {

	 FILE *jugadores ;
	 char usuario[20] ;
	 char copia_usuario[100] ;
	 char lectura;
	 char *token ;
	 const char separador[2] = "/" ;
	 int opcion ;

	 jugadores = fopen("jugadores.txt", "r++") ;

	 if ( jugadores == NULL ) {

	 	printf("\nError de apertura en el fichero\n");

	 }

	 else {

	 	//Pide el nombre de usuario
	 	printf("\nNombre de Usuario:\t");
	 	scanf("%s", usuario) ;

	 	//Comprueba que el nombre de usuario está en el fichero
		 do {

		 	//Asigna a la cadena auxiliar una linea de 100 caracteres del fichero
	 		fgets (copia_usuario, 100 , jugadores) ;
	 		//Coge lo que haya antes del / de dicha cadena
	 		token = strtok (copia_usuario, separador) ;

	 		//Si el fichero termina o no encuentra concordancia en la comparación
	 	 } while (!feof(jugadores) && strcmp(token, usuario) != 0) ;

	 	//Si ha encontrado usuario pide la contraseña
	 	if ( strcmp(token, usuario ) == 0 ) {

	 		introducir_contrasena () ;

	 			 	}

	 	//Sino ha encontrado usuario pide registro
	 	else {

	 		printf("\nUsuario no encontrado\n");

	 		do {

	 			printf("\n[1] Volver a introducir usuario\n[2] Registrarme\n");
	 			scanf("%i", &opcion);

	 		} while ( opcion != 1 && opcion != 2 ) ;

	 		switch (opcion) {

	 			case 1:

	 				login () ;
	 				break ;

	 			case 2:

	 				registrar () ;
	 				break;

	 		}
	 	}

	 }

	 fclose(jugadores) ;

	 }
// int contador_tamano (char *cadena)
// {P} Cadena de caracteres para contar inicializada
// {Q} Devuelve el tamaño de la cadena introducida por el usuario
int contador_tamano (char *cadena) {

	int tamano_cadena = 0;

	 	for ( int i = 0 ; cadena[i] != '\0' ; i++) {

	 		tamano_cadena++ ;

	 	}

	return tamano_cadena ;
}
//
//
//
void introducir_contrasena ( ) {

			FILE *fp ;
			char contrasena[20] ;
			char *tokenc ;
			const char separador[2] = "/" ;
			int opcion_contrasena ;

			fp = fopen ("jugadores.txt" , "r" ) ;

			if ( fp == NULL )  {

				printf("\nError de apertura en el fichero\n");
				system("PAUSE") ;

			}

			else  {

			//El usuario introduce la contraseña a buscar
	 		printf("\nContrase%ca:\t", 164);
	 		scanf("%s", contrasena) ;

	 		//Recorre la línea del fichero donde encuentra concordancia de usuario
			for ( int x = 10 ; x > 0 ; x-- ){

				//Asigna a token el que esté detrás de la barrra 10, la contraseña que está en última posición
				(tokenc = strtok( NULL, separador ));

			}

			//Comprueba si la contraseña introducida es correcta
			if ( strcmp(tokenc,contrasena) == 0 ) {

 				printf("\nTe has logeado con exito") ;
 				system("cls") ;
 				login_exitoso () ;

			}

			//Si la contraseña no es incorrecta pide registro
			else {

				printf("\nContrase%ca incorrecta\n", 164);

				do {

	 			printf("\n[1] Volver a introducir contrase%ca\n[2] Salir del Sistema\n", 164);
	 			scanf("%i", &opcion_contrasena);

	 			} while ( opcion_contrasena != 1 && opcion_contrasena != 2 ) ;
			}

			//El usuario introduce la contraseña a buscar
	 		printf("\nContrase%ca:\t", 164);
	 		scanf("%s", contrasena) ;

	 		//Recorre la línea del fichero donde encuentra concordancia de usuario
			for ( int x = 10 ; x > 0 ; x-- ){

				//Asigna a token el que esté detrás de la barrra 10, la contraseña que está en última posición
				(tokenc = strtok( NULL, separador ));

			}

			//Comprueba si la contraseña introducida es correcta
			if ( strcmp(contrasena,tokenc) == 0 ) {

 				printf("LOGIN EXITOSO") ;
 				system("PAUSE") ;
 				system("cls") ;
 				login_exitoso () ;


			}

			//Si la contraseña no es incorrecta pide registro
			else {

				printf("\nContrase%ca incorrecta\n", 164);

				do {

	 			printf("\n[1] Volver a introducir contrase%ca\n[2] Salir del Sistema\n", 164);
	 			scanf("%i", &opcion_contrasena) ;

	 			} while ( opcion_contrasena != 1 && opcion_contrasena !=2 ) ;

	 			switch	(opcion_contrasena) {

	 				case 1:

	 					introducir_contrasena () ;
	 					break ;

	 				case 2:

	 					printf("\nGracias por utilizar ESINITE\n");
	 					break;
	 			}

			}

			fclose(fp) ;
	}
}
//
//
//
void registrar () {

	//Abrimos el fichero e inicializamos variables
	FILE *fp;
	int opcion_estado, opcion_registro ;
    jugador e;
    system("cls");
    char c ;

    fp = fopen ("jugadores.txt", "a+");

    if( fp == NULL ){

        printf("\nError de apertura en el fichero\n");
        system("PAUSE");

    }

    else{

    	//Pedimos datos del registro
        printf("\n\t%cQuieres crear una cuenta en ESINITE?\n", 168);
        fflush(stdin);
        printf("\nNombre de Usuario:\t");
        gets(e.nick);
        printf("\nNombre y Apellidos:\t");
        gets(e.nombre);

        //Fijamos los datos por defecto de la partida
        e.nivel = 01 ;
        e.vida = 100 ;
        e.escudo = 00 ;
        fflush(stdin);
        e.estado = "OFF" ;
        e.cartera = 100 ;
        e.partidas = 0 ;
        e.ganadas = 0 ;

        //Le hacemos decidir el tipo de perfil que usará
        printf("\n%cEres ADM o JGD?\n\n\t[1] JGD\n\t[2] ADM\n", 168);
        do {

        	scanf("%i", &opcion_estado);
        	switch (opcion_estado) {

        		case 1:

        			e.perfil = "JGD" ;
        			break ;

        		case 2:

        			e.perfil = "ADM" ;
        			break ;
        	}


        } while ( opcion_estado != 1 && opcion_estado != 2 ) ;

        fflush(stdin);

        //Pedimos la contraseña
        printf("\nContrase%ca:\t", 164);
        gets(e.contra);


        //Escribimos los nuevos datos introducidos en el fichero
        fprintf(fp, "%s/%s/%d/%d/%d/%s/%d/%d/%d/%s/%s%c", e.nick, e.nombre, e.nivel, e.vida, e.escudo, e.estado, e.cartera, e.partidas, e.ganadas, e.perfil, e.contra, '/');
        fprintf(fp, "\n");
        fclose(fp);

        //Todo ha salido correctamente, le damos opcion para continuar
        printf("\nTodos tus datos se han registrado correctamente\n") ;

       	system("PAUSE") ;
        system("cls") ;
        printf("\n%cEstas listo para jugar?\n\n\t[1] Iniciar Sesion\n\n\t[2] Salir de ESINITE\n", 168);

        do {

       	 	scanf( "%i", &opcion_registro );

       	 	switch (opcion_registro) {

       	 		case 1:

       				//Opcion para loguearse y jugar
       	 			system("cls") ;
       	 			login() ;

       	 		case 2:

       	 			//Opcion para salir
       	 			printf("\nGracias por usar ESINITE\n");
       	 			system("PAUSE") ;
       	 			break ;

       	 	}

       	 } while ( opcion_registro != 1 && opcion_registro != 2 ) ;

    }

}
//
//
//
void login_exitoso () {

	FILE *fp ;
	int eleccion ;
	jugador e ;
	fp = fopen ("jugadores.txt", "r++") ;

	if ( fp == NULL ) {

		printf("\nError de apertura en el fichero\n");
		system("PAUSE") ;

	}

	else {

		printf("\n\tBienvenido %s\n\n\t%cQue vas a hacer hoy en ESINITE?\n", e.nombre, 168) ;

		do {

			printf("\n[1] Iniciar una partida\n[2] Ver Perfil\n[3] Tienda\n[4] Salir\n");
			scanf("%i", &eleccion);

		} while ( eleccion <= 0 && eleccion >= 5 ) ;

		switch (eleccion) {

			case 1:

				printf ("\nhacer opccion de partida\n");
				break ;

			case 2:
        printf("\nTu perfil consta de los siguientes datos\n");
				printf("%s/%s/%d/%d/%d/%s/%d/%d/%d/%s/%s%c", e.nick, e.nombre, e.nivel, e.vida, e.escudo, e.estado, e.cartera, e.partidas, e.ganadas, e.perfil, e.contra);
				break ;

			case 3:

				printf ("\nhacer opccion de tienda\n");
				break ;


			case 4:

				printf("\nGracias por utilizar ESINITE\n");
				system("PAUSE") ;
				break ;

		}

	}


	fclose( fp ) ;
}
