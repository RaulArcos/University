import java.rmi.*;
import java.util.*;

public class clientCine
{
    public static void main(String[] args)
	throws Exception
    {
	iCine RefObRemoto = (iCine) Naming.lookup("//localhost:2020/cine");
	Scanner s = new Scanner(System.in);

	boolean finish = false;

	System.out.println("Bienvenido a los cines LOS MUERTOS DE TOMEU, elige una pelicula:\n   1)COMO MATAR A TOMEU\n   2)DESPELLEJANDO A TOMEU\n   3)A LOS COCODRILOS CON TOMEU\n   4)MUERTE A TOMEU");
	int op = s.nextInt();

	if(op > 4 || op < 1)
	    System.out.println("La pelicula indicada no existe");
	else {

	    while(!finish) {
		System.out.println("Introduce una fila: ");
		int f = s.nextInt();
		
		System.out.println("Introduce un asiento: ");
		int a = s.nextInt();
		
		if(RefObRemoto.reservar(op, f, a)) {
		    System.out.println("Reservado con exito!");
		    finish = true;
		}
		else {
		    System.out.println("Asientos no disponibles.");
		    finish = false;
		}
	    }
	}
    }   
}