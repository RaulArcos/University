#include <windows.h>
#include <MMsystem.h>
#include <stdio.h>
#include <Winmm.lib>

void musica();

void musica(){
PlaySound(TEXT("C:\\Users\\1raul\\Desktop\\Uni\\Uni\\Primer Año\\Segundo 4tri\\MP\\ESINAIT\\bandasonora.wav"),NULL,SND_FILENAME | SND_ASYNC);
}
