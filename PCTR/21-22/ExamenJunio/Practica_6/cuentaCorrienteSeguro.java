/**
 * cuentaCorrienteSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

public class cuentaCorrienteSeguro {
    private int id;
    private double saldo;
    private Object obj;
    
    public cuentaCorrienteSeguro (int i, double s, Object obj) {
        this.id = i;
        this.saldo = s;
        this.obj = obj;
    }

    public int id() {return id;}
    public double saldo () {return saldo;}

    public double ingresar (double n) { return this.saldo + n;}
    public double retirar (double n) { return this.saldo - n;}
}