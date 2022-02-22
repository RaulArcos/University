#include "menu_partida.h" // Incluimos las estruturas

// Inicializamos los protipos a utilizar
void usar_objeto ( mochila **m , jugador **j , int posicion_jugador_estructura , int x ) ;
void recuperar_vida ( mochila **m , jugador **j , int posicion_jugador_estructura , int x , int vida_recuperada) ;
void recuperar_escudo ( mochila **m , jugador **j , int posicion_jugador_estructura , int x) ;
void reducir_unidades ( mochila **m , int x ) ;
void disparar (mochila **m , jugador **j , mapita **mp , int x) ;
void calcular_distancias ( mochila **m , objetos **o , jugador **j , mapita **mp , int x ) ;
int distancia_jugadores (int xp , int xc , int yp , int yc ) ;
void danar_jugador (objetos **o , jugador **j , int otro_jugador , int x) ;
void seleccionar_objeto ( mochila **m , jugador **j , int posicion_jugador_estructura) ;
// void seleccionar_objeto ( mochila **m , jugador **j , int posicion_jugador_estructura) 
// {P} Estructurar mochila y jugador inicializada y cargada, posicion del jugador en la estrutura inicalizada
// {Q} Permite seleccionar al jugador que objeto de la mochila quiere usar
void seleccionar_objeto ( mochila **m , jugador **j , int posicion_jugador_estructura) {

	int variable_seleccionadora = -1 , opcion ;

	do { // Repetimos el proceso hasta que 

		variable_seleccionadora++ ; 

		system ("cls") ; // Limpiamos pantalla

		printf ("\n%cQue objeto quieres usar?\n\t%c%s[1/0]\n" , 168 , 62 , (*m)[variable_seleccionadora].identificador_arma ); // Le mostramos el objeto y le decimos si quiere usar ese

		do { // Repetimos hasta

			scanf ( "%i" , &opcion ) ; // Pedimos opción

		} while ( opcion != 1 || opcion != 0 ) ; // Introducir una opción válida

	} while ( opcion != 1 && variable_seleccionadora < lineas_mochila ) ; // Se llegue a fin de la mochila o se diga que no quiere usar ese objeto

	usar_objeto ( &pmochila , &pjugador , posicion_jugador_estructura , variable_seleccionadora ) ; // Llamamos a la función para distinguir y usar los objetos

}
// void usar_objeto ( mochila **m , jugador **j , int posicion_jugador_estructura , int x , int vida_recuperada ) 
// {P} Estructura mochila y posición del jugador en la estructura cargado, vida recuperada y las posiciones de los jugadores en las estructuras inicializadas
// {Q} Llama a una función u otra dependiendo del tipo de objeto que sea
void usar_objeto ( mochila **m , jugador **j , int posicion_jugador_estructura , int x ) {

	char bot[4] = "BOT" ;
	char poc[4] = "POC" ;
	char ven[4] = "VEN" ;

		if ( strcmp ((*m)[x].identificador_arma , bot) == 0 ) { // Si el objeto que tenemos es un botiquín

			recuperar_vida (&pmochila , &pjugador , posicion_jugador_estructura , x , 100) ; // Recuperamos vida

		}

		else if ( strcmp ( (*m)[x].identificador_arma , ven) == 0 ) { // Si el objeto es una poción
			
			recuperar_vida (&pmochila , &pjugador , posicion_jugador_estructura , x , 25) ; // Recuperamos vida

		}

			
		else if ( strcmp ( (*m)[x].identificador_arma , poc) == 0 ) { // Si el objeto es una poción
			
			recuperar_escudo (&pmochila , &pjugador , posicion_jugador_estructura , x) ; // Recuperamos escudo

		}



		else { // Si no es ni un botiquín ni una poción, es un arma así que:

			disparar (&pmochila , &pjugador , &pmapa , posicion_jugador_estructura) ; // Disparamos

		}

}

// void recuperar_vida ( mochila **m , mochila **j , int posicion_jugador_estructura , int x )
// {P} Estructura mochila y jugador cargada, posición del jugador en la estructura y mochila inicializado, así como la cantidad de vida recuperada dependiendo del objeto que sea
// {Q} Recuperamos la cantidad de vida al jugador dependiendo del objeto utilizado
void recuperar_vida ( mochila **m , jugador **j , int posicion_jugador_estructura , int x , int vida_recuperada ) {

	(*j)[posicion_jugador_estructura].vida =+ vida_recuperada ; // Le ponemos la salud al máximo

	if ( vida_recuperada == 25 ) { // Miramos si la vida recuperada es por usar vendas

		(*j)[posicion_jugador_estructura].vida =+ 25 ; // Aumentamos su vida en 25
 
		if ( (*j)[posicion_jugador_estructura].vida >= 75 ) { // Si la vida es mayor o igual que 75

			(*j)[posicion_jugador_estructura].vida = 75 ; // Fijamos la vida a 75

		}

	} 

	else { // Si no es 25, significa que ha pasado un botiquín y le hemos pasado 100

		(*j)[posicion_jugador_estructura].vida = 100 ; // Fijamos la vida a 100

	}

	reducir_unidades (&pmochila , x) ; // Reducimos en uno la unidad


}

