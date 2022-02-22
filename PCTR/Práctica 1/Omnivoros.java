package EntregaP1;

public class Omnivoros extends Animal {
    public int nPatas ;
    public float peso ;
    public String especie ;
    
    public Omnivoros (int n , boolean a , int nP , float p ,
    String e) {
    super (n , a ) ;
    this.nPatas = nP ;
    this.peso = p ;
    this.especie = e ;
    }
}
