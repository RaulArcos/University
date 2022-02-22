// Incluimos las librerías necesarias para la ejecución del código
#include "title_tienda.h"
#include "estructuras.h"

// Declaramos las funciones que vamos a utilizar.
void menu_tienda(jugador**,configurar**,objetos**,mochila**,int);
void comprar_objeto(jugador**,objetos**,mochila**,int);
void ver_mochila(jugador**,objetos**,mochila**,int);
void comprar_municion(jugador**,objetos**,mochila**,int);
void proceso_compra_objeto(jugador**,objetos**,mochila**,int,int,int);
void proceso_compra_municion(jugador**,objetos**,mochila**,int,int,int,int);

char adm[4] = "ADM";
char jgd[4] = "JGD";

// void menu_tienda()
// {P} Ninguna
// {Q} Muestra el menu tienda y lleva al jugador hacia alguna opción
void menu_tienda(jugador** j,configurar** c,objetos** o,mochila **m,int x){




   system("cls"); // Limpiamos pantalla

   title_tienda(); // Llamamos a la función que muestra el título

   int opcion_tienda1 ;


 	do { // Repetimos hasta introducir una opción válida

     // Mostramos las opciones del menu
 		printf("\n\n\n\t%cBienvenido a la Tienda, tienes %i de Saldo%c\n\n\t[1] Comprar un Objeto\n\n\t[2] Comprar Municion\n\n\t[3] Ver Mochila\n\n\t[4] Salir de la tienda\n", 254, (*j)[x].cartera, 254);
 		scanf("%i", &opcion_tienda1);

 	} while ( opcion_tienda1<1 && opcion_tienda1>5 ) ;


 		switch (opcion_tienda1) { // Ejecutamos la opción dependiendo del caso

 			case 1:

 				system("cls") ;
 				comprar_objeto(&pjugador,&pobjetos,&pmochila,x); // Iniciamos la función de comprar_objeto gracias al puntero a la estrucutra del jugador
 				break ;

       case 2:

         comprar_municion(&pjugador,&pobjetos,&pmochila,x);// Inicializamos la funcion de comprar_municion gracias al puntero a la estructura del jugador
         printf("\nGracias por probar ESINITE\n");
         break ;

      case 3:

        ver_mochila(&pjugador,&pobjetos,&pmochila,x); // Inicializamos la funcion de ver_mochila gracias al puntero a la estructura del jugador

        break ;


      case 4:

      guardar_mochila(&pmochila);
      guardar_jugador(&pjugador);

      if(strcmp((*j)[x].perfil, adm)==0){ //Diferencia entre administrador y juagdor para volver a su menu

        logueo_adm(&pjugador,x,&pconfigurar);

    } else logueo_jugador(&pjugador ,x, &pconfigurar);
    // Inicializamos la funcion de guardar_jugador y mochila gracias al puntero a la estructura del jugador

        break ;

 		}
 }

// void comprar_objeto()
// {P} Tienda y estructura iniciadas
// {Q} Realiza el menu para elegir el objeto a comprar
void comprar_objeto(jugador** j,objetos** o,mochila **m,int x){

  system("cls");

int i,y,opcion_tienda3,opcion_tienda2,p,cant;

  printf("\n\n\tLos Articulos Disponibles Son :");

  do { // Repetimos hasta introducir una opción válida

     // Mostramos las opciones del menu
 		printf("\n\n\t[1] Pistola   --   10\n\n\t[2] Escopeta   --   30\n\n\t[3] Ballesta   --   120\n\n\t[4] Botiquin   --   50\n\n\t[5] Pocima   --   90\n\n\t[6] Venda   --   60\n\n\t[7] Skin   --   150\n\n\t[8] Cancelar compra\n ", 254, (*j)[x].cartera, 254);
 		scanf("%i", &opcion_tienda2);

 	} while ( opcion_tienda2<1 && opcion_tienda2>5 ) ;


 		switch (opcion_tienda2) { // Ejecutamos la opción dependiendo del caso

 			case 1:
      p=0;
      cant = 20;
      proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
      //Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas

 				break ;

       case 2:

       p=1;
       cant = 10;
       proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
//Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas
  				break ;

      case 3:

      p=2;
      cant = 5;
      proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
//Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas
 				break ;

      case 4:

      p=3;
      cant = 1;
      proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
//Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas
 				break ;

      case 5:

      p=4;
      cant = 3;
      proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
//Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas
 				break ;


      case 6:

      p=5;
      cant = 5;
      proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
//Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas
 				break ;


        case 7:

        p=6;
        cant = 1;
        proceso_compra_objeto(&pjugador,&pobjetos,&pmochila,x,p,cant);
//Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas
   				break ;


      case 8:

      menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
//Volvemos a la tienda
        break ;

 		}





}


