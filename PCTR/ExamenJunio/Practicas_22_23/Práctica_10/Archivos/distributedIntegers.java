//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar distributedIntegers.java
//EJECUCION: mpjrun.bat -np 11 distributedIntegers

import mpi.*;
import java.util.Arrays;

public class distributedIntegers {

    public static boolean esPrimo (int numero) {
        if (numero == 0 || numero == 1 || numero == 4) return false;
        for (int x = 2; x < numero / 2; x++) {
            if (numero % x == 0) return false;
        }
        return true;
    }

    public static void main(String args[]) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int tag = 100, unitSize = 1;
        int tamano[] = new int[1], gPrimos[] = {0}, lPrimos[] = {0};;

        if(rank == 0){
            tamano[0] = (int)(10000000 / (size - 1));
        } 
       
        MPI.COMM_WORLD.Bcast(tamano, 0, unitSize, MPI.INT, 0);
       
        if (rank != 0) {
            int linf = (rank - 1) * tamano[0], lsup = (rank) * tamano[0];

            for (int i = linf; i < lsup; i++) {
                if (esPrimo(i)) lPrimos[0]++;
            }
        }
        
        MPI.COMM_WORLD.Reduce(lPrimos, 0, gPrimos, 0, 1, MPI.INT, MPI.SUM, 0);

        if(rank == 0){
            System.out.println(gPrimos[0]);
        } 

        MPI.Finalize();
    }
}
