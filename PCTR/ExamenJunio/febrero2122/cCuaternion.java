import java.rmi.*;
import java.util.*;

public class cCuaternion {
    public static void main(String[] args) throws Exception {
        // Objeto de la interfaz, siendo "cine" el mismo nombre que el del servidor
        ICuaternion RefObRemoto = (ICuaternion) Naming.lookup("//localhost:2020/cine");

        // Imprimir aquello q quieres que vea el cliente

        // Llamar a las funciones asi:
        RefObRemoto.funcionInterfaz();
    }
}