// void comprar_municion
// {P} Tienda y Estructuras Iniciadas
// {Q} Realiza el menu para elegir la municion a comprar
void comprar_municion(jugador** j,objetos** o,mochila **m,int x){

  system("cls");

int opcion_tienda2,p,cant,precio;

  printf("\n\n\tMuniciones Disponibles :");

  do { // Repetimos hasta introducir una opción válida

     // Mostramos las opciones del menu
 		printf("\n\n\t[1] Pistola   --   5  /  10 balas\n\n\t[2] Escopeta   --   10  /  5 balas\n\n\t[3] Ballesta   --   20  /  3 balas\n\n\t[4] Cancelar compra\n ", 254, (*j)[x].cartera, 254);
 		scanf("%i", &opcion_tienda2);

 	} while ( opcion_tienda2<1 && opcion_tienda2>5 ) ;


 		switch (opcion_tienda2) { // Ejecutamos la opción dependiendo del caso

 			case 1:
      p=0;
      precio = 5;
      cant = 10;
      proceso_compra_municion(&pjugador,&pobjetos,&pmochila,x,p,cant,precio);
      //Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas

 				break ;

       case 2:

       p=1;
       precio = 10;
       cant = 5;
       proceso_compra_municion(&pjugador,&pobjetos,&pmochila,x,p,cant,precio);
       //Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas

  				break ;

      case 3:

      p=2;
      precio = 20;
      cant = 3;
      proceso_compra_municion(&pjugador,&pobjetos,&pmochila,x,p,cant,precio);
      //Llamamos a el proceso de compra con los datos de la pistola y la cantidad de balas

 				break ;


      case 4:

      menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
//volvemos al menu de la tienda
        break ;

 		}



}



