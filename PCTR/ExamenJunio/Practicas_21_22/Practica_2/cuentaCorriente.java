import java.util.Scanner;
import java.util.*;

public class cuentaCorriente {
    private int id;
    private double saldo;
    
    public cuentaCorriente (int i, double s) {
        this.id = i;
        this.saldo = s;
    }

    public int id() {return id;}
    public double saldo () {return saldo;}

    public double ingresar (double n) { return this.saldo + n;}
    public double retirar (double n) { return this.saldo - n;}
}