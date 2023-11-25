/**
 * algEisenbergMcGuire.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 12/11/2021
 */


public class algEisenbergMcGuire implements Runnable{
    private int tipoHilo;
    private static volatile int nVueltas = 10000;
    private static volatile int n = 0;

    static enum estado {restoproceso, quiereentrar, enSC};
    private volatile static int turn = 0;
    volatile static estado flag[] = new estado[2];

    public algEisenbergMcGuire (int tipoHilo) {
        this.tipoHilo = tipoHilo;
    }

    public void run(){
        switch (tipoHilo){
            case 0: {
                for (int j = 0; j < nVueltas; j++){
                    int indice;
                    do {
                        flag[tipoHilo] = estado.quiereentrar;
                        indice = turn;
                        while (indice != tipoHilo){
                            if (flag[indice] == estado.restoproceso) indice = turn;
                            else indice = (indice + 1) % 2;
                        }

                        flag[tipoHilo] = estado.enSC;
                        indice = 0;
                        while ((indice < 2) && ((indice == 0) || (flag[indice] != estado.enSC))) indice++;
                    } while ((indice >= 2) && ((turn == 0) || (flag[turn] == estado.restoproceso)));
                    
                    turn = tipoHilo;

                    n++;

                    indice = (turn + 1) % 2;

                    while (flag[indice] == estado.restoproceso) indice = (indice + 1) % 2;

                    turn = indice;
                    flag[tipoHilo] = estado.restoproceso;
                }
            } break;
            
            case 1: {
                for (int j = 0; j < nVueltas; j++){
                    int indice;
                    do {
                        flag[tipoHilo] = estado.quiereentrar;
                        indice = turn;
                        while (indice != tipoHilo){
                            if (flag[indice] == estado.restoproceso) indice = turn;
                            else indice = (indice + 1) % 2;
                        }

                        flag[tipoHilo] = estado.enSC;
                        indice = 0;
                        while ((indice < 2) && ((indice == 1) || (flag[indice] != estado.enSC))) indice++;
                    } while ((indice >= 2) && ((turn == 1) || (flag[turn] == estado.restoproceso)));
                    
                    turn = tipoHilo;

                    n--;

                    indice = (turn + 1) % 2;

                    while (flag[indice] == estado.restoproceso) indice = (indice + 1) % 2;

                    turn = indice;
                    flag[tipoHilo] = estado.restoproceso;
                }
            } break;
        }
    }

    /**
     * Main
     */
    public static void main (String[] args) throws InterruptedException {
        for (int i = 0; i < 2; i++) flag[i] = estado.restoproceso;
        
        Thread h1 = new Thread (new algEisenbergMcGuire(0));
        Thread h2 = new Thread (new algEisenbergMcGuire(1));

        h1.start(); h2.start();
        h1.join(); h2.join();

        System.out.println(n);
    }
        
}