//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar prodMat.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar prodMat.java
//EJECUCION: mpjrun.bat -np 4 prodMat
//1 master y 3 slave

import mpi.MPI;
import java.util.Random;
import java.util.Arrays;

public class prodMat {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int tag = 100, unitSize = 3, i, j;
        float A[] = new float[unitSize * unitSize], B[] = new float[unitSize * unitSize];
        float aux1[] = new float[unitSize], aux2[] = new float[unitSize], aux3[] = new float[unitSize], res[] = new float [unitSize];

        if (rank == 0) {
            for (i = 0; i < unitSize * unitSize; i++) {
                A[i] = i + 1;
                B[i] = 0;
                if (i == 0 || i == unitSize + 1 || i == unitSize * unitSize - 1) B[i] = 1;
            }
            
            for (i = 0; i < unitSize; i++) {
                aux1[i] = A[i];
                aux2[i] = A[unitSize + i];
                aux3[i] = A[2*unitSize + i];
            }
            System.out.println ("Matriz A: ");
            System.out.println (Arrays.toString(aux1));
            System.out.println (Arrays.toString(aux2));
            System.out.println (Arrays.toString(aux3));
            
            for (i = 0; i < unitSize; i++) {
                aux1[i] = B[i];
                aux2[i] = B[unitSize + i];
                aux3[i] = B[2*unitSize + i];
            }
            System.out.println ("Matriz B: ");
            System.out.println (Arrays.toString(aux1));
            System.out.println (Arrays.toString(aux2));
            System.out.println (Arrays.toString(aux3));

            for (i = 0; i < unitSize; i++) {
                aux1[i] = A[i];
                aux2[i] = A[unitSize + i];
                aux3[i] = A[2*unitSize + i];
            }

            MPI.COMM_WORLD.Send (aux1, 0, unitSize, MPI.FLOAT, 1, tag);
            MPI.COMM_WORLD.Send (B, 0, unitSize * unitSize, MPI.FLOAT, 1, tag);

            MPI.COMM_WORLD.Send (aux2, 0, unitSize, MPI.FLOAT, 2, tag);
            MPI.COMM_WORLD.Send (B, 0, unitSize * unitSize, MPI.FLOAT, 2, tag);

            MPI.COMM_WORLD.Send (aux3, 0, unitSize, MPI.FLOAT, 3, tag);
            MPI.COMM_WORLD.Send (B, 0, unitSize * unitSize, MPI.FLOAT, 3, tag);

            MPI.COMM_WORLD.Recv (aux1, 0, unitSize, MPI.FLOAT, 1, tag);
            MPI.COMM_WORLD.Recv (aux2, 0, unitSize, MPI.FLOAT, 2, tag);
            MPI.COMM_WORLD.Recv (aux3, 0, unitSize, MPI.FLOAT, 3, tag);  
            
            System.out.println ("El resultado es: ");
            System.out.println (Arrays.toString(aux1));
            System.out.println (Arrays.toString(aux2));
            System.out.println (Arrays.toString(aux3));
  
        } else if (rank == 1) {
            float auxB[][] = new float[unitSize][unitSize];
            MPI.COMM_WORLD.Recv (aux1, 0, unitSize, MPI.FLOAT, 0, tag);
            MPI.COMM_WORLD.Recv (B, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);

            for (i = 0; i < unitSize; i++){
                auxB[0][i] = B[i];
                auxB[1][i] = B[i + unitSize];
                auxB[2][i] = B[i + 2*unitSize];
            }  
            for (i = 0; i < unitSize; i++) {
                for (j = 0; j < unitSize; j++) 
                    res[j] += (aux1[j] * auxB[j][i]);
            }
            aux1 = res;

            MPI.COMM_WORLD.Send (aux1, 0, unitSize, MPI.FLOAT, 0, tag);
            
        } else if (rank == 2) {
            float auxB[][] = new float[unitSize][unitSize];
            MPI.COMM_WORLD.Recv (aux2, 0, unitSize, MPI.FLOAT, 0, tag);
            MPI.COMM_WORLD.Recv (B, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);

            for (i = 0; i < unitSize; i++){
                auxB[0][i] = B[i];
                auxB[1][i] = B[i + unitSize];
                auxB[2][i] = B[i + 2*unitSize];
            }  
            for (i = 0; i < unitSize; i++) {
                for (j = 0; j < unitSize; j++) 
                    res[j] += (aux2[j] * auxB[j][i]);
            }
            aux2 = res;

            MPI.COMM_WORLD.Send (aux2, 0, unitSize, MPI.FLOAT, 0, tag);

        } else if (rank == 3) {
            float auxB[][] = new float[unitSize][unitSize];
            MPI.COMM_WORLD.Recv (aux3, 0, unitSize, MPI.FLOAT, 0, tag);
            MPI.COMM_WORLD.Recv (B, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);

            for (i = 0; i < unitSize; i++){
                auxB[0][i] = B[i];
                auxB[1][i] = B[i + unitSize];
                auxB[2][i] = B[i + 2*unitSize];
            }  
            for (i = 0; i < unitSize; i++) {
                for (j = 0; j < unitSize; j++) 
                    res[j] += (aux3[j] * auxB[j][i]);
            }
            aux3 = res;

            MPI.COMM_WORLD.Send (aux3, 0, unitSize, MPI.FLOAT, 0, tag);
        }
        MPI.Finalize();
    }

}
