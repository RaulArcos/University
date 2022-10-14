package EntregaP1;

public class Hombre extends Omnivoros {
    public boolean sexo;
    public float peso ;
    public String raza ;
    
    public Hombre (int n , boolean a , int nP , float p ,
    String e,boolean s, String r) {
    super (n , a , nP , p, e) ;
    this.sexo = s ;
    this.peso = p ;
    this.raza = r ;
    }
}