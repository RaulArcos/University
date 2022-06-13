/**
 * usaDrakkarVikingo.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 2/12/2021
 */

import java.lang.Exception;

public class usaDrakkarVikingo extends Thread {
    public int tipoHebra;
    public drakkarVikingo vik;

    public usaDrakkarVikingo (int tH, drakkarVikingo vik) {
        this.tipoHebra = tH;
        this.vik = vik;
    }

    public void run (){
        switch (tipoHebra){
            case 0:
            for (int i = 0; i < 11; i++)
                vik.comer();
            break;
            case 1:
                vik.cocinar();
            break;
        }
    }

    public static void main (String[] args) throws Exception{
        drakkarVikingo vik = new drakkarVikingo(10);

        Thread h1 = new Thread (new usaDrakkarVikingo(0, vik));
        Thread h2 = new Thread (new usaDrakkarVikingo(1, vik));

        h1.start(); h2.start();
        h1.join(); h2.join();
    }
}
