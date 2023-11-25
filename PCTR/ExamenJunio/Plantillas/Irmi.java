//start rmiregistry
//java servidor &
//java cliente

import java.util.*;
import java.net.*;
import java.rmi.*;

public interface Irmi extends Remote {
    // Cabeceras de funciones
    public boolean reservar(int pelicula, int fila, int asiento) throws RemoteException;
}