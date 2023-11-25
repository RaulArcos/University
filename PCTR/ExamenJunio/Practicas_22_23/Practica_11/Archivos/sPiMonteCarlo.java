import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.Random;

public class sPiMonteCarlo extends UnicastRemoteObject implements iPiMonteCarlo{
    private static int numPuntos = 0;

    public sPiMonteCarlo() throws RemoteException{}

    public void reset() throws RemoteException {
        numPuntos = 0;
    }
    
    public void masPuntos(int nPuntos)  throws RemoteException {
        numPuntos = numPuntos + nPuntos;
    }

    public double aproxActual() throws RemoteException {
        double coordX = 0.0, coordY = 0.0;
        int contPi = 0;
        Random r = new Random();

        for (int i = 0; i < numPuntos; i++){
            coordX = r.nextDouble();
            coordY = r.nextDouble();
            if ((Math.sqrt(Math.pow(coordX, 2) + Math.pow(coordY, 2))) <= 1.0)
                contPi++;
        }
        
        return (double)(contPi/numPuntos);
    }

    public static void main (String[] args) throws Exception {
        sPiMonteCarlo ORemoto = new sPiMonteCarlo();

        Naming.rebind("Servidor", ORemoto);
        System.out.println("Servidor Remoto Preparado");

        ORemoto.reset();
    }
}
