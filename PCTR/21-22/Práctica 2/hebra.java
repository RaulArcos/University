/**
 * hebra.java crea dos objetos hebra con el número de iteraciones y el tipo, dependiendo de este el objeto suma o resta dentro de una variable compartida en su método run.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class hebra extends Thread { 
    private int tipohebra; 
    private static int n=0; //variable de clase 
    private int nVueltas;

    /**
     * @param nVueltas
     * @param tipohebra
     */
    public hebra(int nVueltas, int tipohebra) 
    {this.nVueltas=nVueltas; this.tipohebra=tipohebra;} 

    public void run() { 
      switch(tipohebra){ 
        case 0: for(int i=0; i<nVueltas; i++)n++; break; 
        case 1: for(int i=0; i<nVueltas; i++)n--; break; 
      }
    } 
    
    /**
     * @return la variable compartida n.
     * @throws Exception
     */
    public static int ejecutar() throws Exception{
        hebra p = new hebra(1000000, 0); 
        hebra q = new hebra(1000000, 1); 
        p.start(); 
        q.start(); 
        p.join(); 
        q.join();
 
        return n;
    }
}

