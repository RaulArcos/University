  package Polinomios;

  public class Prueba {
    public static void main(String[] args) {
      //Uso de clases amigas.
      Polinomio p = new Polinomio();
      Monomio m = new Monomio(2, 3.75);
      System.out.print("El monomio de grado " + m.Grado() + " tiene coeficiente " + m.Coeficiente());
    }
  }

