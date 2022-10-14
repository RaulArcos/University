include <stdio.h>
#include <unistd.h>
int main(){
    int id;
    id = fork();
    if (id > 0) {
        printf("padre, con id: %d\n", getpid());
    }
    else if (id == 0) {
        printf("hijo, con id: %d \n", getpid());
        printf("padre, con id: %d.\n", getppid());
    }
    else {
        printf("error en fork\n");
    }
    return 0;
}

