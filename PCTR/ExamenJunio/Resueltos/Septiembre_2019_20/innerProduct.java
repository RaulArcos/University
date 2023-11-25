//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar innerProduct.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar innerProduct.java
//EJECUCION: mpjrun.bat -np 9 innerProduct
//1 master y 8 slave

import java.util.Random;
import java.util.Arrays;
import mpi.MPI;

public class innerProduct {
    public static void main(String args[]) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int tag = 100, unitSize = 8;
        float v1[] = new float[unitSize], v2[] = new float[unitSize], res[] = {0f}, aux1[] = {0f}, aux2[] = {0f};
        float prod = 0f;
        Random r = new Random();
        int i = 0;
       
        long tIni = System.currentTimeMillis();

        if (rank == 0){ //codigo del emisor
            for (i = 0; i < unitSize; i++){
                v1[i] = (float)r.nextFloat();
                v2[i] = (float)r.nextFloat();
            }

            System.out.println ("Vector 1: " + Arrays.toString(v1));
            System.out.println ("Vector 2: " + Arrays.toString(v2));

            for (i = 0; i < unitSize; i++) {
                aux1[0] = v1[i];
                aux2[0] = v2[i];
                MPI.COMM_WORLD.Send(aux1, 0, 1, MPI.FLOAT, i+1, tag);
                MPI.COMM_WORLD.Send(aux2, 0, 1, MPI.FLOAT, i+1, tag);
            }

            for (i = 0; i < unitSize; i++) {
                MPI.COMM_WORLD.Recv(res, 0, 1, MPI.FLOAT, i+1, tag);
                prod = prod + res[0];
            }

            long tFin = System.currentTimeMillis() - tIni;

            System.out.println(prod);
            System.out.println(tFin + " ms.");
        } else {
            MPI.COMM_WORLD.Recv(aux1, 0, 1, MPI.FLOAT, 0, tag);
            MPI.COMM_WORLD.Recv(aux2, 0, 1, MPI.FLOAT, 0, tag);

            res[0] = aux1[0] * aux2[0];

            MPI.COMM_WORLD.Send(res, 0, 1, MPI.FLOAT, 0, tag);
        }
        MPI.Finalize();
    }
}
