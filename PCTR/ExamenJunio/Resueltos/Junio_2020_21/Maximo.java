//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar Maximo.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar Maximo.java
//EJECUCION: mpjrun.bat -np 2 Maximo
//1 master y 1 slave

import mpi.MPI;
import java.util.Random;
import java.util.Arrays;

public class Maximo {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int tag = 100, unitSize = 5;
        Random r = new Random();
        int v[] = new int[unitSize], res[] = {0};

        if (rank == 0) {
            for (int i = 0; i < unitSize; i++) v[i] = r.nextInt(10);

            System.out.println ("Emisor envía la lista: " + Arrays.toString(v));
            
            MPI.COMM_WORLD.Send(v, 0, unitSize, MPI.INT, 1, tag);

            MPI.COMM_WORLD.Recv(res, 0, 1, MPI.INT, 1, tag);

            System.out.println("Emisor recibe: " + res[0]);
            
        } else {
            MPI.COMM_WORLD.Recv(v, 0, unitSize, MPI.INT, 0, tag);

            System.out.println ("Receptor recibe la lista: " + Arrays.toString(v));

            for (int i = 0; i < unitSize; i++) {
                if (v[i] > res[0]) res [0] = v[i];
            }

            System.out.println("Receptor devuelve: " + res[0]);

            MPI.COMM_WORLD.Send(res, 0, 1, MPI.INT, 0, tag);
        }

        MPI.Finalize();
    }
}
