import java.util.*;
import java.net.*;
import java.rmi.*;

public interface iCine
    extends Remote
{
    public boolean reservar(int pelicula, int fila, int asiento)
	throws RemoteException;
}