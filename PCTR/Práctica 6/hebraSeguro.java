public class hebraSeguro extends Thread
{
    private int tipohebra_; 
    private static int n=0; //variable de clase 
    private int nVueltas_;
    private Object lock_;
 
    public hebraSeguro(int nVueltas, int tipohebra, Object lock) 
    {
        nVueltas_ = nVueltas;
        tipohebra_ = tipohebra;
        lock_ = lock;
    } 
 
    public void run() 
    { 
    synchronized(lock_)
    {
        switch(tipohebra_)
        { 
            case 0: for(int i=0; i<nVueltas_; i++)n++; break; 
            case 1: for(int i=0; i<nVueltas_; i++)n--; break; 
        } 
    }
 
    } 
    
    public static int ejecutar() throws Exception
    {
        Object lock = new Object();
        hebraSeguro p = new hebraSeguro(1000000, 0,lock); 
        hebraSeguro q = new hebraSeguro(1000000, 1,lock); 
        p.start(); 
        q.start(); 
        p.join(); 
        q.join();
 
        return n;
    }    
}
