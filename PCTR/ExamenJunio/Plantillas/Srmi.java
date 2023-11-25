import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.*;

public class Srmi extends UnicastRemoteObject implements Irmi {
    //Constructor
    public serverCine() throws RemoteException {}

    //Declaracion de funciones
    public boolean reservar(int pelicula, int fila, int asiento) throws RemoteException {

    }

    public static void main(String[] args) throws Exception {
        Irmi ObRemoto = new Srmi();

        //Si el puerto NO es el predeterminado
            LocateRegistry.createRegistry(2020);

            //siendo "cine" cualquier referencia
            Naming.rebind("//localhost:2020/cine", ObRemoto);

        //Si el puerto ES EL PREDETERMINADO
            Naming.rebind("//localhost:/cine", ObRemoto);
    }
}
