import mpi.*;
public class ejInutil{

  public static void main(String args[]) throws Exception {
    MPI.Init(args);
    int me = MPI.COMM_WORLD.Rank();
    int size = MPI.COMM_WORLD.Size();
    System.out.println("Soy el proceso <"+me+">");
    MPI.Finalize();
  }
} 