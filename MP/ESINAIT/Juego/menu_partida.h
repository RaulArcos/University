// Cabecera con las funciones necesarias para el menú partida
#include "estructuras.h"
#include <math.h>
#define jug_max 5


void mostrar_menu ( jugador **, int, mapita **, int, configurar **, tormenta **t) ; // Inicializamos los prototipos
void restar_turnos ( int * ) ;
void comprobar_turno () ;
int movimiento_jugador(int *, int *, mapita **, int, configurar **, int);
int buscar_estructura(jugador **, int , mapita **);
void logueo_jugador(jugador **, int , configurar **);
void formula_hipotenusa (int , int , int , int , int *);
void comparativa (int, int );
void usar_mochila(jugador**,objetos**,mochila**,int);


// void mostrar_menu ()
// {P} Estructura de jugador inicializada y cargada, posición del jugador en la estructura inicializado
// {Q} Mostrará al usuario el menú con las opciones dentro de la partida
void mostrar_menu (jugador **j , int x, mapita **mp, int vivos, configurar **c, tormenta **t) {

	int opcion , turnos=(*c)[0].turnos, i=0, p, posj;
    printf("%d", vivos);

    do{
	do { // Repetimos el proceso
        p=buscar_estructura(&pjugador, i, &pmapa);
        system("cls"); // Limpiamos pantalla
		// Notificamos de las posibles opciones
		printf ("\n%c Estas en Partida %s %c\n%cQue vas a hacer?Te quedan %d turnos\n[1] Ver/Usar Mochila\n[2] Usar Objeto/Disparar\n[3] Mover al jugador\n[4] Ver objetos cercanos\n[5] Ver oponentes cercanos\n[6] Comprobar tu posicion actual\n[7] Ver posicion y limites de la Tormenta\n[8] Finalizar turno\n[9] Volver al menu principal\n", 175 , (*mp)[i].nick , 174 , 168, turnos);
		scanf ( "%i" , &opcion ) ; // Pedimos la opción

        switch ( opcion ) {

			case 1:

				printf ("Ver/Usar Mochila");
				ver_mochila(&pjugador,&pobjetos,&pmochila,x);
				restar_turnos ( &turnos ) ;
				break ;

			case 2:

				printf ("Ver/Usar Mochila");
				restar_turnos ( &turnos ) ;
				break ;

			case 3:

                turnos = movimiento_jugador(&(*mp)[i].posx, &(*mp)[i].posy, &pmapa, i, &pconfigurar, turnos);
                formula_hipotenusa((*t)[0].posx, (*t)[0].posy, (*mp)[i].posx, (*mp)[i].posy, &posj);
                comparativa(posj, (*t)[0].diametro);
                system("PAUSE");
                if(turnos==0){turnos=(*c)[0].turnos; i++;}
				break ;

			case 4:

				printf ("Ver/Usar Mochila");
				break ;

			case 5:

				printf ("Ver/Usar Mochila");
				break ;

			case 6:

				printf("Tu posicion actual es: %d, %d", (*mp)[i].posx, (*mp)[i].posy);
				system("PAUSE");
				break;

			case 7:
                system("cls");
				printf("La tormenta actual tiene como centro:\n POSICION X: %d\n POSICION Y: %d\n\n Su diametro actual es de: %d\n", (*t)[2].posx, (*t)[2].posy, (*t)[2].diametro);
				system("PAUSE");
                break;

			case 8:
                turnos=(*c)[0].turnos;
				i++;
				break ;

			case 9:

                if(strcmp((*j)[p].perfil, "ADM")==0) logueo_adm(&pjugador, p, &pconfigurar); // Comprobamos si el perfil es JGD o ADM
                else logueo_jugador(&pjugador, p, &pconfigurar);
				break ;

		}

	} while ( opcion < 1 || opcion > 9) ; // Hasta introducir una opción válida
	if(i==vivos) i=0;
    }while(vivos!=1);
}

// void restar_turnos ( int *turnos )
// {P} Número de turnos inicializados y > 0
// {Q} Resta 1 al número de turnos
void restar_turnos ( int *turnos ) {

	turnos-- ;

	comprobar_turno(turnos) ;

}

