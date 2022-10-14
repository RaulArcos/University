/**
 * @author Raul Arcos Herrera
 */

public class usaDrakkarVikingo 
{
    public boolean co;
    public drakkarVikingo drak;

    public usaDrakkarVikingo(boolean co, drakkarVikingo drak){this.drak = drak; this.co = co;}

    public void run()
    {
        switch(co)
        {
            case true: drak.cocinar(); break;
            case false: drak.comer(); break;
        }
    }
    public static void main(String[] args) throws Exception
    {
        drakkarVikingo drak = new drakkarVikingo();
        usaDrakkarVikingo A = new usaDrakkarVikingo(m, true);
        usaDrakkarVikingo B = new usaDrakkarVikingo(m, false);

        A.start(); A.join();
        B.start(); B.join();
        
        
    
    }
}
