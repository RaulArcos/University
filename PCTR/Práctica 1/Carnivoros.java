package EntregaP1;

public class Carnivoros extends Animal {
    public int nDientes ;
    public float peso ;
    public boolean felino ;
    
    public Carnivoros (int n , boolean a , int d , float p ,
    boolean f ) {
    super (n , a ) ;
    this.nDientes = d ;
    this.peso = p ;
    this.felino = f ;
    }
}