// void recuperar_escudo ( mochila **m , jugador **j , int posicion_jugador_estructura , int x) 
// {P} Estructura de mochila y jugador cargadas, posicion jugador en la estructura y x inicializados
// {Q} Recupera 50 de escudo al jugador que ha utilizado la poción
void recuperar_escudo ( mochila **m , jugador **j , int posicion_jugador_estructura , int x) {

	(*j)[posicion_jugador_estructura].escudo =+ 50 ; // Aumentamos su escudo en 50
	
	if ( (*j)[posicion_jugador_estructura].escudo >= 100 ) { // Si la cantidad de escudo supera la máxima

		(*j)[posicion_jugador_estructura].escudo = 100 ; // Fijamos el escudo al máximo

	} 

	reducir_unidades (&pmochila , x) ; // Reducimos las unidades

}
// void reducir_unidades ( mochila **m , int x ) 
// {P} Estructura mochila cargada e inicializada, posición en la estructura inicializado
// {Q} Reduce en uno las unidades del objeto utilizado
void reducir_unidades ( mochila **m , int x ) {

	(*m)[x].unidades -- ; // Reducimos en uno la unidad del objeto en cuestio

 	if ( (*m)[x].unidades == 0 ) { // Si las unidades son 0
 
		printf("\nNo tienes más unidades de este objeto\n") ; // No puede seguir usando objetos

	}

}

// void disparar ( mochila **m , jugador **j , mapita **mp , int x ) 
// {P} Estructura mochila, jugador y mapa cargada e inicializada, posición del jugador en la estructura mochila inicializada
// {Q} Llama a la función para disparar a los jugadores a rango y reduce la munición
void disparar ( mochila **m , jugador **j , mapita **mp , int x ) {

	calcular_distancias (&pmochila , &pobjetos , &pjugador , &pmapa , x ) ; // Calculamos la distancia para ver que jugadores están dentro del rango del arma
	
	reducir_unidades ( &pmochila , x ) ; // Reducimos la unidad del objeto utilizado

}
// void calcular_distancias ( mochila **m , objetos **o , jugador **j , mapita **mp , int x) 
// {P} Estructura mochila , objetos , jugador y mapa inicalizadas y cargada, posición del jugador en la estructura mochila inicaliada
// {Q} Detecta los jugadores a rango de nuestra arma y llama a la siguiente función para disparar
void calcular_distancias ( mochila **m , objetos **o , jugador **j , mapita **mp , int x) {

	int aux , cont , otro_jugador , opcion ;

	for ( cont = 0 ; cont <= numero_objetos ; cont ++ ) { // Recorremos la estructura de objetos para saber el rango del arma que vamos a usar

		 if (strcmp ( (*m)[x].identificador_arma , (*o)[cont].nombre_objeto ) == 0 ) { // Si obtenemos coincidencia

		 	aux = cont ; // Nos quedamos con la posición en la estructura objetos

		 } 

	}

	for ( otro_jugador = 0 ; otro_jugador <= numero_jugadores ; otro_jugador++ ) { // Comparamos la distancia entre nuestra posición y los demás jugadores
		
		if ( distancia_jugadores ( (*mp)[x].posx , (*mp)[x].posy , (*mp)[otro_jugador].posx , (*mp)[otro_jugador].posy ) <= (*o)[cont].alcance_objeto ) { // Si están dentro del rango de nuestra arma

			printf("\t\s esta a rango\n%c Quieres disparar ?\n[1] Si\n[2] No\n" , (*j)[otro_jugador].nick , 168 ); // Mostramos quien está a rango y le damos la opción de disparar

			do { // Pedimos la opción de si y no

				scanf("%i" , &opcion);

			} while ( opcion != 1 || opcion != 2 ) ; // Hasta introducir una opción válida

			if ( opcion == 1 ) { // Si ha elegido que si

				danar_jugador (&pobjetos , &pjugador , otro_jugador , x ) ; // Llamamos a la función para dañar al jugador

			}

		}

	}

	system("pause") ;

}
// void danar_jugador ( objetos **o , jugadores **j , int otro_jugador , int x ) {
// {P} Estructura objetos y jugadores cargada, posición del jugador en la estructura y del jugador a rango inicializada
// {Q} Resta la vida y escudo al jugador objetivo y realiza las comprobaciones
void danar_jugador ( objetos **o , jugador **j , int otro_jugador , int x ) {

	int damage_auxiliar ;

	if ( (*j)[otro_jugador].escudo > 0 ) { // Si el escudo del objetivo > 0 

		 (*j)[otro_jugador].escudo = (*j)[otro_jugador].escudo - (*o)[x].damage ; // Reducimos su escudo

		 if (  (*j)[otro_jugador].escudo < 0 ) { // Si al reducir ha quedado menor que 0

		 	damage_auxiliar = abs ((*j)[otro_jugador].escudo) ; // Obtenemos el valor absoluto del daño restante

		 	(*j)[otro_jugador].escudo = 0 ; // Fijamos el escudo a 0

		 	(*j)[otro_jugador].vida = (*j)[otro_jugador].vida - damage_auxiliar ; // Restamos el valor absoluto a la vida restante

		 	if ( (*j)[otro_jugador].vida <= 0 ) { // Si el jugador abatido ha muerto

		 		if ( numero_jugadores == 0 ) { // Y era el último en partida
  
		 			printf("\n Has Ganado la Partida\n") ; // Mostrar la victoria

		 		}
 
		 		else { // Si no lo era

		 			mostrar_menu ( &pjugador , x ) ; // Regresar al menu para efectuar acción

		 		}
		 	}
		 }
	}

}

// int distancia_jugadores ( int xp , int xc , int yp , int yc )  
// {P} Posición x e y del jugadores 1 y 2 inicializado
// {Q} Devuelve la distancia entre dos jugadores
int distancia_jugadores ( int xp , int yp , int xc , int yc ) {

	float distancia = sqrt  ( pow( (xp - xc) , 2 ) + pow( (yp - yc) , 2) )  ; // Declaramos la distancia como la fórmula de Pitágoras para calcular la distanica entre dos jugadores

	return distancia ; // Devolvemos la distancia entre los dos jugadores
}