import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.Random;

public class sBonoLoto extends UnicastRemoteObject implements iBonoLoto {
    public int apuestaGanadora[] = new int[6];

    public void resetServidor() throws RemoteException{
        Random r = new Random();

        for (int i = 0; i < 6; i++)
            apuestaGanadora[i] = r.nextInt(50);
    }
    public boolean compApuesta(int[] apuesta)  throws RemoteException{
        for (int i = 0; i < 6; i++){
            if (apuesta[i] != apuestaGanadora[i])
                return false;
        }
        return true;
    }

    public sBonoLoto() throws RemoteException{
        Random r = new Random();  

        for (int i = 0; i < 6; i++)
            apuestaGanadora[i] = r.nextInt(50);;
    } 

    public static void main(String[] args) throws Exception{
        sBonoLoto ORemoto = new sBonoLoto();
        
        Naming.bind("Servidor", ORemoto);
        System.out.println("Servidor Remoto Preparado");
    }	
}
