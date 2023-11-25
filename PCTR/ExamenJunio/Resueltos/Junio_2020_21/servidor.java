import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Random;

public class servidor extends UnicastRemoteObject implements interfaz {
    Random r = new Random();

    public servidor () throws RemoteException {}

    static Float f(double x) {return (float) (Math.pow(x, 2));}

    public float integral(int n) throws RemoteException {
        double a = 0, b = 1, tam = (double)(b - a) / n;
		float sol = 0;

		b = b / n;

		for (int i = 0; i < n; i++) {
			sol += (b - a) * f((a + b) / 2);
			a = b;
			b += tam;
		}

		return sol;
    }

    public void reinicio() throws RemoteException {
        int a = r.nextInt(10) + 1;
		integral(a);
    }

    public static void main(String[] args) throws Exception {
        try {
            interfaz in = new servidor();

            LocateRegistry.createRegistry(2020);

            Naming.rebind("//localhost:2020" + "/ejercicio", in);
        } catch (Exception e) {}
    }
}
