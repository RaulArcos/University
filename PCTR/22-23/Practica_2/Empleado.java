/**
 * Esta clase contiene los atributos y metodos de un empleado
 * @author El Tato...
 * @version 2222.0
 * @see Persona
 */
public class Empleado{
    
    private int numeroEmpleado;
    private String departamento;
    private String puesto;
    
    /**
     * Metodo constructor por defecto
     */
    public Empleado(){
    }
    
    /**
     * Metodo constructor parametrizado
     * @param nombre Nombre del empleado
     * @param edad Edad del empleado
     * @param sexo Sexo del empleado en formato H o M
     * @param numeroEmpleado Numero de empleado
     * @param departamento Departamento donde trabajara el empleado
     * @param puesto Puesto que ocupara el empleado dentro de la empresa
     */
    public Empleado(String nombre, 
                    int edad, 
                    char sexo, 
                    int numeroEmpleado, 
                    String departamento, 
                    String puesto){
        super(nombre, edad, sexo);
        this.numeroEmpleado = numeroEmpleado;
        this.departamento = departamento;
        this.puesto = puesto;
    }
    
    /**
     * Metodo para regresar el numero de empelado
     * @return Regresa el numero del empleado
     */
    public int getNumeroEmpleado() {
        return numeroEmpleado;
    }
    
}