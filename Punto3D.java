//Alexis Guzman Dolores 3CV1 Paradigmas de programacion 

import java.lang.Math;

public class Punto3D {
    private double x;
    private double y;
    private double z;

    // Constructor por defecto
    public Punto3D() {
        this.x = 0.0;
        this.y = 0.0;
        this.z = 0.0;
    }

    // Constructor que recibe parámetros
    public Punto3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Constructor que recibe un objeto Punto3D
    public Punto3D(Punto3D punto) {
        this.x = punto.getX();
        this.y = punto.getY();
        this.z = punto.getZ();
    }

    // Métodos setter y getter para X
    public void setX(double x) {
        this.x = x;
    }

    public double getX() {
        return this.x;
    }

    // Métodos setter y getter para Y
    public void setY(double y) {
        this.y = y;
    }

    public double getY() {
        return this.y;
    }

    // Métodos setter y getter para Z
    public void setZ(double z) {
        this.z = z;
    }

    public double getZ() {
        return this.z;
    }

    // Método para calcular la distancia entre dos puntos 3D
    public double distancia(Punto3D otroPunto) {
        double dx = this.x - otroPunto.getX();
        double dy = this.y - otroPunto.getY();
        double dz = this.z - otroPunto.getZ();
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }

    public static void main(String[] args) {
        // Crear un arreglo de 10 objetos Punto3D
        Punto3D[] puntos = new Punto3D[10];

        // Inicializar los puntos con valores aleatorios
        for (int i = 0; i < puntos.length; i++) {
            puntos[i] = new Punto3D(Math.random() * 10, Math.random() * 10, Math.random() * 10);
        }

        // Calcular la distancia entre todos los pares de puntos y determinar la menor distancia
        double menorDistancia = Double.MAX_VALUE; // Inicializamos la menor distancia con el máximo valor posible
        Punto3D punto1 = null;
        Punto3D punto2 = null;

        for (int i = 0; i < puntos.length - 1; i++) {
            for (int j = i + 1; j < puntos.length; j++) {
                double distanciaActual = puntos[i].distancia(puntos[j]); // Calculamos la distancia entre los puntos i y j
                if (distanciaActual < menorDistancia) { // Si la distancia actual es menor que la menor distancia registrada hasta ahora
                    menorDistancia = distanciaActual; // Actualizamos la menor distancia
                    punto1 = puntos[i];
                    punto2 = puntos[j];
                }
            }
        }

        // Imprimir la menor distancia y los puntos entre los cuales se encuentra
        System.out.println("La menor distancia entre dos puntos es: " + menorDistancia);
        System.out.println("Los puntos entre los cuales se encuentra la menor distancia son:");
        System.out.println("Punto 1: (" + punto1.getX() + ", " + punto1.getY() + ", " + punto1.getZ() + ")");
        System.out.println("Punto 2: (" + punto2.getX() + ", " + punto2.getY() + ", " + punto2.getZ() + ")");
    }
}
