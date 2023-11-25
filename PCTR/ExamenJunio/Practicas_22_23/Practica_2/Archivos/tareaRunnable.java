import java.util.Scanner;
import java.util.*;

public class tareaRunnable implements Runnable {

	private static int n = 0;
    private int tipoHilo;
    public tareaRunnable (int h) {
        this.tipoHilo = h;    
    }
    
	public void run () {
        if (tipoHilo == 0) {
            for(int i = 0; i < 1000000; i++) n++;
        } else {
            for(int i = 0; i < 1000000; i++) n--;
        }
    }

    public static int n() {
        return n;
    }
}