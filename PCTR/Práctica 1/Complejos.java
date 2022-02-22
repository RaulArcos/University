package EntregaP1;
public class Complejos
{
    
   private double real_;
   private double imag_;

   //Constructor por omisión
    public Complejos()
    {
        real_ = 0;
        imag_ = 0;
    }
   //Constructor de un número complejo
    public Complejos(double r, double i)
    {
        real_ = r;
        imag_ = i;
    }

    public static Complejos sumaComplejos(Complejos c1, Complejos c2)
    {
        c1.real_ = c1.real_ + c2.real_;
        c1.imag_ = c1.imag_ + c2.imag_;

        return c1;
    }
   
    public static Complejos restaComplejos(Complejos c1, Complejos c2)
    {
        c1.real_ = c1.real_ + c2.real_;
        c1.imag_ = c1.imag_ + c2.imag_;

        return c1;
    }

    public static Complejos producto(Complejos c1, Complejos c2)
    {
        c1.real_ = c1.real_*c2.real_-c1.imag_*c2.imag_;
        c1.imag_ = c1.real_*c2.imag_+c1.imag_*c2.real_;
        
        return c1;
    }

    public static double modulo(Complejos c1)
    {
        return Math.sqrt(c1.real_*c1.real_+c1.imag_*c1.imag_);
    }

    public static Complejos cociente(Complejos c1, Complejos c2)
    {
        double aux;
        if(modulo(c2)==0.0){
           return new Complejos();
        }else{
             aux=c2.real_*c2.real_+c2.imag_*c2.imag_;
             c1.real_=(c1.real_*c2.real_+c1.imag_*c2.imag_)/aux;
             c2.imag_=(c1.imag_*c2.real_-c1.real_*c2.imag_)/aux;
        }
        return c1;
    }

    public static String imprimeComplejos(Complejos c1)
    {   
        if(c1.imag_ >= 0)
        {
            return c1.real_ + " + " + c1.imag_ + "i" ;
        }
        else
        {
            return c1.real_ +" "+  c1.imag_ + "i";
        }
    }
}
