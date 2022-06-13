/**
 * usalectorEscritor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 2/12/2021
 */

public class usalectorEscritor extends Thread{
    public int tipoHebra;
    public lectorEscritor le;

    public usalectorEscritor(int tH, lectorEscritor le) {
        this.tipoHebra = tH;
        this.le = le;
    }

    public void run (){
        try {
            switch (tipoHebra){
                case 0:
                    le.StartRead();
                    sleep(100);
                    le.EndRead();
                break;
                case 1:
                    le.StartWrite();
                    sleep(100);
                    le.EndWrite();
                break;
            }
        } catch (InterruptedException e) {}
    }

    public static void main (String[] args) throws Exception{
        lectorEscritor le = new lectorEscritor();

        Thread h1 = new Thread (new usalectorEscritor(0, le));
        Thread h2 = new Thread (new usalectorEscritor(0, le));
        Thread h3 = new Thread (new usalectorEscritor(1, le));
        Thread h4 = new Thread (new usalectorEscritor(1, le));

        h1.start(); h2.start(); h3.start(); h4.start();
        h1.join(); h2.join(); h3.join(); h4.join();
    }
}
