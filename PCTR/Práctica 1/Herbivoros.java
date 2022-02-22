package EntregaP1;

public class Herbivoros extends Animal {
    public float altura ;
    public float peso ;
    public String especie ;
    
    public Herbivoros (int n , boolean a , float alt , float p ,
    String e) {
    super (n , a ) ;
    this.altura = alt ;
    this.peso = p ;
    this.especie = e ;
    }
}