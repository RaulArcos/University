public class algDekker extends Thread{
    private int tipoHilo;
	private static volatile int nVueltas = 10000;
	private static volatile int n = 0;
	private static volatile boolean C1 = false;
	private static volatile boolean C2 = false;
    private static volatile int turn = 1;

    public algDekker(int tipoHilo)
    {this.tipoHilo=tipoHilo;}

    public void run(){
      switch(tipoHilo){
        case 1:{for(int i=0; i<nVueltas; i++){
                    C1 = true;
                    while(C2 == true)
                    {
                        if(turn == 2)
                        {
                            C1 = false;
                            while(turn == 2);
                            C1 = true;
                        }
                    }
                    n++;
                    turn = 2;
                    C1 = false;
        	      
        	    }
        	    break;}
        case 2: {for(int i=0; i<nVueltas;i++){
        	      C2 = true;
                  while(C1 == true)
                    {
                        if(turn == 1)
                        {
                            C2 = false;
                            while(turn == 1);
                            C2 = true;
                        }
                    }
        	        n--;
                  turn = 1;
        	      C2 = false;
                }
        	    }break;
      }
    }

    public static void main(String[] args) throws InterruptedException{
      algDekker h1 = new algDekker(1);
      algDekker h2 = new algDekker(2);
      h1.start(); h2.start();
      h1.join(); h2.join();
      System.out.println(n);
    }
}
