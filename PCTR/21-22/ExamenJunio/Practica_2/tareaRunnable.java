import java.util.Scanner;
import java.util.*;

public class tareaRunnable implements Runnable {

	private Critica c;
    private int tipoHilo;
    public tareaRunnable (Critica c, int h) {
        this.c = c;
        this.tipoHilo = h;    
    }
    
	public void run () {
        if (tipoHilo == 0) {
            for(int i = 0; i < 1000000; i++)
                c.inc();
        } else {
            for(int i = 0; i < 1000000; i++) 
                c.dec();
        }
    }
}