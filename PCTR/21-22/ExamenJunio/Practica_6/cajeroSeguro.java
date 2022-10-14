/**
 * cajeroSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.util.Scanner;
import java.util.*;

public class cajeroSeguro implements Runnable {
    private cuentaCorrienteSeguro cuenta;
    private double dinero;
    private Object obj;

    public cajeroSeguro (cuentaCorrienteSeguro c, double d, Object obj) {
        this.cuenta = c;
        this.dinero = d;
        this.obj = obj;
    }

    public void run() {
        synchronized(obj){
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
}