/**
 * @author Raúl Arcos Herrera
 */
public class monitorImpresion {

    Boolean libre[];
    int impresoras;

    public monitorImpresion(int nImpresoras)
    {
        impresoras = nImpresoras;
        libre = new Boolean[impresoras];
        for(int i = 0; i < impresoras; i++)
        {
            libre[i] = true;
        }
        
    }

    public synchronized int take_print()
    {
        while(impresoras == 0)
            try
            {
                wait();
            }catch(InterruptedException e){} 
        int aux = 0;
        while(!libre[aux])
            aux++;
        libre[aux] = false;
        impresoras--;
        return aux;
    }

    public synchronized void drop_print(int n)
    {
        libre[n] = true;
        impresoras++;
        notifyAll();
    }
}
