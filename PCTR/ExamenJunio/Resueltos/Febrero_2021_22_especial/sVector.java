import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.*;

public class sVector extends UnicastRemoteObject implements IVector {
    public static int tam = 4;

    public sVector() throws RemoteException {}

    public float[] sumVector (float[] q1, float[] q2) throws RemoteException {
        float aux[] = new float[tam];
        for (int i = 0; i < tam; i++) aux[i] = q1[i] + q2[i]; 
        
        return aux;
    }

    public float pEscalVector (float[] q1, float[] q2) throws RemoteException {
        float aux = 0f;
        for (int i = 1; i < tam; i++) aux += (q1[i] + q2[i]);
        
        return aux;
    }

    public float[] xVector (float[] q, float p) throws RemoteException {
        float aux[] = new float[tam];
        for (int i = 0; i < tam; i++) aux[i] = q[i] * p;
        
        return aux;
    }

    public float trazaVector (float[] q) throws RemoteException {
        float aux = 0f;
        for (int i = 1; i < tam; i++) aux += q[i];

        return aux;
    }

    public static void main (String[] args) throws Exception{
        IVector ObRemoto = new sVector();

        Naming.rebind("//localhost:/vector", ObRemoto);
    }
}