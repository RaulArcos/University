  package Polinomios;

  public class Monomio {
    private int grado;
    private double coeficiente;
    public Monomio() {}
    public Monomio(int gr, double coef) {
      grado = gr;
      coeficiente = coef;
    }
    public int Grado() {return grado;}
    public double Coeficiente() {return coeficiente;}
  }
