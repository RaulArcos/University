import java.rmi.*;
import java.rmi.registry.*;
import java.util.Random;

public class cPiMonteCarlo {
    public static void main (String[] args) throws Exception {
        iPiMonteCarlo RefObRemoto = (iPiMonteCarlo)Naming.lookup("//localhost/Servidor");
        
        RefObRemoto.masPuntos(10000);
    }
}
