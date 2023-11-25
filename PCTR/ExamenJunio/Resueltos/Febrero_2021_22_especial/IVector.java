import java.util.*;
import java.net.*;
import java.rmi.*;
 
public interface IVector extends Remote{
    public float[] sumVector (float[] q1, float[] q2) throws RemoteException;
    public float pEscalVector (float[] q1, float[] q2) throws RemoteException;
    public float[] xVector (float[] q, float p) throws RemoteException;
    public float trazaVector (float[] q) throws RemoteException;
}