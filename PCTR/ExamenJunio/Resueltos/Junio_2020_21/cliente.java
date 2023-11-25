import java.rmi.Naming;
import java.rmi.RemoteException;
import java.util.Scanner;

public class cliente {
    private static interfaz in;
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        int op = 0;

        do {
            System.out.println("Elija una opcion:\n [1] Realizar la integral\n [2] Reiniciar");
            op = s.nextInt();

            if (op == 1) {
                System.out.println("Introduzca el numero de subintervalos: ");
                int intervalos = s.nextInt();
                try { in = (interfaz) Naming.lookup("//localhost:2020/ejercicio"); } catch (Exception e) {}
                float res = in.integral(intervalos);
                System.out.println("El resultado de la integral es: " + res);
            } else if (op == 2) {in.reinicio();}
        } while (op == 1 || op == 2);
        s.close();
    }
}
