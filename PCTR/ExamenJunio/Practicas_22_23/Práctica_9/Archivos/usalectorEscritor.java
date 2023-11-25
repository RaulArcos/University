/**
 * usalectorEscritor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 14/12/2022
 */

public class usalectorEscritor extends Thread {
    public int tipoHebra;
    public static long data = 0;
    public lectorEscritor le;
    public recurso r;

    public usalectorEscritor(int tH, lectorEscritor le, recurso r) {
        this.tipoHebra = tH;
        this.le = le;
        this.r = r;
    }

    public void run (){
        try {
            switch (tipoHebra){
                case 0:
                    for (long i = 0; i < 1000000; i++) {
                        le.iniciaLectura();
                        data = r.observer();
                        le.acabarLectura();
                    }
                break;
                case 1:
                    for (long i = 0; i < 1000000; i++) {                    
                        le.iniciarEscritura();
                        r.inc();
                        le.acabarEscritura();
                    }
                break;
            }
        } catch (Exception e) {}
    }

    public static void main (String[] args) throws Exception{
        lectorEscritor le = new lectorEscritor();
        recurso r = new recurso();

        Thread h1 = new Thread (new usalectorEscritor(0, le, r));
        Thread h2 = new Thread (new usalectorEscritor(1, le, r));
        Thread h3 = new Thread (new usalectorEscritor(0, le, r));
        Thread h4 = new Thread (new usalectorEscritor(1, le, r));

        h1.start(); h2.start(); h3.start(); h4.start();
        h1.join(); h2.join(); h3.join(); h4.join();

        System.out.println(data);
    }
}
