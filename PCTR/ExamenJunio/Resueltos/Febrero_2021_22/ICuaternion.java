import java.util.*;
import java.net.*;
import java.rmi.*;
 
public interface ICuaternion extends Remote{
    public float[] sumCuaternion (float[] q1, float[] q2) throws RemoteException;
    public float[] conCuaternion (float[] q) throws RemoteException;
    public float[] xCuaternion (float[] q, float p) throws RemoteException;
    public float tCuaternion (float[] q) throws RemoteException;
}