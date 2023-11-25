import java.util.concurrent.Callable;
public class tareaPrimos implements Callable{
   
  private final long linf;
  private final long lsup;
  private Long total = new Long(0);
   	
  public tareaPrimos(long linf, long lsup){
    this.linf = linf;
    this.lsup = lsup;
    System.out.println("Rango de analisis: "+"["+linf+"-"+lsup+"]");
  }
  
  public boolean esPrimo(long n){
    if(n<=1) return(false);
    for(long i=2; i<=Math.sqrt(n); i++)
      if(n%i == 0) return(false);
    return(true);
  }	
		
  public Long call(){   
    for(long i=linf; i<=lsup;i++)
      if(esPrimo(i)) total++;
  return(total);
  }
}
