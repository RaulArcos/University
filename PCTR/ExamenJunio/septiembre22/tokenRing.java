//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar mpj.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar mpj.java
//EJECUCION: mpjrun.bat -np 10 mpj
//1 master y 9 slave

import mpi.MPI;

import javax.swing.plaf.synth.SynthEditorPaneUI;

public class tokenRing {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int tag = 100, unitSize = 1;
        int vectorAux[] = new int[unitSize], res[] = {0}; //estas variables las COMPARTEN TODOS LOS PROCESOS, y son INDEPENDIENTES en cada uno de ellos
        int token = 10;
        int vueltas = 2;

        if (rank == 0) {
            if(token <= vueltas*size){
                System.out.println("Soy el proceso " + rank + " y el vale token " + token);
                MPI.COMM_WORLD.Send(token+1, 0, unitSize, MPI.INT, rank+1, tag);
            }else{
                System.out.println("Soy el proceso " + rank + " y el vale token " + token);
            }
            MPI.COMM_WORLD.Recv(token, 0, 0, MPI.INT, size-1, tag);
        } else {
            MPI.COMM_WORLD.Recv(token, 0, unitSize, MPI.INT, rank-1, tag);
            System.out.println("Soy el proceso " + rank + " y el vale token " + token);
            MPI.COMM_WORLD.Send(token+1, 0, unitSize, MPI.INT, rank+1, tag);
        }
    
        MPI.Finalize();
    }
}