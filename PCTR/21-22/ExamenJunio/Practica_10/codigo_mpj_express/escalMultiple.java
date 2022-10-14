//COMPILACION: javac -cp .;%MPJ_HOME %/lib/mpj.jar escalMultiple.java
//EJECUCION: mpjrun.bat -np 5 escalMultiple

import mpi.*;
import java.util.Arrays;

public class escalMultiple {
    public static void main(String args[]) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int emisor = 0;
        int tag = 100; 
        int unitSize = 10;
        
        int v[] = new int[10];
        if(rank==0){
            for (int i = 0; i < 10; i++) v[i] = 1;
        } 
       
        MPI.COMM_WORLD.Bcast(v, 0, unitSize, MPI.INT, 0);
       
        if(rank==1){ 
            int v1[] = new int[10];
            for (int i = 0; i < 10; i++) v1[i] = v[i] * rank;
            System.out.println(Arrays.toString(v1));
        }else if(rank==2){ 
                int v2[] = new int[10];
                for (int i = 0; i < 10; i++) v2[i] = v[i] * rank;
                System.out.println(Arrays.toString(v2));
            }else if(rank==3){
                    int v3[] = new int[10];
                    for (int i = 0; i < 10; i++) v3[i] = v[i] * rank;
                    System.out.println(Arrays.toString(v3));
                }else if(rank==4){ 
                        int v4[] = new int[10];
                        for (int i = 0; i < 10; i++) v4[i] = v[i] * rank;
                        System.out.println(Arrays.toString(v4));
                }
        MPI.Finalize();
    }
}

