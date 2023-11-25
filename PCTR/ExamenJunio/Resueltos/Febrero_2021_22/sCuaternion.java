import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.*;

public class sCuaternion extends UnicastRemoteObject implements ICuaternion {
    public static int tam = 4;

    public sCuaternion() throws RemoteException {}

    public float[] sumCuaternion (float[] q1, float[] q2) throws RemoteException{
        float aux[] = new float[tam];
        for (int i = 0; i < tam; i++) aux[i] = q1[i] * q2[i];
        
        return aux;
    }

    public float[] conCuaternion (float[] q) throws RemoteException{
        float aux[] = new float[tam];
        aux[0] = q[0];
        for (int i = 1; i < tam; i++) aux[i] = q[i] * (-1);
        
        return aux;
    }

    public float[] xCuaternion (float[] q, float p) throws RemoteException{
        float aux[] = new float[tam];
        for (int i = 0; i < tam; i++) aux[i] = q[i] * p;
        
        return aux;
    }

    public float tCuaternion (float[] q) throws RemoteException{
        float aux = 0f;
        for (int i = 1; i < tam; i++) aux += q[i];

        return aux;
    }

    public static void main (String[] args) throws Exception{
        ICuaternion ObRemoto = new sCuaternion();

        Naming.rebind("//localhost:/cuaternion", ObRemoto);
    }
}