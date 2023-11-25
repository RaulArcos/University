//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar tokenRing.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar tokenRing.java
//EJECUCION: mpjrun.bat -np 10 tokenRing
//1 master y 9 slave

import mpi.MPI;

import javax.swing.plaf.synth.SynthEditorPaneUI;

public class tokenRing {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int tag = 100, unitSize = 1;
        int token[] = {10}, flag = 0;

        if (rank == 0) {             
            do {
                System.out.println("Soy el proceso " + rank + " y el token vale: " + token[0]);
                MPI.COMM_WORLD.Send(token, 0, unitSize, MPI.INT, rank + 1, tag); 
                MPI.COMM_WORLD.Recv(token, 0, 1, MPI.INT, size - 1, tag);
                token[0]++;
                flag++;
            } while (flag < 2);
           
        } else {
            do {
                MPI.COMM_WORLD.Recv(token, 0, unitSize, MPI.INT, rank - 1, tag);
                token[0]++;
                flag++;
                System.out.println("Soy el proceso " + rank + " y el token vale: " + token[0]);
                MPI.COMM_WORLD.Send(token, 0, unitSize, MPI.INT, (rank + 1) % size, tag);
            } while (flag < 2);
        }
        MPI.Finalize();
    }
}