import java.util.Scanner;

public class intDefinidaMonteCarlo {
    public static void main(String[] args){
        System.out.print("Introduce el número de iteraciones: ");
        Scanner scan = new Scanner(System.in);
        int nIteraciones = scan.nextInt();
        double contFx=0,contFsin=0;
        for(int i = 0; i < nIteraciones; i++){
            
        }
    }  

    public static double f_x(double x){
        return x;
    }
    public static double f_sin(double x){
        return Math.sin(x);
    }
}
