/**
 * Loteria.java
 * @author Raúl Arcos Herrera, 77175935X
 * @version 17/06/2022
 * 
 * COMPILACIÓN: javac -cp .;%MPJ_HOME%/lib/mpj.jar Loteria.java
 * EJECUCIÓN: mpjrun.bat -np 5 Loteria  
 * VALOR DE -np = 5 (1 máster y 4 jugadores)
 */



import mpi.*;
import java.util.Random;

public class Loteria {
    public static void main(String args[]) throws Exception {
        MPI.Init(args);
        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();
        int master = 0; //Definimos que el master va a ser el número 0.
        int tag = 100; int unitSize = 1; 
        Random r = new Random();

        if(rank == master){ //Código del Master
            int bufer[] = new int[unitSize];
            int result[] = new int[unitSize];
            int ganador=0,nSecreto;
            nSecreto = r.nextInt(100); //Master saca un número de 0 a 100
            System.out.println("Numero secreto: " + nSecreto); //El master Imprime el número a adivinar.
            while(ganador==0){
                for(int i = 1; i < size; ++i){ //Recibimos un dato por cada cliente.
                    MPI.COMM_WORLD.Recv(bufer, 0, unitSize, MPI.INT, i, tag+i); 
                    System.out.println("Proceso " + i + " juega con el numero " + bufer[0]); //Imprimimos por pantalla el proceso y el número de su apuesta
                    if(bufer[0] == nSecreto){ //Si el número que ha apostado el proceso es el secreto, pasa a ser el ganador.
                        ganador = i;
                    }
                }
                if(ganador == 0){ //Si una vez comprobadas todas las apuestas ninguno ha ganado, Enviamos un 0 a cada jugador para iniciar una nueva ronda.
                    System.out.println("No hay ganador, repetimos ronda.");
                    result[0] = 0;
                    for(int i = 1; i < size; ++i){ //Enviamos el valor 0 a cada jugador
                        MPI.COMM_WORLD.Send(result, 0, unitSize, MPI.INT, i, tag+i); //Si no hay ganador, enviamos 0 a todas los jugadores.
                    }   
                }else{
                    System.out.println("El proceso " + ganador + " gana el juego."); //Si tenemos un ganador, lo imprimimos por pantalla y enviamos el numero secreto.
                    result[0] = nSecreto;                                            
                    for(int i = 1; i < size; ++i){
                        MPI.COMM_WORLD.Send(result, 0, unitSize, MPI.INT, i, tag+i); //Envio de numero secreto a todos los jugadores (Indicador de que se ha acabado el juego).
                    } 
                }
            }

            

        }else{ //Código de cualquiera de los jugadores/slaves
            int bufer[] = new int[unitSize];
            int result[] = new int[unitSize];
            bufer[0] = r.nextInt(100); //El jugador realiza su apuesta.
            MPI.COMM_WORLD.Send(bufer, 0, unitSize, MPI.INT, master, tag+rank); //Envía su apuesta al servidor.
            MPI.COMM_WORLD.Recv(result, 0, unitSize, MPI.INT, master, tag+rank); //Recibe la respuesta al servidor (0 si nadie ha ganado o el número secreto si alguien ha ganado.)
            while(result[0] == 0){ //Mientras nadie haya ganado.
                bufer[0] = r.nextInt(100); //Repetimos otra apuesta.
                MPI.COMM_WORLD.Send(bufer, 0, unitSize, MPI.INT, master, tag+rank); //Enviamos de nuevo nuestra apuesta.
                MPI.COMM_WORLD.Recv(result, 0, unitSize, MPI.INT, master, tag+rank);//Recibimos el resultado por parte del servidor (0 si nadie ha ganado o el número secreto si alguien ha ganado.)
            }
        }
        MPI.Finalize();
    }
    
}
