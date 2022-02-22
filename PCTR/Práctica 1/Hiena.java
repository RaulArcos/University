package EntregaP1;

public class Hiena extends Carnivoros {
    public boolean agresiva ;
    public float peso ;
    public Boolean sexo ;
    
    public Hiena (int n , boolean a , int d , float p ,
    boolean f, Boolean ag, boolean s) {
    super (n , a , d, p, f) ;
    this.agresiva = a ;
    this.peso = p ;
    this.sexo = s ;
    }
}