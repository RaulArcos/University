//transfiere un array de enteros del emisor al recpetor
//COMPILACION:javac -cp .;%MPJ_HOME%/lib/mpj.jar ArrayPuntoAPunto.java
//EJECUCION: mpjrun.bat -np 2 ArrayPuntoAPunto 
//NOTA: CONFIGURAR de manera previa MPJ-Express adecuadamente

import mpi.*;
import java.util.Arrays;
public class ArrayPuntoAPunto {

public static void main(String args[]) throws Exception {
 MPI.Init(args);
 int rank = MPI.COMM_WORLD.Rank();
 int size = MPI.COMM_WORLD.Size();
 int emisor = 0; int receptor = 1;
 int tag = 100; int unitSize = 10;
 
 if(rank==emisor){ //codigo del emisor
 	 int bufer[] = new int[10];
 	 for(int i=0; i<bufer.length; i++)bufer[i] = i;
 	 MPI.COMM_WORLD.Send(bufer, 0, unitSize, MPI.INT, receptor, tag);
 } else{ //codigo del receptor
 	 int revbufer[] = new int[10];
 	 MPI.COMM_WORLD.Recv(revbufer, 0, unitSize, MPI.INT, emisor, tag);
 	 System.out.println("Recibido: "+Arrays.toString(revbufer));
   }

 MPI.Finalize();
 
 }
}