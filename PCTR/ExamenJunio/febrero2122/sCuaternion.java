import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;
import java.util.*;

public class sCuaternion extends UnicastRemoteObject implements ICuaternion {
    // Constructor
    public sCuaternion() throws RemoteException {
    }

    public float[] sumCuaternion(float[] q1, float[] q2) throws RemoteException{
        if()
    }

    public float[] conCuaternion(float[] q1) throws RemoteException {

    }

    public float[] xCuaternion(float[] q, float[] p) throws RemoteException {

    }

    public float[] tCuaternion(float[] q) throws RemoteException {

    }

    public static void main(String[] args) throws Exception {
        ICuaternion ObRemoto = new sCuaternion();

        // Si el puerto NO es el predeterminado
        LocateRegistry.createRegistry(2020);

        // siendo "cine" cualquier referencia
        Naming.rebind("//localhost:2020/cine", ObRemoto);

        // Si el puerto ES EL PREDETERMINADO
        Naming.rebind("//localhost:/cine", ObRemoto);
    }
}
