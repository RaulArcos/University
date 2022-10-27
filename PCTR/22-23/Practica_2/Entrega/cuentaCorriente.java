/**
 * cuentaCorriente.java
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class cuentaCorriente {
    /**
     * Constructor de la clase.
     * @param cuenta
     * @param saldo
     */
    public cuentaCorriente(int cuenta, double saldo) { 
		cuenta_ = cuenta; 
		saldo_ = saldo; 
    }
    /**
     * Método observador
     * @return El número de cuenta.
     */
    public int cuenta() { return cuenta_; }
    /**
     * Método Observador
     * @return El saldo de la cuenta.
     */
    public double saldo() { return saldo_; }

    /**
     * Ingresa 1 al saldo.
     * @return saldo + 1.
     */
    public double ingresar() {
        return saldo_++; 
    }
    /**
     * Decrementa 1 al saldo.
     * @return saldo - 1.
     */
    public double retirar(){ 
        return saldo_--; 
    }
    
    private int cuenta_;
    private static double saldo_;
}
