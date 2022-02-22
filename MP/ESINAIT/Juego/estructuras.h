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

typedef struct {

	char portador [20] ;
	char identificador_arma [20] ;
	int unidades ;

} mochila ;

mochila *pmochila ;

typedef struct {
	char tipo[15], nick[20];
	int posx, posy;
}mapita;

mapita *pmapa;

typedef struct{
    int posx, posy, diametro,tiempo;
}tormenta;
tormenta *ptormenta;


// Inicializamos los prototipos
void iniciar_estructuras();
void estructuras_jugador();
void cargar_jugadores(jugador **);
void cargar_config(configurar **);
void cargar_mochila ( mochila ** ) ;
void cargar_objetos( objetos **);
void cargar_mapa(mapita **);
void guardar_jugador(jugador **);
void guardar_config(configurar **);
void guardar_mochila ( mochila ** );
void guardar_mapa(mapita **);
void cargar_storm(tormenta **);

// Inicializamos las variables necesarias para el funcionamiento de los prototipos
int numero_jugadores = 0;
int pin_admin = 1234;
int numero_objetos = 0;
int lineas_mochila = 0;

// void iniciar_estructuras()
// {P} Ninguna
// {Q} Carga e inicializa las estructuras para su posterior utilización
void iniciar_estructuras(){

	estructuras_jugador();// Cargamos la estructura de los jugadores

	cargar_config(&pconfigurar); // Cargamos la estructura de configuración
	cargar_jugadores(&pjugador);
	cargar_objetos(&pobjetos);
	cargar_mochila (&pmochila) ;
	cargar_mapa(&pmapa);
	cargar_storm(&ptormenta);

}
//
//
//
void cargar_mochila ( mochila **m ) {

	FILE *mochilas ;
	char temp[200] , auxiliar [200];
	char *token ;
	const char separador[2] = "/" ;
	int tokeni , x , n ;


	*m = (mochila*)malloc(lineas_mochila*sizeof(mochila));

	mochilas = fopen ("mochila.txt" , "r+" ) ; // Abrimos el fichero

	if ( mochilas == NULL ) {

		printf("Error de apertura en el fichero");

	}

	else {

	 // Hacemos la reserva de memoria dinámica para la estructura
printf("%i",lineas_mochila);

		for (  n = 0 ; n < lineas_mochila ; n++ ) {

			fgets ( auxiliar , 200 , mochilas ) ;

			token = strtok ( auxiliar , separador ) ;

			strcpy ((*m)[n].portador , token) ;

			for (  x = 0 ; x < 3 ; x++ ) {

				token = strtok ( NULL , separador ) ;

				if (   x == 0 ) strcpy ((*m)[n].identificador_arma , token) ;

			}
			printf("%s y %s\n",(*m)[n].identificador_arma,(*m)[n].portador);
		}

			rewind ( mochilas ) ;

			for (  n = 0 ; n < lineas_mochila ; n++ ) {

				fgets ( auxiliar , 200 , mochilas ) ;

				token = strtok ( auxiliar , separador ) ;

				for (  x = 0 ; x < 3 ; x++ ) {

					token = strtok (NULL , separador) ;
					tokeni = atoi(token) ;

					if (  x == 1 ) (*m)[n].unidades = tokeni ;

				}
			}

			rewind (mochilas) ;
			fclose (mochilas) ;
		}

}
//
//
//
void guardar_mochila ( mochila **m ) {

	int n = 0 ;
	FILE *mochila ;

	mochila = fopen("mochila.txt" , "w" ) ;

	if ( mochila == NULL ) {

		printf("Error al abrir el archivo");

	}

	else {

for(n =0;n<lineas_mochila;n++){

		fprintf (mochila , "%s/%s/%d/", (*m)[n].portador , (*m)[n].identificador_arma , (*m)[n].unidades) ;

		if (n<lineas_mochila-1)	// Printeamos el salto de línea para seguir escribiendo los datos del siguiente jugador
				fprintf(mochila,"%s","\n");

}
rewind (mochila) ;
fclose (mochila) ;
	}

}

