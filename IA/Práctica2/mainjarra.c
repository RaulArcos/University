#include "jarras.h"
#include <stdio.h>
//g++ -o jarras jarras.h jarras.c mainjarra.c
int main() {
//pruebas del código generado
int op;
tEstado *a;
a=estadoInicial();

printf("Estado Inicial: ");

while(testObjetivo(a) == 0){
    
    dispEstado(a);
    printf("Elige Movimiento\n[1]Llenar J4\n[2]Llenar J3\n[3]Vaciar J4\n[4]Vaciar J3\n[5]Llenar 4 con 3\n[6]Llenar J3 con J4\n[7]Vaciar 3 en 4\n[8]Vaciar 4 con 3\n");
    scanf("%i",&op);
   
    if(op>0 && esValido(op, a)==1)
    
    {
       a = aplicaOperador(op,a);
    } else
    {
        printf("Operador No válido.\n");
    }
    

}
printf("Lo hisiste");
return 0;
}//main