// void comprobar_turno ( int *turnos ) {
// {P} Número de turnos inicializado y > 0
// {Q} Comprueba si el número de turno = 0 , en cuyo caso, llama a la función para finalizar el turno
void comprobar_turno ( int *turnos ) {

	if ( turnos == 0 ) {
	}

}
//
//
//
void formula_hipotenusa (int posx, int posy, int posjx, int posjy, int *posj){
    *posj= sqrt((pow((posjx-posx),2)+(pow((posjy-posy),2))));
}

void comparativa (int posj, int radio){

    printf("\nJugador: %d || Radio: %d\n", posj, (radio/2));
	if (posj<(radio/2))
		printf ("El jugador esta dentro del circulo\n");
	else if(posj>(radio/2)) printf ("EL JUGADOR ESTA FUERA DEL CIRCULO. PA TU CASA GUAPO\n");
        else printf("El jugador esta en el limite del circulo\n");
	}

//
//
//
int movimiento_jugador(int *posx, int *posy, mapita **mp, int i, configurar **c, int turnos){
int o=1;
char op;
    system("cls");
	printf("Hacia que posicion deseas moverte %s\n", (*mp)[i].nick);
	printf ("Posicion Actual: %d, %d\n", *posx, *posy);
    printf (" [W] Subir\n [S] Bajar\n [D] Derecha\n [A] Izquierda\n [X] Salir\n");
	do{
        fflush(stdin);
        do{
        scanf ("%c", &op);
        if(op<97 || op>122) op+=32;

            switch (op){
			case 'w' :
			*posy=*posy+(*c)[0].tamano/25;
			turnos--;
			break;
			case 's':
			*posy=*posy-(*c)[0].tamano/25;
			turnos--;
			break;
			case 'd':
			*posx=*posx+(*c)[0].tamano/25;
			turnos--;
			break;
			case 'a':
			*posx=*posx-(*c)[0].tamano/25;
			turnos--;
			break;
		}
        }while(op<97 || op>132);
		printf("%d%c MOVIMIENTO || Posicion Actual: %d, %d\n", o, 167, *posx, *posy);

		o++;
	}while(turnos>0 && op!='x');
	return turnos;
}

int buscar_estructura(jugador **j, int i, mapita **mp){
int x=0;

    do{
        x++;
    }while(strcmp((*j)[x].nick, (*mp)[i].nick)!=0 && x<numero_jugadores);
    return x;
}

void usar_mochila(jugador**j,objetos**o,mochila**m,int x){

	system("cls");

	int i,y,mem=0;
	char tipo_arma[4] = "arma",tipo_objeto[9] = "accesorio",nombre[20];

	printf("\n\n\tActualmente Tienes en Tu mochila :\n\n ");

	for(i=0;i<lineas_mochila+1;i++){ //Recorre la estrcutura mochila


	  if (strcmp((*j)[x].nick, (*m)[i].portador ) == 0){ //Comprueba si el nombre del usuariuo se encuentra en la estrcutura

	    mem++; // Si esta, suma a la memoria para recordarlo
	      for(y=0;y<numero_objetos-1;y++){

	        if (strcmp( (*o)[y].nombre_objeto , (*m)[i].identificador_arma) == 0){
	//Encuestra el nombre del arma que esta a tu nombre (en la misma linea)
	        if(strcmp( (*o)[0].tipo_objeto, (*o)[y].tipo_objeto) == 0){
	//Comprueba si es un arma o un objeto
	          strcpy (nombre, (*o)[y].clase_objeto);

	      printf("\tUna %s con %i de Municion\n",nombre,(*m)[i].unidades);
	//imprime en pantalla para que el usuario vea que tiene en la mochila
	}else{
	//Si el articulo es un objeto en vez de un arma, hace este proceso(es lo mismo pero con objeto)
	      if(strcmp(  tipo_objeto , (*o)[y].tipo_objeto) == 0){

	        strcpy (nombre,(*o)[y].clase_objeto);

	          printf("\tTienes %i  %s.\n",nombre,(*m)[i].unidades);
	    }

	}
	  }
	}
	}
	}
	//Si el usuario no tiene nada en su mochila, se le informa de ello y se le devuelve al menu
	if (mem==0){printf("\n\n\tAbsolutamente nada\n\n\n");}
	printf("\n\n\n\n");
	system("pause");
inicio_juego(&pjugador, x, &pconfigurar);
}
