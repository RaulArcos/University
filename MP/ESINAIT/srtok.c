#include <stdio.h>
#include <string.h>

int main()
{
   /* inicializa el arreglo de cadena */
   char cadena[] = "Este es un enunciado con 7 tokens";
   char *ptrToken; /* crea un apuntador char */

   printf( "%s\n%sn\n%s\n",
      "La cadena a dividir en tokens es:", cadena,
      "Los tokens son:" );

   ptrToken = strtok( cadena, " " ); /* comienza la divisiÃƒÂ³n en tokens del enunciado */

   /* continua la divisiÃƒÂ³n en tokens hasta que ptrToken se hace NULL */
   while ( ptrToken != NULL ) {
      printf( "%s\n", ptrToken );
      ptrToken = strtok( NULL, " " ); /* obtiene el siguiente token */
   } /* fin de while */

   return 0; /* indica terminaciÃƒÂ³n exitosa */

} /* fin de main */
