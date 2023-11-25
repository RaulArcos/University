import java.rmi.*;
import java.rmi.registry.*;
import java.util.Random;

public class cBonoLoto {
    public static void main(String[] args) throws Exception{
      int apuesta[] = new int[6];
      Random r = new Random();  

      for (int i = 0; i < 6; i++)
        apuesta[i] = r.nextInt(50);;
      
      iBonoLoto RefObRemoto =  (iBonoLoto)Naming.lookup("//localhost/Servidor");
                  
      if (RefObRemoto.compApuesta(apuesta))
        System.out.println ("Has acertado");
      else
        System.out.println ("Has perdido");
        
      RefObRemoto.resetServidor();
    }
}
