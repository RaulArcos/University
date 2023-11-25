import java.util.Scanner;
import java.util.*;

public class hebra extends Thread {
    private int tipoHilo;
    private static int n =0; // variable de clase
    private int nVueltas;

    public hebra (int nVueltas , int tipoHilo ) { 
        this.nVueltas = nVueltas; 
        this.tipoHilo = tipoHilo;
    }

    public void run () {
        switch (tipoHilo) {
            case 0: 
                for (int i = 0; i < nVueltas; i ++) 
                    n++; 
                break ;
            case 1:
                for (int i = 0; i < nVueltas; i ++) 
                    n--;
                break ;
        }
    }

    public static int n() {
        return n;
    }

}