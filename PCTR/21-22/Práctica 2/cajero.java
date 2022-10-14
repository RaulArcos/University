public class cajero implements Runnable {

    //Constructor 
    public cajero(cuentaCorriente cc, double cantidad,int opcion) 
    {
    	cc_ = cc;
    	n_ = cantidad;
    	op_ = opcion;
    }

	//Atributos
	private cuentaCorriente cc_;
	private double n_;
	private int op_;

    public void run()
    {
      switch(op_)
      {
		  case 1: for(int i= 0; i < n_; i++) cc_.ingresar(); break;
		  case 2: for(int i= 0; i < n_; i++) cc_.retirar(); break;
      }
    }
}
