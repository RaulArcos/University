public class cuentaCorriente {

    //Constructor
    public cuentaCorriente(int cuenta, double saldo) 
    { 
		cuenta_ = cuenta; 
		saldo_ = saldo; 
    }

    //Observadores
    public int cuenta() { return cuenta_; }
    public double saldo() { return saldo_; }

    //Métodos de la clase
    public double ingresar() 
    {
        return saldo_++; 
    }
    public double retirar()
    { 
        return saldo_--; 
    }

    //Attibutos
    private int cuenta_;
    private static double saldo_;
}
