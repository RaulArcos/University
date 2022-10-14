import java.util.Scanner;
import java.util.*;
import java.String;

public class jerarquiaClases {
    public class animal {
        public int nPatas;
        public boolean acuatico;
        
        public animal (int n, boolean a){
            this.nPatas = n;
            this.acuatico = a;
        }
    }
    
    public class carnivoro extends animal {
        public int nDientes;
        public float peso;
        public boolean felino;
        
        public carnivoro (int n, boolean a, int d, float p, boolean f){
            super (n, a);
            this.nDientes = d;
            this.peso = p;
            this.felino = f;
        }
    }
    
    public class herbivoro extends animal{
        public int nDientes;
        public float peso;
        public boolean mamifero;
        
        public herbivoro (int n, boolean a , int d, float p, boolean m){
            super (n, a);
            this.nDientes = d;
            this.peso = p;
            this.mamifero = m;
        }
    }

    public class omnivoro extends animal {
        public int nDientes;
        public float peso;
        
        public omnivoro (int n, boolean a, int d, float p){
            super (n, a);
            this.nDientes = d;
            this.peso = p;
        }
    }
    
    public class conejo extends herbivoro {
        public String raza;
        
        public conejo (int n, boolean a, int d, float p, boolean m, String r){
            super (n, a, d, p, m);
            this.raza = r;
        }
    }
    
    public class leon extends carnivoro {
        public String bioma;
        
        public leon (int n, boolean a, int d, float p, boolean f, String b){
            super (n, a, d, p, f);
            this.bioma = b;
        }
    }
    
    public class hiena extends carnivoro {
        public boolean carronero;
        
        public hiena (int n, boolean a, int d, float p, boolean f, boolean c){
            super (n, a, d, p, f);
            this.carronero = c;
        }
    }
    
    public class hombre extends omnivoro {
        public int DNI;
        public String sexo;
        public int edad;
        
        public hombre (int n, boolean a, int d, float p, int DNI, String s, int e){
            super (n, a, d, p);
            this.DNI = DNI;
            this.sexo = s;
            this.edad = e;
        }
    }
}
