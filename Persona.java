public class Persona {
    // Atributos
    private String nombre;
    private int edad;
    private String genero;
    private String direccion;
    private String ciudad;
    private String profesion;
    private String estadoCivil;
    private String telefono;
    private String email;
    private String nacionalidad;

    // Constructor
    public Persona(String nombre, int edad, String genero, String direccion, String ciudad,
                   String profesion, String estadoCivil, String telefono, String email, String nacionalidad) {
        this.nombre = nombre;
        this.edad = edad;
        this.genero = genero;
        this.direccion = direccion;
        this.ciudad = ciudad;
        this.profesion = profesion;
        this.estadoCivil = estadoCivil;
        this.telefono = telefono;
        this.email = email;
        this.nacionalidad = nacionalidad;
    }

    // Métodos getters y setters
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public String getProfesion() {
        return profesion;
    }

    public void setProfesion(String profesion) {
        this.profesion = profesion;
    }

    public String getEstadoCivil() {
        return estadoCivil;
    }

    public void setEstadoCivil(String estadoCivil) {
        this.estadoCivil = estadoCivil;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getNacionalidad() {
        return nacionalidad;
    }

    public void setNacionalidad(String nacionalidad) {
        this.nacionalidad = nacionalidad;
    }

    // Método toString para imprimir la información de la persona
    @Override
    public String toString() {
        return "Persona{" +
                "nombre='" + nombre + '\'' +
                ", edad=" + edad +
                ", genero='" + genero + '\'' +
                ", direccion='" + direccion + '\'' +
                ", ciudad='" + ciudad + '\'' +
                ", profesion='" + profesion + '\'' +
                ", estadoCivil='" + estadoCivil + '\'' +
                ", telefono='" + telefono + '\'' +
                ", email='" + email + '\'' +
                ", nacionalidad='" + nacionalidad + '\'' +
                '}';
    }

    // Método principal para probar la clase
    public static void main(String[] args) {
        // Crear una nueva instancia de Persona
        Persona Alexis = new Persona("Alexis", 30, "Masculino", "Calle 123", "Ciudad XYZ",
                "Ingeniero", "Soltero", "5613803679", "alexis.dolores07@gmail.com", "Mexicano");

        // Imprimir la información de la persona
        System.out.println(Alexis);
    }
}
