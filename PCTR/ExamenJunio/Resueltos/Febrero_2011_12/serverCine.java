import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.*;

public class serverCine
    extends UnicastRemoteObject
    implements iCine

{
    public boolean sala1[][] = new boolean[100][100];
    public boolean sala2[][] = new boolean[100][100];
    public boolean sala3[][] = new boolean[100][100];
    public boolean sala4[][] = new boolean[200][200];
    
    public serverCine()
	throws RemoteException
    {}

    public boolean reservar(int pelicula, int fila, int asiento)
	throws RemoteException
    {
	switch(pelicula) {
	case 1:
	    if(sala1[fila][asiento] == false) {
		sala1[fila][asiento] = true;
		return true;
	    }
	    else
		return false;
	    
	case 2:
	    if(sala2[fila][asiento] == false) {
		sala2[fila][asiento] = true;
		return true;
	    }
	    else
		return false;
	case 3:
	    if(sala3[fila][asiento] == false) {
		sala3[fila][asiento] = true;
		return true;
	    }
	    else
		return false;
	case 4:
	    if(sala4[fila][asiento] == false) {
		sala4[fila][asiento] = true;
		return true;
	    }
	    else
		return false;

	default:
	    System.out.println("Pelicula incorrecta");
	    break;
	}

	return false;
    }

    public static void main(String[] args)
	throws Exception
    {
	iCine ObRemoto = new serverCine();

	LocateRegistry.createRegistry(2020);

	Naming.rebind("//localhost:2020/cine", ObRemoto);
    }
}
