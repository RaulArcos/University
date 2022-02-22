// Incluimos las librerías necesarias para el funcionamiento del código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef JUGADOR_H
#define JUGADOR_H

// Definimos las estructuras
typedef struct{

	char nick[20],nombre[40],contrasena[20],perfil[4],estado[4];
	int nivel,vida,escudo,cartera,pjugadas,pganadas;

}jugador;

jugador *pjugador;

typedef struct{

    int tamano, distancia, pico,cartera, minimo, paso, mochila, exp, turnos;

}configurar;

configurar *pconfigurar;

typedef struct {

  char nombre_objeto[20], clase_objeto[20],tipo_objeto[20] ;
  int coste_objeto, alcance_objeto, damage ;

} objetos ;

objetos *pobjetos  ;




// Inicializamos los prototipos
void iniciar_estructuras();
void estructuras();
void cargar_jugadores(jugador **);
void cargar_config(configurar **);
void guardar_jugador(jugador **);
void guardar_config(configurar **);
void cargar_objetos(objetos **);

// Inicializamos las variables necesarias para el funcionamiento de los prototipos
int numero_jugadores = 0;
int numero_objetos = 0;
int pin_admin = 1234;
int njugador;

// void iniciar_estructuras()
// {P} Ninguna
// {Q} Carga e inicializa las estructuras para su posterior utilización
void iniciar_estructuras(){

	estructuras(); // Cargamos la estructura de los jugadores

	cargar_config(&pconfigurar); // Cargamos la estructura de configuración

}


// void estructuras_jugador()
// {P} Ninguna
// {Q} Carga e inicializa la estructura jugador, que cargará los datos de jugadores.txt
void estructuras(){

	FILE *jugadores;
	FILE *objetos;

	char temp[200];
	char temp2[200];

	jugadores=fopen("jugadores.txt","r"); // Abrimos el fichero

	if (jugadores==NULL){ // Notificamos si da error de apertura

		printf("No se abierto el fichero");

	}

	while(!feof(jugadores)){ // Leemos hasta fin de fichero

		fgets(temp,200,jugadores); // Contamos el número de jugadores que hay
		numero_jugadores++;
	}

	rewind(jugadores); // Volvemos al inicio del archivo


	cargar_jugadores(&pjugador); // Llamamos a la función para cargar la estructura


	objetos=fopen("objetos.txt","r"); // Abrimos el fichero

	if (objetos==NULL){ // Notificamos si da error de apertura

		printf("No se abierto el fichero");

	}

	while(!feof(objetos)){ // Leemos hasta fin de fichero

		fgets(temp2,200,objetos); // Contamos el número de jugadores que hay
		numero_objetos++;
	}

	rewind(objetos); // Volvemos al inicio del archivo

	cargar_objetos(&pobjetos);
}

