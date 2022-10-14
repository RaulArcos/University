public class algEinsenbergMcGuire implements Runnable{
    
    private int tipoHilo;
	private static volatile int nVueltas = 10000;
	private static volatile int n = 0;

	private volatile static int turno = 0;
    private volatile static int nHilos = 2;

    private static volatile estado indicador[] = new estado[nHilos];
    static enum estado {restoproceso, quiereentrar, esSC};

    public algEinsenbergMcGuire(int tipoHilo)
    {this.tipoHilo=tipoHilo;}

    public void run(){
        switch(tipoHilo){
          case 1:
            {
                int indice;
                for(int i=0; i<nVueltas; i++)
                {
                    do
                    {
                        indicador[0] = estado.quiereentrar;
                        indice = turno;

                        while(indice != 0)
                        {
                            if(indicador[0] != estado.restoproceso)
                                indice = turno;
                            else 
                                indice = (indice + 1) % nHilos;
                        }

                        indicador[0] = estado.esSC;

                        indice = 0;
                        
                        while( (indice < nHilos) && (indice == 0 || indicador[indice] != estado.esSC)){
                            indice ++;}
                    
                    }while(indice < nHilos || (turno != 0 && indicador[turno] != estado.restoproceso));

                    turno = 0;

                    n++;

                    indice = (turno + 1) % nHilos;

                    while(indicador[indice] == estado.restoproceso)
                        indice = (indice + 1) % nHilos;
                    
                    turno = indice;
                    indicador[0] = estado.restoproceso;
                }
            }break;
          case 2: 
            {
                int indice;
                for(int i=0; i<nVueltas; i++)
                {
                    do
                    {
                        indicador[1] = estado.quiereentrar;
                        indice = turno;

                        while(indice != 1)
                        {
                            if(indicador[1] != estado.restoproceso)
                                indice = turno;
                            else 
                                indice = (indice + 1) % nHilos;
                        }

                        indicador[1] = estado.esSC;

                        indice = 0;
                        while( (indice < nHilos) && (indice == 1 || indicador[indice] != estado.esSC)){indice++;}
                    
                    }while(indice < nHilos || (turno != 1 && indicador[turno] != estado.restoproceso));

                    turno = 1;

                    n--;

                    indice = (turno + 1) % nHilos;

                    while(indicador[indice] == estado.restoproceso)
                        indice = (indice + 1) % nHilos;
                    
                    turno = indice;
                    indicador[1] = estado.restoproceso;
                }
            }break;
        }
    }

    public static void main(String[] args) throws InterruptedException{
        
        Thread h1 = new Thread(new algEinsenbergMcGuire(1));
        Thread h2 = new Thread(new algEinsenbergMcGuire(2));
        
        h1.start(); h2.start();
        h1.join(); h2.join();
        System.out.println(n);
    }

    
}