// void proceso_compra_objeto()
// {P} comprar_objeto y estructuras iniciado
// {Q} Realiza los cambios de valores de la estructura para llevar a cabo la compra de un objeto
void proceso_compra_objeto(jugador** j,objetos** o,mochila **m,int x,int p,int cant){

int i,y,opcion_tienda3,opcion_tienda2,precio,dinero,mem = 0;

system("cls") ;


//Se le dan valores a las dos variables que se usaran despues
precio = (*o)[p].coste_objeto;
dinero = (*j)[x].cartera;

  for(i=0;i<lineas_mochila+1;i++){
//Comprueba a traves de la mochila si coinciden el nombre del usuario y si este tiene el arma en posesion
    if (strcmp((*j)[x].nick, (*m)[i].portador ) == 0 &&  strcmp((*o)[p].nombre_objeto, (*m)[i].identificador_arma) == 0){mem++;}

    if (i==lineas_mochila){
//En caso de que lo tenga, entrara aqui y se le dara la opcion de comprar otro objeto
      if (mem>0){

        printf("\n\n\tNo Puedes Comprar Este Objeto, Ya lo Tienes.\n");

        do { // Mostramos las opción tras no haber un usuario como el introducido

            printf("\n[1] Comprar municion\n[2] Comprar Otro Objeto\n[3] Volver a la Tienda\n");

            scanf("%i", &opcion_tienda3);

          } while ( opcion_tienda3<1 && opcion_tienda3>3 ) ; // Repetimos hasta introducir una opción válida

        switch (opcion_tienda3){ // Ejecutamos las opciones

            case 1:
            printf("Comprar municion");
                  ; // Llamamos a la función para comprar municion
                  break;

            case 2:
            comprar_objeto(&pjugador,&pobjetos,&pmochila,x);
                   // Llamamos a la función para comprar
                  break;

            case 3:

                  system("cls") ;
                menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
                  break;
        }

      } else {
//Si no se ecnuentra su nombre en la mochila, le da la opcion de comprarlo
        if(dinero<precio){printf("\n\nNo tienes suficiente dinero\n\n"); system("pause"); comprar_objeto(&pjugador,&pobjetos,&pmochila,x); }else{

      lineas_mochila++;
          strcpy ((*m)[lineas_mochila-1].portador , (*j)[x].nick) ; // Se copia su nick en el portador de la linea correspondiente

          strcpy ((*m)[lineas_mochila-1].identificador_arma , (*o)[p].nombre_objeto) ; //Lo mismo con le nombre dek objeto

          (*m)[lineas_mochila-1].unidades = cant; // //Se le añade la cantidad de balas o de cantidad de objetos que tendra tras la compra

          (*j)[x].cartera = (*j)[x].cartera - precio; // Se le resta a la cartera el precio del objetow


printf("\n\n\tObjeto Adquirido con Exito, Pulsa 1 para Volver a la Tienda\n\n\n");

scanf("%i",&y);

if (y == 1 ) system("cls");  menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);


        }


      }
    }
  }
}



// void proceso_compra_municion
// {P} comprar_municion y estrcuturas iniciadas
// {Q} Realiza los cambios de valores de la estructura para llevar a cabo la compra de municion
void proceso_compra_municion(jugador** j,objetos** o,mochila **m,int x,int p,int cant,int precio){

  system("cls") ;

  int i,opcion_tienda3,n,dinero,mem=0;


  dinero = (*j)[x].cartera;


    for(i=0;i<lineas_mochila+1;i++){

      if (strcmp((*j)[x].nick, (*m)[i].portador ) == 0 &&  strcmp((*o)[p].nombre_objeto, (*m)[i].identificador_arma) == 0){
mem++;

}
if(i == lineas_mochila && mem>0){
  if(dinero<precio){printf("\n\nNo tienes suficiente dinero\n\n"); system("pause"); comprar_municion(&pjugador,&pobjetos,&pmochila,x); }else{

          (*m)[lineas_mochila-1].unidades =((*m)[lineas_mochila-1].unidades) + cant;
          (*j)[x].cartera = dinero - precio;

          printf("\nMunicion Comprada con Éxito\n");

          system("pause");
          menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
          break;
        }

      }

      if (i== lineas_mochila && mem<=0){


        printf("\n\n\tNo tienes El Arma para Compar Municion.\n");

        do { // Mostramos las opción tras no haber un usuario como el introducido

            printf("\n[1] Comprar Objeto\n[2] Comprar Municion de Otro Arma\n[3] Volver a la Tienda\n");

            scanf("%i", &opcion_tienda3);

          } while ( opcion_tienda3<1 && opcion_tienda3>3 ) ; // Repetimos hasta introducir una opción válida

        switch (opcion_tienda3){ // Ejecutamos las opciones

            case 1:
            comprar_objeto(&pjugador,&pobjetos,&pmochila,x);
                   // Llamamos a la función para volver a loguearse
                  break;

            case 2:
            comprar_municion(&pjugador,&pobjetos,&pmochila,x);
                   // Llamamos a la función para registrar un jugador
                  break;

            case 3:

                  system("cls") ;
                menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
                  break;
        }

      }



}
}


// void ver_mochila
// {P} Tienda y Estructuras Iniciadas
// {Q} Permite al usuario ver que hay en su mochila.
void ver_mochila(jugador** j,objetos** o,mochila **m,int x){

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
menu_tienda(&pjugador,&pconfigurar,&pobjetos,&pmochila,x);
}