// void estructuras_jugador()
// {P} Ninguna
// {Q} Carga e inicializa la estructura jugador, que cargará los datos de jugadores.txt
void estructuras_jugador(){

	FILE *mochila ;

	FILE *objetos;
        
	FILE *jugadores;

	char temp[200];

	jugadores=fopen("jugadores.txt","r"); // Abrimos el fichero

	if (jugadores==NULL){ // Notificamos si da error de apertura

		printf("No se abierto el fichero");

	}

	while(!feof(jugadores)){ // Leemos hasta fin de fichero

		fgets(temp,200,jugadores); // Contamos el número de jugadores que hay
		numero_jugadores++;
	}

	rewind(jugadores); // Volvemos al inicio del archivo

	objetos=fopen("objetos.txt","r"); // Abrimos el fichero

	if (objetos==NULL){ // Notificamos si da error de apertura

		printf("No se abierto el fichero");

	}

	while(!feof(objetos)){ // Leemos hasta fin de fichero

		fgets(temp,200,objetos); // Contamos el número de jugadores que hay
//		numero_objetos++;
	}
numero_objetos = 7;
	rewind(objetos); // Volvemos al inicio del archivo

	mochila = fopen ("mochila.txt" , "r" ) ; // Abrimos el fichero

	if ( mochila == NULL ) {

		printf("Error de apertura en el fichero");

	}

			while(!feof(mochila)){ // Leemos hasta fin de fichero

			fgets(temp,200,mochila); // Contamos el número de líneas que hay

printf("%s",temp);
			lineas_mochila++;

			}

			rewind (mochila) ;
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

	objetos=fopen("objetos.txt","r"); // Abrimos el fichero jugadores.txt

	if (objetos==NULL){ // Si da error de apertura, reportamos el error

		printf("No se abierto el fichero");

	}

	for(n=0;n<numero_objetos;n++){ // Recorremos la línea de cada jugador
printf("numero de n : %i\n",n);
		fgets(auxiliar,200,objetos); // Obtenemos la cadena completa

		token = strtok( auxiliar, separador); // Separamos cada línea en "tokens", cada cadena separada por '/'

		strcpy ((*o)[n].nombre_objeto, token); // Cogemos el primer token (nick) y lo añadimos a la estructura
printf("\nNombre Objeto : %s\n",(*o)[n].nombre_objeto);
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
		if(x==2){ (*o)[n].coste_objeto = tokeni;printf("\nCoste Objeto : %i\n",(*o)[n].coste_objeto);}

		if(x==3 &&  strcmp (ar,(*o)[n].tipo_objeto) == 0){ (*o)[n].alcance_objeto = tokeni;} else (*o)[n].alcance_objeto = 0;

		if(x==4) (*o)[n].damage = tokeni;


		}

	}

	rewind (objetos); // Volvemos al inicio del fichero
	fclose(objetos) ; // Cerramos el fichero

}

void cargar_mapa(mapita **mp){
int linea_mapa=0;
FILE *mapa;
char temp[200],auxiliar[200];
char *token;
const char separador[2]= "/";
int n,x,tokeni;

mapa=fopen("mapa.txt", "r");

if (mapa==NULL){ // Notificamos si da error de apertura
		printf("No se abierto el fichero");
	}

	while(!feof(mapa)){ // Leemos hasta fin de fichero

		fgets(temp,200,mapa); // Contamos el número de lineas que hay
		linea_mapa++;
	}

	rewind(mapa); // Volvemos al inicio del archivo

	(*mp)=(mapita*)malloc(linea_mapa*sizeof(mapita));

    for(n=0; n<linea_mapa; n++){

        fgets(auxiliar,200,mapa);
        token = strtok(auxiliar, separador);
        strcpy((*mp)[n].tipo, token);

        for(x=0; x<3; x++){
            token = strtok(NULL,separador);
            if(x==0) strcpy((*mp)[n].nick, token);

        }
    }
    rewind(mapa);

    for(n=0; n<linea_mapa; n++){

        fgets(auxiliar, 200, mapa);
        token = strtok(auxiliar, separador);

        for(x=0; x<4; x++){

            token = strtok(NULL, separador);
            tokeni = atoi(token);
            if(x==1) (*mp)[n].posx = tokeni;
            if(x==2) (*mp)[n].posy = tokeni;

        }
    }

    rewind(mapa);
    fclose(mapa);

}

void guardar_mapa(mapita **mp){
	int n;
	char aux[200];
	int linea_mapa=0;
	FILE *mapa;

	    mapa=fopen("mapa.txt", "r");

	    while(!feof(mapa)){
	        fgets(aux,200,mapa);
	        linea_mapa++;
	    }

	    rewind(mapa);
	    fclose(mapa);

	    mapa=fopen("mapa.txt", "w");

	    for(n=0; n<linea_mapa; n++){
	        fprintf(mapa, "%s/%s/%d/%d/", (*mp)[n].tipo, (*mp)[n].nick, (*mp)[n].posx, (*mp)[n].posy);
	        if (n<linea_mapa-1)	// Printeamos el salto de línea para seguir escribiendo los datos del siguiente jugador
				fprintf(mapa,"%s","\n");

	    }
	rewind(mapa);
	fclose(mapa);

	}

void cargar_storm(tormenta **t){
int lineas=0, n, x, tokeni;
const char separador[2] = "/";
FILE *storm;
char aux[200], aux2[200];
char *token;

    storm=fopen("tormenta.txt", "r");

    if(!storm){
        printf("Error en la apertura del fichero.");
    }

    while(!feof(storm)){
        fgets(aux,200,storm);
        lineas++;
    }
    rewind(storm);

    (*t)=(tormenta*)malloc(lineas*sizeof(tormenta));

    for(n=0; n<lineas; n++){
        fgets(aux2,200,storm);
        token = strtok(aux2, separador);
        tokeni = atoi(token);
        (*t)[n].posx = tokeni;
        for(x=0; x<4; x++){
            token = strtok(NULL, separador);
            tokeni = atoi(token);
            if(x==0) (*t)[n].posy = tokeni;
            if(x==1) (*t)[n].diametro = tokeni;
            if(x==2) (*t)[n].tiempo = tokeni;
        }
    }
    rewind(storm);
    fclose(storm);

}


#endif
