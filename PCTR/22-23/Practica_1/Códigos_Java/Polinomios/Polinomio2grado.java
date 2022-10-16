  import Polinomios.Monomio;
  public class Polinomio2grado {

  public static void main(String[] args) {
    //Para usar las clases de mi paquete podemos importarlas y usarlas...
    Monomio  m1 = new Monomio();
    //o bien, utilizar su nombre completo incluyendo el prefijo mipaquete...
    Polinomios.Monomio m2 = new Polinomios.Monomio(2, 5,5);
    System.out.println("El monomio m2 es de grado " + m2.Grado() + 
      " y de coeficiente " + m2.Coeficiente());
    }
  }
