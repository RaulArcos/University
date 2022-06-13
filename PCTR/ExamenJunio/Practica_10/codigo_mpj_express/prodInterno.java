//COMPILACION: javac -cp .;%MPJ_HOME %/lib/mpj.jar prodInterno.java
//EJECUCION: mpjrun.bat -np 2 prodInterno

import mpi.*;
import java.util.Arrays;

public class prodInterno {
    public static void main(String args[]) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int emisor = 0; int receptor = 1;
        int tag = 100; int unitSize = 4;
        
        if(rank==emisor){ //codigo del emisor
            int v1[] = {2, 4, 5, 4};
            int v2[] = {1, 4, 2, 5};
            int res[] = new int[1];
            MPI.COMM_WORLD.Send(v1, 0, unitSize, MPI.INT, receptor, tag);
            MPI.COMM_WORLD.Send(v2, 0, unitSize, MPI.INT, receptor, tag);

            MPI.COMM_WORLD.Recv(res, 0, 1, MPI.INT, receptor, tag);
            System.out.println(res[0]);

        } else{ //codigo del receptor
            int v1rec[] = new int[4];
            int v2rec[] = new int[4];
            int res[] = new int[1];
            MPI.COMM_WORLD.Recv(v1rec, 0, unitSize, MPI.INT, emisor, tag);
            MPI.COMM_WORLD.Recv(v2rec, 0, unitSize, MPI.INT, emisor, tag);
            System.out.println("Recibido: " + Arrays.toString(v1rec));
            System.out.println("Recibido: " + Arrays.toString(v2rec));

            for (int i = 0; i < 4; i++) res[0] = res[0] + (v1rec[i] * v2rec[i]);

            MPI.COMM_WORLD.Send(res, 0, 1, MPI.INT, emisor, tag);
        }
       
        MPI.Finalize();
    }
}
