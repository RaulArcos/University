//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar mpj.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar mpj.java
//EJECUCION: mpjrun.bat -np 5 mpj
//1 master y 4 slave

import mpi.MPI;

import javax.swing.plaf.synth.SynthEditorPaneUI;

public class mpj {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int tag = 100, unitSize = 4;
        int vectorAux[] = new int[unitSize], res[] = {0}; //estas variables las COMPARTEN TODOS LOS PROCESOS, y son INDEPENDIENTES en cada uno de ellos

        if (rank == 0) {
                            //referencia a UN VECTOR, offset (no sirve para nada, 0 por defecto), tamaño del vector, tipo de datos, emisor(recv)/receptor(send), etiqueta
            MPI.COMM_WORLD.Send(vectorAux, 0, unitSize, MPI.INT, i+1, tag); //por cada send un recv en el otro proceso
            MPI.COMM_WORLD.Recv(res, 0, 1, MPI.INT, i+1, tag);
           
        } else {
            MPI.COMM_WORLD.Recv(vectorAux, 0, unitSize, MPI.INT, 0, tag);
            MPI.COMM_WORLD.Send(res, 0, 1, MPI.INT, 0, tag);
        }

        MPI.Finalize();
    }
}