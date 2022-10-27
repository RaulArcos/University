/**
 * tareaRunnable.java
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class tareaRunnable extends Thread{   
    private Critica c;
    private int tipoHilo; 
    /**
     * tareaRunnable
     * @param c
     * @param tipo
     */
    public tareaRunnable(Critica c, int tipo){
        this.c=c;
        tipoHilo = tipo;
    }

    public void run(){
        switch(tipoHilo){ 
            case 0: for(int i=0; i<1000000; i++)c.inc(); break; 
            case 1: for(int i=0; i<1000000; i++)c.dec(); break; 
          } 
    }
}

