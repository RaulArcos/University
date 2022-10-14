/**
 * tareaRunnableSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.util.Scanner;
import java.util.*;

public class tareaRunnableSeguro implements Runnable {

	private Critica c;
    private int tipoHilo;
    private Object obj;

    public tareaRunnableSeguro (Critica c, int h, Object obj) {
        this.c = c;
        this.tipoHilo = h; 
        this.obj = obj;  
    }
    
	public void run () {
        synchronized(obj){
            if (tipoHilo == 0) {
                for(int i = 0; i < 1000000; i++)
                    c.inc();
            } else {
                for(int i = 0; i < 1000000; i++) 
                    c.dec();
            }
        }
    }
}