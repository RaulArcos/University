import java.util.*;
import java.net.*;
import java.rmi.*;

public interface interfaz extends Remote {

    public float integral(int n) throws RemoteException;
    public void reinicio() throws RemoteException;
	
}