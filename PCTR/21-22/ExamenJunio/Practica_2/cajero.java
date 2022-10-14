import java.util.Scanner;
import java.util.*;

public class cajero implements Runnable {
    private cuentaCorriente cuenta;
    private double dinero;

    public cajero (cuentaCorriente c, double d) {
        this.cuenta = c;
        this.dinero = d;
    }

    public void run() {
        Scanner s = new Scanner(System.in);
        System.out.println("Seleccione una opcion:\n [1] Mostrar saldo\n [2] Ingresar saldo\n [3] Retirar saldo\n ");
        int op = s.nextInt();

        switch (op){
            case 1:
                System.out.println("Saldo de la cuenta: " + cuenta.id() + " -> " + cuenta.saldo());
                break;
            case 2:
                System.out.println("Escriba el dinero que desee ingresar\n");
                dinero = s.nextDouble();
                System.out.println("Saldo resultante de la cuenta: " + cuenta.id() + " -> " + cuenta.ingresar(dinero));
                break;
            case 3:
                System.out.println("Escriba el dinero que desee retirar\n");
                dinero = s.nextDouble();
                System.out.println("Saldo resultante de la cuenta: " + cuenta.id() + " -> " + cuenta.retirar(dinero));
                break;
            default:
                System.out.println("Opcion incorrecta");
                break;
        }
    }
}