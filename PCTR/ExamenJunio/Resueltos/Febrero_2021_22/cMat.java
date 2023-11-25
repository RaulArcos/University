//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar cMat.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar cMat.java
//EJECUCION: mpjrun.bat -np 4 cMat
//1 master y 3 slave

import mpi.MPI;
import java.util.Random;
import java.util.Arrays;

public class cMat {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int tag = 100, unitSize = 3, i, j = 1, desp = 0;
        float A[] = new float[unitSize * unitSize], B[] = new float[unitSize * unitSize], res[] = new float[unitSize * unitSize];
        float aux1[] = new float[unitSize], aux2[] = new float[unitSize], aux3[] = new float[unitSize];

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

            MPI.COMM_WORLD.Send (A, 0, unitSize * unitSize, MPI.FLOAT, 1, tag);
            MPI.COMM_WORLD.Send (B, 0, unitSize * unitSize, MPI.FLOAT, 1, tag);

            MPI.COMM_WORLD.Send (A, 0, unitSize * unitSize, MPI.FLOAT, 2, tag);
            MPI.COMM_WORLD.Send (B, 0, unitSize * unitSize, MPI.FLOAT, 2, tag);

            MPI.COMM_WORLD.Send (A, 0, unitSize * unitSize, MPI.FLOAT, 3, tag);
            MPI.COMM_WORLD.Recv (res, 0, unitSize * unitSize, MPI.FLOAT, 3, tag);  
            
            
            for (i = 0; i < unitSize; i++) {
                aux1[i] = res[i];
                aux2[i] = res[unitSize + i];
                aux3[i] = res[2*unitSize + i];
            }
            System.out.println ("La traspuesta es: ");
            System.out.println (Arrays.toString(aux1));
            System.out.println (Arrays.toString(aux2));
            System.out.println (Arrays.toString(aux3));
  
        } else if (rank == 1) {
            MPI.COMM_WORLD.Recv (A, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);
            MPI.COMM_WORLD.Recv (B, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);

            for (i = 0; i < unitSize * unitSize; i++) res[i] = A[i] + B[i];

            for (i = 0; i < unitSize; i++) {
                aux1[i] = res[i];
                aux2[i] = res[unitSize + i];
                aux3[i] = res[2*unitSize + i];
            }
            System.out.println ("La suma es: ");
            System.out.println (Arrays.toString(aux1));
            System.out.println (Arrays.toString(aux2));
            System.out.println (Arrays.toString(aux3));
            
        } else if (rank == 2) {
            MPI.COMM_WORLD.Recv (A, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);
            MPI.COMM_WORLD.Recv (B, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);

            float auxA[][] = new float[unitSize][unitSize], auxB[][] = new float[unitSize][unitSize], auxRes[][] = new float[unitSize][unitSize];
            for (i = 0; i < unitSize; i++) {
                auxA[0][i] = A[i];
                auxA[1][i] = A[unitSize + i];
                auxA[2][i] = A[2*unitSize + i];
                auxB[0][i] = B[i];
                auxB[1][i] = B[unitSize + i];
                auxB[2][i] = B[2*unitSize + i];
            }

            for (i = 0; i < unitSize; i++) {
                for (j = 0; j < unitSize; j++) {
                    for (int k = 0; k < unitSize; k++) {
                        auxRes[i][j] += auxA[i][k] * auxB[k][j];
                    }
                }
            }

            System.out.println ("La multiplicacion es: ");
            for (i = 0; i < unitSize; i++)
                System.out.println (Arrays.toString(auxRes[i]));

        } else if (rank == 3) {
            MPI.COMM_WORLD.Recv (A, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);
            float auxA[][] = new float[unitSize][unitSize], auxRes[][] = new float[unitSize][unitSize];;

            for (i = 0; i < unitSize; i++) {
                auxA[0][i] = A[i];
                auxA[1][i] = A[unitSize + i];
                auxA[2][i] = A[2*unitSize + i];
            }

            for (i = 0; i < unitSize; i++) {
                for (j = 0; j < unitSize; j++) auxRes[j][i] = auxA[i][j];
            }

            for (i = 0; i < unitSize; i++) {
                res[i] = auxRes[0][i];
                res[unitSize + i] = auxRes[1][i];
                res[2*unitSize + i] = auxRes[2][i];
            }

            MPI.COMM_WORLD.Send (res, 0, unitSize * unitSize, MPI.FLOAT, 0, tag);
        }
        MPI.Finalize();
    }

}
