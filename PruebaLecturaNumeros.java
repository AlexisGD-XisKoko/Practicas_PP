// Alexis Guzman Dolores 19/02/24  Programacion Dinamica


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;

class LecturaNumeros extends BufferedReader {
    
    // Constructores
    public LecturaNumeros() {
        super(new InputStreamReader(System.in));
    }
    
    public LecturaNumeros(Reader r) {
        super(r);
    }
    
    // Métodos de lectura de enteros
    public int readInt() throws IOException {
        return Integer.parseInt(super.readLine());
    }
    
    public int readInt(String mensaje) throws IOException {
        System.out.print(mensaje);
        return readInt();
    }
    
    public Integer readInteger() throws IOException {
        return Integer.valueOf(readInt());
    }
    
    // Métodos de lectura de dobles
    public double readDouble() throws IOException {
        return Double.parseDouble(super.readLine());
    }
    
    public double readDouble(String mensaje) throws IOException {
        System.out.print(mensaje);
        return readDouble();
    }
}

public class PruebaLecturaNumeros {
    public static void main(String[] args) {
        try {
            LecturaNumeros lector = new LecturaNumeros();
            
            // Pedir 5 números al usuario
            System.out.println("Ingrese 5 números:");
            int num1 = lector.readInt("Número 1: ");
            int num2 = lector.readInt("Número 2: ");
            Integer num3 = lector.readInteger();
            double num4 = lector.readDouble("Número 4 (double): ");
            Double num5 = lector.readDouble("Número 5 (Double): ");
            
            // Mostrar los números ingresados
            System.out.println("\nNúmeros ingresados:");
            System.out.println("Número 1: " + num1);
            System.out.println("Número 2: " + num2);
            System.out.println("Número 3: " + num3);
            System.out.println("Número 4: " + num4);
            System.out.println("Número 5: " + num5);
            
            // Cerrar el lector
            lector.close();
            
        } catch (IOException e) {
            System.out.println("Error de entrada/salida: " + e.getMessage());
        }
    }
}
