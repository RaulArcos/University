//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar sumMatDistribuida.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar sumMatDistribuida.java
//EJECUCION: mpjrun.bat -np 5 sumMatDistribuida
//1 master y 4 slave

import mpi.MPI;
import java.util.Random;
import java.util.Arrays;

import javax.swing.plaf.synth.SynthEditorPaneUI;

public class sumMatDistribuida {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int tag = 100, unitSize = 4;
        Random r = new Random();
        int matriz[][] = new int[unitSize][unitSize];
        int vectorAux[] = new int[unitSize], res[] = {0}, suma = 0;

        if (rank == 0) {
            for (int i = 0; i < unitSize; i++) {
                for (int j = 0; j < unitSize; j++) matriz[i][j] = r.nextInt(2);
            }

            System.out.println("Matriz INICIAL");
            for (int i = 0; i < unitSize; i++) {
                for (int j = 0; j < unitSize; j++) {
                    System.out.print(matriz[i][j] + " ");
                }
                System.out.println();
            }

            System.out.println("\n\n\n");

            for (int i = 0; i < unitSize; i++) {
                for (int j = 0; j < unitSize; j++) {
                    vectorAux[j] = matriz[i][j]; 
                }
                MPI.COMM_WORLD.Send(vectorAux, 0, unitSize, MPI.INT, i+1, tag);
            }

            for (int i = 0; i < unitSize; i++) {
                MPI.COMM_WORLD.Recv(res, 0, 1, MPI.INT, i+1, tag);
                suma = suma + res[0];
            }

            System.out.println("El resultado final de la matriz es: " + suma);
        } else {
            MPI.COMM_WORLD.Recv(vectorAux, 0, unitSize, MPI.INT, 0, tag);

            for (int i = 0; i < unitSize; i++) {
                res[0] = res[0] + vectorAux[i];
            }

            System.out.println("El resultado de la suma del rank " + rank + " es: " + res[0]);

            MPI.COMM_WORLD.Send(res, 0, 1, MPI.INT, 0, tag);
        }

        MPI.Finalize();
    }
}