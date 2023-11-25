import java.rmi.*;
import java.rmi.registry.*;
import java.util.Scanner;

public class cBonoLoto {
    public static void main(String[] args) throws Exception{
      int apuesta[] = new int[6];
      Scanner s = new Scanner(System.in);

        for (int i = 0; i < 6; i++) {
          System.out.println("Introduzca el numero " + (i + 1) + ": ");
          apuesta[i] = s.nextInt();
        }
      
      iBonoLoto RefObRemoto = (iBonoLoto)Naming.lookup("//localhost/Servidor");
      
      RefObRemoto.resetServidor();

      if (RefObRemoto.compApuesta(apuesta))
        System.out.println ("Has acertado");
      else
        System.out.println ("Has perdido");
        
      RefObRemoto.resetServidor();
    }
}
