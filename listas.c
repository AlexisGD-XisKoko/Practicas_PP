/*
06/03/2024
Paradigmas de programacón
Guzmán Dolores Alexis
programa: listas operaciones(maximos,minimos,sumas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de funciones
void generar_listas(int num_elementos, int lista1[], int lista2[]);
void mostrar_listas(int num_elementos, int lista1[], int lista2[]);
void minimos_listas(int num_elementos, int lista1[], int lista2[], int *minimo1, int *minimo2);
void maximos_listas(int num_elementos, int lista1[], int lista2[], int *maximo1, int *maximo2);
void sumar_elementos(int num_elementos, int lista1[], int lista2[], int suma_lista[]);
int sumar_lista_completa(int num_elementos, int lista[]);


//Definición de funciones


// Función para generar las listas de números aleatorios
void generar_listas(int num_elementos, int lista1[], int lista2[]) {
    srand(time(NULL));
    for (int i = 0; i < num_elementos; i++) {
        lista1[i] = rand() % 201 - 100; // Rango de -100 a 100
        lista2[i] = rand() % 201 - 100;
    }
}

// Función para mostrar las listas
void mostrar_listas(int num_elementos, int lista1[], int lista2[]) {
    printf("Lista 1: [");
    for (int i = 0; i < num_elementos; i++) {
        printf("%d", lista1[i]);
        if (i < num_elementos - 1)
            printf(", ");
    }
    printf("]\n");

    printf("Lista 2: [");
    for (int i = 0; i < num_elementos; i++) {
        printf("%d", lista2[i]);
        if (i < num_elementos - 1)
            printf(", ");
    }
    printf("]\n");
}

// Función para encontrar el mínimo de cada lista
void minimos_listas(int num_elementos, int lista1[], int lista2[], int *minimo1, int *minimo2) {
    *minimo1 = lista1[0];
    *minimo2 = lista2[0];

    for (int i = 1; i < num_elementos; i++) {
        if (lista1[i] < *minimo1)
            *minimo1 = lista1[i];
        if (lista2[i] < *minimo2)
            *minimo2 = lista2[i];
    }
}

// Función para encontrar el máximo de cada lista
void maximos_listas(int num_elementos, int lista1[], int lista2[], int *maximo1, int *maximo2) {
    *maximo1 = lista1[0];
    *maximo2 = lista2[0];

    for (int i = 1; i < num_elementos; i++) {
        if (lista1[i] > *maximo1)
            *maximo1 = lista1[i];
        if (lista2[i] > *maximo2)
            *maximo2 = lista2[i];
    }
}

// Función para sumar los elementos de las listas
void sumar_elementos(int num_elementos, int lista1[], int lista2[], int suma_lista[]) {
    for (int i = 0; i < num_elementos; i++) {
        suma_lista[i] = lista1[i] + lista2[i];
    }
}

// Función para sumar por completo una lista
int sumar_lista_completa(int num_elementos, int lista[]) {
    int suma_total = 0;
    for (int i = 0; i < num_elementos; i++) {
        suma_total += lista[i];
    }
    return suma_total;
}

int main() {
    int num_elementos;
    printf("Ingrese el número de elementos que desea en las listas: ");
    scanf("%d", &num_elementos);

    int lista1[num_elementos], lista2[num_elementos];
    int suma_lista[num_elementos];

    generar_listas(num_elementos, lista1, lista2);

    int opcion;
    do {
        printf("\nMenú:\n");
        printf("1. Mostrar listas\n");
        printf("2. Mínimos de las listas\n");
        printf("3. Máximos de las listas\n");
        printf("4. Sumar elementos de las listas\n");
        printf("5. Sumar lista completa\n");
        printf("6. Salir\n");

        printf("Ingrese el número de la operación que desea realizar: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrar_listas(num_elementos, lista1, lista2);
                break;
            case 2: {
                int minimo1, minimo2;
                minimos_listas(num_elementos, lista1, lista2, &minimo1, &minimo2);
                printf("Mínimo de la lista 1: %d\n", minimo1);
                printf("Mínimo de la lista 2: %d\n", minimo2);
                break;
            }
            case 3: {
                int maximo1, maximo2;
                maximos_listas(num_elementos, lista1, lista2, &maximo1, &maximo2);
                printf("Máximo de la lista 1: %d\n", maximo1);
                printf("Máximo de la lista 2: %d\n", maximo2);
                break;
            }
            case 4:
                sumar_elementos(num_elementos, lista1, lista2, suma_lista);
                printf("Suma de los elementos de las listas: [");
                for (int i = 0; i < num_elementos; i++) {
                    printf("%d", suma_lista[i]);
                    if (i < num_elementos - 1)
                        printf(", ");
                }
                printf("]\n");
                break;
            case 5: {
                sumar_elementos(num_elementos, lista1, lista2, suma_lista);
                int suma_total = sumar_lista_completa(num_elementos, suma_lista);
                printf("Suma total de la lista completa: %d\n", suma_total);
                break;
            }
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese un número válido del menú.\n");
        }
    } while (opcion != 6);

    return 0;
}