import java.util.Scanner;

public class intDefinidaMonteCarlo {
    public static void main(String[] args){
        System.out.print("Introduce el numero de iteraciones: ");
        Scanner scan = new Scanner(System.in);
        int nIteraciones = scan.nextInt();
        scan.close();
        double contFx=0,contFsin=0;
        for(int i = 0; i < nIteraciones; i++){
            double coor_x =  Math.random();
            double coor_y =  Math.random();
            if(coor_y <= f_x(coor_x))
                contFx++;
            if(coor_y <= f_sin(coor_x))
                contFsin++;
        }
        System.out.println("Integral aproximada x = " + contFx/nIteraciones);
        System.out.println("Integral aproximada sin = " + contFsin/nIteraciones);
    }  
    public static double f_x(double x){
        return x;
    }
    public static double f_sin(double x){
        return Math.sin(x);
    }
}
