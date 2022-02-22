#include <stdio.h>
#include <stdlib.h>
#define N 30

void introducir(char*c1, char*c2);
//void logeo(char*c1, char*c2);

	FILE *fp;

int main(){

	char usuario[N],contra[N],carac;

	puts("Que desea hacer:");

	printf("1.Registrate\n2.Entra en una cuenta existente\n");

	scanf("%c",&carac);

	switch (carac) {

			case '1' : introducir(usuario,contra);break;}

	fclose(fp);

	return 0;
}

void introducir (char*c1, char*c2 ){

	int c;

	puts("Introduce tu nombre de usuario para registro");

	fp = fopen ( "fichero.txt", "at" );

	while((c=getchar())!='\n\n'){

								fputc(c,fp);
        		}
	puts("Introduce tu nueva clave");

		fprintf(fp," ");

		while((c=getchar())!='\n'){

						fputc(c,fp); }

	if (fp==NULL) {fputs ("File error",stderr); exit (1);


}
fclose(fp);
}
/*void logeo (char*c1,char*c2){
char c;
FILE *fp;
puts("Introduce tu usuario");
fp = fopen ("fichero.txt","r");




}
*/
