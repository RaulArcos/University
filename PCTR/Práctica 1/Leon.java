package EntregaP1;

public class Leon extends Carnivoros {
    public String Zona ;
    public float peso ;
    public Boolean sexo ;
    
    public Leon (int n , boolean a , int d , float p ,
    boolean f, String z, boolean s) {
    super (n , a , d, p, f) ;
    this.Zona = z ;
    this.peso = p ;
    this.sexo = s ;
    }
}