// void cargar_jugadores(jugador **j)
// {P} Estructura de jugador (carga los datos de jugadores.txt) inicializada
// {Q} Cargamos los datos del fichero jugadores.txt y los volcamos
void cargar_jugadores(jugador **j){

	*j = (jugador*)malloc(numero_jugadores*sizeof(jugador)); // Hacemos la reserva de memoria dinámica para la estructura

	char auxiliar[200];

	char c;

	FILE *jugadores;

	char *token ;

	const char separador[2] = "/" ;

	int n,x,tokeni;

	jugadores=fopen("jugadores.txt","r++"); // Abrimos el fichero jugadores.txt

	if (jugadores==NULL){ // Si da error de apertura, reportamos el error

		printf("No se abierto el fichero");

	}

	for(n=0;n<numero_jugadores;n++){ // Recorremos la línea de cada jugador

		fgets(auxiliar,200,jugadores); // Obtenemos la cadena completa

		token = strtok( auxiliar, separador); // Separamos cada línea en "tokens", cada cadena separada por '/'

		strcpy ((*j)[n].nick, token); // Cogemos el primer token (nick) y lo añadimos a la estructura

		for(x=0;x<10;x++){ // Recorremos el resto de los tokens, añadiendo cada información al campo de la estructura respectivo

			token = strtok( NULL, separador);
			if(x==0) strcpy ((*j)[n].nombre, token);
			if(x==4) strcpy ((*j)[n].estado, token);
			if(x==8) strcpy ((*j)[n].perfil, token);
			if(x==9) strcpy ((*j)[n].contrasena, token);

		}

	}

	rewind (jugadores); // Volvemos al inicio del fichero

	// Repetimos el proceso anterior, pero ahora obteniendo los datos numéricos
	for(n=0;n<numero_jugadores;n++){ // Recorremos la línea de cada jugador

		fgets(auxiliar,200,jugadores); // Obtenemos la cadena completa

		token = strtok( auxiliar, separador); // Ibtenemos el primer token

		for(x=0;x<11;x++){ // Recorremos el resto de los token, añadiendo cada información a su respectivo campo

		token = strtok( NULL, separador);
		tokeni = atoi(token);
		if(x==1) (*j)[n].nivel = tokeni;
		if(x==2) (*j)[n].vida = tokeni;
		if(x==3) (*j)[n].escudo = tokeni;
		if(x==5) (*j)[n].cartera = tokeni;
		if(x==6) (*j)[n].pjugadas = tokeni;
		if(x==7) (*j)[n].pganadas = tokeni;

		}

	}

	rewind (jugadores); // Volvemos al inicio del fichero
	fclose(jugadores) ; // Cerramos el fichero

}

// void cargar_config(configurar **c)
// {Q} Estructura de configuracion (carga los datos de configuracion.txt) inicializada
// {P} Cargamos los datos del fichero jugadores.txt y los volcamos
void cargar_config(configurar **c){

	*c = (configurar*)malloc(1*sizeof(configurar)); // Hacemos la reserva de memoria dinámica para almacenar la estructura

	char auxiliar[100];
	int n=0;
	FILE *config;
	char *token;
	const char separador[2] = "/" ;
	int x,tokeni;


	config=fopen("configuracion.txt","r++"); // Abrimos el fichero configuracion.txt

	if (config==NULL){ // Reportamos error si nos da error en la apertura

		printf("No se abierto el fichero");

	}

		fgets(auxiliar,100,config); // Recorremos la línea donde está la configuración

		// Separamos cada línea en tokens, separados por '/'
		token = strtok( auxiliar, separador); // Separación para datos tipo cadena
		tokeni = atoi(token); // Separación para datos tipo numérico

		(*c)[n].tamano = tokeni; // Cogemos el primer token y lo añadimos a la estructura

        for(x=0;x<8;x++){ // Obtenemos el resto de tokens, añadiendo cada uno al campo que pertenece

		token = strtok( NULL, separador);
		tokeni = atoi(token);

		if(x==0) (*c)[n].distancia = tokeni;
		if(x==1) (*c)[n].pico = tokeni;
		if(x==2) (*c)[n].cartera = tokeni;
		if(x==3) (*c)[n].minimo = tokeni;
		if(x==4) (*c)[n].paso = tokeni;
		if(x==5) (*c)[n].mochila = tokeni;
        if(x==6) (*c)[n].exp = tokeni;
        if(x==7) (*c)[n].turnos = tokeni;

		}

	fclose(config); // Cerramos el archivo configuracíón

}

// void guardar_jugador(jugador **j)
// {P} Estructura jugador inicializada
// {Q} Deja los datos del fichero jugadores.txt volcados en la estructura
void guardar_jugador(jugador **j){

	int n;
	FILE *auxiliar;
	char aux[20];

	auxiliar = fopen("jugadores.txt","w"); // Abrimos el fichero

	if (auxiliar==NULL){ // Si reporta error de apertura, lo notificamos

		printf("No se abierto el fichero");
	}

	for(n=0; n<numero_jugadores;n++){ // Volcamos de nuevo los datos en el fichero

		fprintf(auxiliar,(*j)[n].nick);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,(*j)[n].nombre);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,"%i",(*j)[n].nivel);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,"%i",(*j)[n].vida);
	  	fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,"%i",(*j)[n].escudo);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,(*j)[n].estado);
    	fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,"%i",(*j)[n].cartera);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,"%i",(*j)[n].pjugadas);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,"%i",(*j)[n].pganadas);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,(*j)[n].perfil);
		fprintf(auxiliar,"%s","/");
		fprintf(auxiliar,(*j)[n].contrasena);
		fprintf(auxiliar,"%s","/");

	if (n<numero_jugadores-1)	// Printeamos el salto de línea para seguir escribiendo los datos del siguiente jugador
			fprintf(auxiliar,"%s","\n");

	}

	rewind(auxiliar); // Volvemos al inicio del fichero

	fclose(auxiliar); // Cerramos el fichero

}

