/*
20/03/2024
Paradigmas de programacón
Guzmán Dolores Alexis
programa: calculador funciones primarias  (10 funciones )
*/


#include <stdio.h>
#include <math.h>

// Función para ingresar los datos
void ingresarDatos(float datos[], int *n) {
    printf("Ingrese la cantidad de datos a ingresar: ");
    scanf("%d", n);
    printf("Ingrese los datos:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%f", &datos[i]);
    }
}

// Funciones para realizar operaciones matemáticas
float suma(float datos[], int n) {
    float resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado += datos[i];
    }
    return resultado;
}

float resta(float datos[], int n) {
    float resultado = datos[0];
    for (int i = 1; i < n; i++) {
        resultado -= datos[i];
    }
    return resultado;
}

float multiplicacion(float datos[], int n) {
    float resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= datos[i];
    }
    return resultado;
}

float division(float datos[], int n) {
    float resultado = datos[0];
    for (int i = 1; i < n; i++) {
        resultado /= datos[i];
    }
    return resultado;
}

float raiz(float datos[], int n) {
    float resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= sqrt(datos[i]); // Calcula la raíz cuadrada de cada dato y los multiplica entre sí
    }
    return resultado;
}

float potencia(float base, float exponente) {
    return pow(base, exponente); // Devuelve la base elevada al exponente
}

float factorial(float dato) {
    float resultado = 1;
    for (int i = 1; i <= (int)dato; i++) {
        resultado *= i;
    }
    return resultado; // Devuelve el factorial del dato ingresado
}

float seno(float dato) {
    return sin(dato); // Devuelve el seno del dato ingresado
}

float coseno(float dato) {
    return cos(dato); // Devuelve el coseno del dato ingresado
}

float tangente(float dato) {
    return tan(dato); // Devuelve la tangente del dato ingresado
}

int main() {
    int opcion, n;
    float datos[100], exponente;

    while (1) {
        printf("\n");
        printf("1. Ingresar datos\n");
        printf("2. Suma\n");
        printf("3. Resta\n");
        printf("4. Multiplicación\n");
        printf("5. División\n");
        printf("6. Raíz cuadrada\n");
        printf("7. Potencia\n");
        printf("8. Factorial\n");
        printf("9. Seno\n");
        printf("10. Coseno\n");
        printf("11. Tangente\n");
        printf("0. Salir\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 0:
                return 0;
            case 1:
                ingresarDatos(datos, &n);
                break;
            case 2:
                printf("Suma: %.2f\n", suma(datos, n));
                break;
            case 3:
                printf("Resta: %.2f\n", resta(datos, n));
                break;
            case 4:
                printf("Multiplicación: %.2f\n", multiplicacion(datos, n));
                break;
            case 5:
                printf("División: %.2f\n", division(datos, n));
                break;
            case 6:
                printf("Raíz cuadrada de todos los datos: %.2f\n", raiz(datos, n));
                break;
            case 7:
                printf("Ingrese el exponente: ");
                scanf("%f", &exponente);
                printf("Potencia: %.2f\n", potencia(datos[0], exponente));
                break;
            case 8:
                printf("Factorial: %.2f\n", factorial(datos[0]));
                break;
            case 9:
                printf("Seno: %.2f\n", seno(datos[0]));
                break;
            case 10:
                printf("Coseno: %.2f\n", coseno(datos[0]));
                break;
            case 11:
                printf("Tangente: %.2f\n", tangente(datos[0]));
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    }

    return 0;
}