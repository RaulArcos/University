/**
 * @author Raúl Arcos Herrera
 */
public class forkMonitor 
{
    int fork[];

    public forkMonitor()
    {
        fork = new int[5];
        for(int i = 0; i < 5; i++)
            fork[i] = 2;
    }

    public synchronized void takeForks(int i)
    {
        while(fork[i] != 2)
            try
            {
                wait();
            }catch(InterruptedException e){} 
        
        if (rango(i)) 
        {
            fork [i+1] = fork [i+1]--;
            fork [i-1] = fork [i-1]--;
        }
        else
        {
            fork [0] = fork [0]--;
            fork [4] = fork [4]--;
        }
}
    public synchronized void releaseForks(int i)
    {
        if(rango(i))
        {
            fork[i+1] = fork[i+1]++;
            fork[i-1] = fork[i-1]--;
            if(fork[i+1] == 2 || fork[i-1] == 2)
                notifyAll();
        }
        else
        {
            fork[0] = fork[0]++;
            fork[4] = fork[4]--;
            if(fork[0] == 2 || fork[4] == 2)
                notifyAll();
        }
    }

    static boolean rango(int i)
    {
        boolean bool = true;
        if ((i-1) < 0 || (i+1) > 4)
            bool = false;
        return bool;
    }
}
