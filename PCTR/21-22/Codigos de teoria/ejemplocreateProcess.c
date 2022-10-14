#include <windows.h>
#include <stdio.h>
#include <tchar.h>
void _tmain( int argc, TCHAR *argv[] ){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    if( argc != 2 ){
        printf("Empleo: \%s [orden DOS]\n", argv[0]);
        return;
    }
    // Arranca hijo...
    if(!CreateProcess(NULL, argv[1], NULL, NULL,           
                      FALSE, 0, NULL, NULL, &si, &pi))

{printf( "CreateProcess failed (\%d).\n", GetLastError() );
   return;
  }
  WaitForSingleObject( pi.hProcess, INFINITE );
  CloseHandle( pi.hProcess );
  CloseHandle( pi.hThread );
}