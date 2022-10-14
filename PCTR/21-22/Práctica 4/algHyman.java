public class algHyman implements Runnable{
    private int tipoHilo;
	private static volatile int nVueltas = 10000;
	private static volatile int n = 0;

    static volatile boolean C1 = false;
    static volatile boolean C2 = false;
    static volatile int turno = 0;

    public algHyman(int tipoHilo)
    {this.tipoHilo=tipoHilo;}

    public void run(){
        switch(tipoHilo){
          case 1:
            {
                for(int i=0; i<nVueltas; i++)
                {
                    C1 = true;
                    while(turno != 0)
                    {
                        while(C2 == true);
                        turno = 0;
                    }
                    n++;
                    C1 = false;
                }  
            }break;
          case 2: 
            {
                for(int i=0; i<nVueltas; i++)
                {
                    C2 = true;
                    while(turno != 1)
                    {
                        while(C1 == true);
                        turno = 1;
                    }
                    n--;
                    C2 = false;
                }
            }break;
        }
    }

    public static void main(String[] args) throws InterruptedException{
        
        Thread h1 = new Thread(new algHyman(1));
        Thread h2 = new Thread(new algHyman(2));
        
        h1.start(); h2.start();
        h1.join(); h2.join();
        System.out.println(n);
    }
}
