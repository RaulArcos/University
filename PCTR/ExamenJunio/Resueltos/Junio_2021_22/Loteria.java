//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar Loteria.java
//COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar Loteria.java
//EJECUCION: mpjrun.bat -np i Loteria
//1 master y i slave

import mpi.MPI;
import java.util.Random;
import java.util.Arrays;
import java.util.*;

import javax.swing.plaf.synth.SynthEditorPaneUI;

public class Loteria {
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int tag = 100, unitSize = 1;
        Random r = new Random();
        int win[] = new int[unitSize], res[] = new int[unitSize], winner[] = {0}, aux = 0, i;
        boolean flag = false;

        
        if (rank == 0) {
            win[0] = r.nextInt(100);
            System.out.println("Numero secreto: " + win[0]);

            do{
                for (i = 1; i < size; i++) MPI.COMM_WORLD.Send(winner, 0, unitSize, MPI.INT, i, tag);
                for (i = 1; i < size; i++) {
                    MPI.COMM_WORLD.Recv(res, 0, unitSize, MPI.INT, i, tag);
                    System.out.println("Proceso " + i + " juega con el numero " + res[0]);
                    if (win[0] == res[0]) {
                        flag = true; 
                        aux = i;
                    }
                }
            } while(flag != true);  
            
            winner[0] = aux;
            System.out.println("Proceso " + aux + " ha ganado");
            for (i = 1; i < size; i++) MPI.COMM_WORLD.Send(winner, 0, unitSize, MPI.INT, i, tag);
        } else {
            do {
                MPI.COMM_WORLD.Recv(winner, 0, unitSize, MPI.INT, 0, tag);
                res[0] = r.nextInt(100);
                MPI.COMM_WORLD.Send(res, 0, unitSize, MPI.INT, 0, tag);
            } while (winner[0] == 0);
        }

        MPI.Finalize();
    }
}