/*
02/03/2024
GUZMAN DOLORES ALEXIS
PARADIGMAS DE LA PROGRAMACION 
programa: arreglo numeros aleatorios
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Función para generar un arreglo de números enteros aleatorios
void generarArreglo(int arreglo[], int tamano) {
    srand(time(NULL)); // Inicializa la semilla para generar números aleatorios
    for (int i = 0; i < tamano; i++) {
        arreglo[i] = rand() % 1000; // Genera números aleatorios entre 0 y 999
    }
}

// Función para imprimir el contenido de un arreglo
void imprimirArreglo(int arreglo[], int tamano) {
    printf("Arreglo: [");
    for (int i = 0; i < tamano; i++) {
        printf("%d", arreglo[i]);
        if (i != tamano - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Búsqueda secuencial en un arreglo
int busquedaSecuencial(int arreglo[], int tamano, int elemento, double *tiempo) {
    clock_t inicio = clock(); // Toma el tiempo de inicio
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == elemento) {
            *tiempo = ((double)(clock() - inicio)) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido
            return i; // Retorna el índice donde se encontró el elemento
        }
    }
    *tiempo = ((double)(clock() - inicio)) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido
    return -1; // Retorna -1 si el elemento no se encuentra
}

// Función para ordenar un arreglo de menor a mayor (usando el algoritmo de selección)
void ordenarArreglo(int arreglo[], int tamano, double *tiempo) {
    clock_t inicio = clock(); // Toma el tiempo de inicio
    for (int i = 0; i < tamano - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamano; j++) {
            if (arreglo[j] < arreglo[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arreglo[min_idx];
        arreglo[min_idx] = arreglo[i];
        arreglo[i] = temp;
    }
    *tiempo = ((double)(clock() - inicio)) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido
}

// Búsqueda secuencial en un arreglo ordenado
int busquedaSecuencialOrdenada(int arreglo[], int tamano, int elemento, double *tiempo) {
    clock_t inicio = clock(); // Toma el tiempo de inicio
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == elemento) {
            *tiempo = ((double)(clock() - inicio)) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido
            return i; // Retorna el índice donde se encontró el elemento
        } else if (arreglo[i] > elemento) {
            *tiempo = ((double)(clock() - inicio)) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido
            return -1; // Retorna -1 si el elemento no se encuentra y el arreglo está ordenado
        }
    }
    *tiempo = ((double)(clock() - inicio)) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido
    return -1; // Retorna -1 si el elemento no se encuentra
}

int main() {
    int opcion;
    int tamano;
    printf("Ingrese el tamaño del arreglo (hasta 1000): ");
    scanf("%d", &tamano);
    
    if (tamano > MAX_SIZE) {
        printf("El tamaño excede el máximo permitido.\n");
        return 1;
    }
    
    int arreglo[MAX_SIZE];
    generarArreglo(arreglo, tamano); // Genera el arreglo de números aleatorios
    int arreglo_original[MAX_SIZE];
    for (int i = 0; i < tamano; i++) {
        arreglo_original[i] = arreglo[i]; // Guarda una copia del arreglo original
    }
    
    clock_t inicio, fin;
    double tiempo_busqueda, tiempo_ordenamiento;
    int elemento;

    do {
        printf("\nMenú:\n");
        printf("1. Imprimir arreglo\n");
        printf("2. Búsqueda secuencial\n");
        printf("3. Ordenar arreglo y mostrarlo\n");
        printf("4. Búsqueda secuencial en arreglo ordenado\n");
        printf("5. Calcular tiempo de ejecución\n");
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                imprimirArreglo(arreglo_original, tamano); // Imprime el arreglo original
                break;
            case 2:
                {
                    printf("Ingrese el elemento a buscar: ");
                    scanf("%d", &elemento);
                    int indice = busquedaSecuencial(arreglo, tamano, elemento, &tiempo_busqueda); // Realiza la búsqueda secuencial
                    if (indice != -1) {
                        printf("El elemento %d se encuentra en la posición %d.\n", elemento, indice);
                    } else {
                        printf("El elemento %d no se encuentra en el arreglo.\n", elemento);
                    }
                    printf("Tiempo de ejecución de la búsqueda secuencial: %.6f segundos.\n", tiempo_busqueda);
                }
                break;
            case 3:
                inicio = clock();
                ordenarArreglo(arreglo, tamano, &tiempo_ordenamiento); // Ordena el arreglo
                printf("Arreglo ordenado: ");
                imprimirArreglo(arreglo, tamano); // Imprime el arreglo ordenado
                printf("Tiempo de ejecución del ordenamiento del arreglo: %.6f segundos.\n", tiempo_ordenamiento);
                break;
            case 4:
                {
                    printf("Ingrese el elemento a buscar en el arreglo ordenado: ");
                    scanf("%d", &elemento);
                    int indice = busquedaSecuencialOrdenada(arreglo, tamano, elemento, &tiempo_busqueda); // Realiza la búsqueda secuencial en el arreglo ordenado
                    if (indice != -1) {
                        printf("El elemento %d se encuentra en la posición %d.\n", elemento, indice);
                    } else {
                        printf("El elemento %d no se encuentra en el arreglo.\n", elemento);
                    }
                    printf("Tiempo de ejecución de la búsqueda secuencial en arreglo ordenado: %.6f segundos.\n", tiempo_busqueda);
                }
                break;
            case 5:
                printf("Ingrese el elemento a buscar en el arreglo original: ");
                scanf("%d", &elemento);
                busquedaSecuencial(arreglo_original, tamano, elemento, &tiempo_busqueda); // Realiza la búsqueda secuencial en el arreglo original
                printf("Ingrese el elemento a buscar en el arreglo ordenado: ");
                scanf("%d", &elemento);
                busquedaSecuencialOrdenada(arreglo, tamano, elemento, &tiempo_busqueda); // Realiza la búsqueda secuencial en el arreglo ordenado


                printf("\n");
                printf("--Tiempo de ejecución 1 a 5--\n");
                printf("Tiempo de ejecución de la impresión del arreglo original: %.6f segundos.\n", tiempo_busqueda);
                printf("Tiempo de ejecución de la impresión del arreglo ordenado: %.6f segundos.\n", tiempo_ordenamiento);
                printf("Tiempo de ejecución de la búsqueda secuencial en el arreglo original: %.6f segundos.\n", tiempo_busqueda);
                printf("Tiempo de ejecución de la búsqueda secuencial en arreglo ordenado: %.6f segundos.\n", tiempo_busqueda);
                
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}