package EntregaP1;

public class Conejo extends Herbivoros {
    public String raza ;
    public float peso ;
    public String color ;
    
    public Conejo (int n , boolean a , float alt , float p ,
    String e, String r, String c) {
    super (n , a , alt, p, e);
    this.peso = p ;
    this.raza = r ;
    this.especie = e ;
    }
}