// void guardar_config(configurar **c)
// {P} Estructura configuración inicializada
// {Q} Deja los datos del fichero configuracion.txt volcados en la estructura
void guardar_config(configurar **c){

	int n=0;
	FILE *auxiliar;

	auxiliar=fopen("configuracion.txt", "w"); // Abrimos el fichero

    if (auxiliar==NULL){ // Si da error en la apertura, reportamos dicho error

		printf("Error al abrir\n");

	}

	else {

	// Volcamos los datos de la estructura en el fichero
    fprintf(auxiliar, "%d/%d/%d/%d/%d/%d/%d/%d/%d/",(*c)[n].tamano, (*c)[n].distancia, (*c)[n].pico,(*c)[n].cartera,(*c)[n].minimo, (*c)[n].paso, (*c)[n].mochila, (*c)[n].exp, (*c)[n].turnos);

	rewind(auxiliar); // Volvemos al inicio del fichero

	fclose(auxiliar); // Cerramos el fichero

	}

}


void cargar_objetos (objetos **o) {

	*o = (objetos*)malloc(numero_objetos*sizeof(objetos)); // Hacemos la reserva de memoria dinámica para la estructura


	char ar[4] = "arma";

	char auxiliar[200];

	char c;

	FILE *objetos;

	char *token ;

	const char separador[2] = "/" ;

	int n,x,tokeni;

	objetos=fopen("objetos.txt","r++"); // Abrimos el fichero jugadores.txt

	if (objetos==NULL){ // Si da error de apertura, reportamos el error

		printf("No se abierto el fichero");

	}

	for(n=0;n<numero_objetos;n++){ // Recorremos la línea de cada jugador

		fgets(auxiliar,200,objetos); // Obtenemos la cadena completa

		token = strtok( auxiliar, separador); // Separamos cada línea en "tokens", cada cadena separada por '/'

		strcpy ((*o)[n].nombre_objeto, token); // Cogemos el primer token (nick) y lo añadimos a la estructura

		for(x=0;x<5;x++){ // Recorremos el resto de los tokens, añadiendo cada información al campo de la estructura respectivo

			token = strtok( NULL, separador);
			if(x==0) strcpy ((*o)[n].clase_objeto, token);
			if(x==1) strcpy ((*o)[n].tipo_objeto, token);

		}

	}

	rewind (objetos); // Volvemos al inicio del fichero

	// Repetimos el proceso anterior, pero ahora obteniendo los datos numéricos
	for(n=0;n<numero_objetos;n++){ // Recorremos la línea de cada jugador

		fgets(auxiliar,200,objetos); // Obtenemos la cadena completa

		token = strtok( auxiliar, separador); // Ibtenemos el primer token

		for(x=0;x<6;x++){ // Recorremos el resto de los token, añadiendo cada información a su respectivo campo

		token = strtok( NULL, separador);
		tokeni = atoi(token);
		if(x==1) (*o)[n].coste_objeto = tokeni;
		if(x==2 &&  strcmp (ar,(*o)[n].tipo_objeto) == 0){ (*o)[n].alcance_objeto = tokeni;} else (*o)[n].alcance_objeto = 0;
		if(x==3) (*o)[n].damage = tokeni;

		}

	}

	rewind (objetos); // Volvemos al inicio del fichero
	fclose(objetos) ; // Cerramos el fichero

}




#endif
