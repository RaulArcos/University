#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nullptr NULL // capricho mio -.-
#define BUFFER_SIZE 2000

///////////////////
inline void showUse()
{
  printf("Error : Pasar como argumento el archivo a removerle los comentarios simples \r\n");
  exit(EXIT_FAILURE);
}
///////////////////
char* removeComments(const char* mFile)
{
  FILE* mFp = fopen(mFile,"rb");
  if (mFp == nullptr) return nullptr;

  // pedimos memoria para el buffer que va a guardar la linea a tratar y para el resultado final
  char* mBuffer = (char*) malloc(BUFFER_SIZE);
  char* mRet = (char*) nullptr;

  // Pedimos cuanto pesa el fichero ..
  fseek(mFp,0,SEEK_END); // Vamos al final
  long mSize = ftell(mFp); // pedimos la posicion
  fseek(mFp,0,SEEK_SET); // vamos al comienzo

  mRet = (char*) malloc(mSize); // pedimos memoria del mismo peso que el archivo original
  mRet[0] = '\0'; // tengamos por seguro que hay un EOF al principio, para strcat ...

  // mientras que no lleguemos al fin del archivo ....
  while(!feof(mFp))
  {
    fgets(mBuffer,BUFFER_SIZE,mFp); // Leemos la cadena con BUFFER_SIZE caracteres como maximo
    char* mPos = strstr(mBuffer,"//"); // obtenemos puntero a la primer ocurrencia de "//"

    // Encontramos algo ?
    if (mPos != nullptr)
	mPos[0] = '\0'; // digamos que aca termino la cadena con un caracter EOF, ignorando el resto

    strcat(mRet, mBuffer); // concatenamos el resultado final con el Buffer ya cambiado

  }

  // Hecho, limpiemos recursos ...
  free(mBuffer); // limpiemos memoria del buffer
  fclose(mFp); // cerremos el fichero
  // y finalmente y opcional, "ajustemos" la memoria del Buffer a retornar
  // ya que pedimos la misma memoria de lo que pesaba el archivo original, y con la eliminacion de los comentarios,seguro pesa menos

  mRet = (char*) realloc(mRet,strlen(mRet)+1); // reajustemos al largo +1 (EOF)

  return mRet;
}
///////////////////
int main(int argc, char **argv)
{
    if(argc<2) showUse();

    char* mFile = removeComments(argv[1]);
    if (mFile == nullptr)
    {
      fprintf(stderr,"Error al leer el archivo !\r\n");
      return EXIT_FAILURE;
    }

    printf(mFile);
    free(mFile); // limpiamos la unica memoria que pedimos que nos quedo sin liberar

    return EXIT_SUCCESS;
}
