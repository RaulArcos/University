//Maria Teresa Supervielle Sanchez 77172557J
//COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar intDistribuida.java C:\mpj
//EJECUCION: mpjrun.bat -np 3 intDistribuida
//1 master y 2 slave

import mpi.MPI;

import java.util.concurrent.locks.LockSupport;

import javax.swing.plaf.synth.SynthEditorPaneUI;

public class intDistribuida {

    public static double f (double x) {return (4/(1 + Math.pow(x, 2)));}
    public static double g (double x) {return (Math.cos(x) + Math.pow(x, 3));}

    public static double integral (double linf, double lsup, int r) {
        if (r == 1) {
            return ((lsup - linf) * ((f(linf) + f(lsup)) / 2));
        } else {
            return ((lsup - linf) * ((g(linf) + g(lsup)) / 2));
        }
    }
    
    public static void main (String[] args) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int tag = 100, unitSize = 3;
        double datos[] = new double[unitSize], res[] = {0}; 

        if (rank == 0) {
            datos[0] = 0; //limite inferior
            datos[1] = 1; //limite superior
            datos[2] = 40; //subintervalo

            for (int i = 1; i <= 2; i++)
                MPI.COMM_WORLD.Send(datos, 0, unitSize, MPI.DOUBLE, i, tag);
            
            for (int i = 1; i <= 2; i++) {
                 MPI.COMM_WORLD.Recv(res, 0, 1, MPI.DOUBLE, i, tag);
                if (i == 1) {
                    System.out.println ("La integral en [0, 1] de f es: " + res[0]);
                } else {
                    System.out.println ("La integral en [0, 1] de g es: " + res[0]);
                }
            }
        } else {
            MPI.COMM_WORLD.Recv(datos, 0, unitSize, MPI.DOUBLE, 0, tag);
            System.out.println ("Proceso slave " + rank + " ha recibido datos...");

            double desp = ((double)(Math.abs(datos[0] - datos[1]) / datos[2])), start = 0, end = desp, integralRes = 0;          

            for (int i = 0; i < datos[2]; i++) {
                integralRes += integral(start, end, rank);
                start = end;
                end = end + desp;
            }
            res[0] = integralRes;

            MPI.COMM_WORLD.Send(res, 0, 1, MPI.DOUBLE, 0, tag);
        }

        MPI.Finalize();
    }
}