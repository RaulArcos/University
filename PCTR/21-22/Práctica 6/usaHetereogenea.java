/**
 * @author Raúl Arcos Herrera
 * 
*/
public class usaHetereogenea extends Thread
{
    public static int nHebras = 10;
    private hetereogenea hete_ = new hetereogenea();
    private int m_;

    usaHetereogenea(hetereogenea h,int metodo)
    {
        this.hete_ = h;
        this.m_ = metodo;
    }

    public void run()
    {  
        switch(m_)
        {
            case 0: for(int i = 0; i < 10000; i++) hete_.aumento_synchronized(); break;
            case 1: for(int i = 0; i < 10000; i++) hete_.aumento_unsynchronized(); break;
            default: 
        }   
    }
    public static void main(String[] args) throws Exception
    {
        hetereogenea hete = new hetereogenea();

        for(int i = 0; i < 10000; i++)
        {
        }
       
        Thread[] hilos = new Thread[nHebras];
        for(int i = 0; i < nHebras; i++) 
            hilos[i] = new usaHetereogenea(hete,i%2);
        
        for(int i = 0; i < nHebras; i++)
            hilos[i].start();
        for(int i = 0; i < nHebras; i++)
            hilos[i].join();
    

        System.out.println("Resultado Synchronized = " + hetereogenea.n);
        System.out.println("Resultado UnSynchronized = " + hetereogenea.m);
    }


}
