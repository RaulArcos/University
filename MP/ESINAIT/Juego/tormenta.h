#include "estructuras.h"
#include <math.h>

void tormenta_aleatoria(configurar **);
void reducir_mapa(int *, int *, int *, configurar **);


void tormenta_aleatoria(configurar **c){
int diametro = (*c)[0].tamano, posx=0, posy=0;
FILE *tormenta;

    tormenta=fopen("tormenta.txt", "w");
    if(!tormenta){
        printf("ERROR AL ABRIR EL ARCHIVO");
    }

   do{
        fprintf(tormenta, "%d/%d/%d/180/\n", posx, posy, diametro);
        reducir_mapa(&posx, &posy, &diametro, &pconfigurar);
	}while(diametro>((*c)[0].tamano/10));

rewind(tormenta);
fclose(tormenta);
}

void reducir_mapa (int *posx, int *posy, int *diametro, configurar **c){  //diametro = (*c)[0].tamano  TAMAÑO INICIAL DE LA TORMENTA
int reducir;
int posx2 = -(*diametro/25) + rand() % (((*diametro/25)+1) +(*diametro/25));
int posy2 = -(*diametro/25) + rand() % (((*diametro/25)+1) +(*diametro/25));

int D=sqrt((pow((posx2-*posx),2)+(pow((posy2-*posy),2))));
int f;

    do{
    reducir = rand() % (((*c)[0].tamano/10)+1)+((*c)[0].tamano/10);
    f=*diametro-reducir;
    if(f<((*c)[0].tamano/10)){
        f=0;
     }
    }while(D>(*diametro-f) && f!=0);
    *diametro=f;
    *posx=posx2;
    *posy=posy2;
}

