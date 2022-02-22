/**
 * @author Raul Arcos Herrera
 */

public class drakkarVikingo extends Thread
{
	private int marmita;
	
	public drakkarVikingo() {marmita = 5; }
	
	public synchronized void comer() {
        while(true){
            while (marmita == 0) 
			{
                notifyAll();
                try 
				{
                    wait();
                } catch (InterruptedException ex) {
                }
            }
            marmita--;
        }
    }

	public synchronized void cocinar() {
        while(true){
            while (marmita != 0)
				try 
				{
					wait();
				} catch (InterruptedException ex) {}
    
            marmita = 5;
            notifyAll();
        }
    }
}