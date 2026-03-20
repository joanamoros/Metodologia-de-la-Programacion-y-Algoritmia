#include<iostream>
#include<stdlib.h>

/*
Juan Manuel Garcia Cabot
Ainhoa Rodrigez Gonzalez
Joan Amoros Ramirez
*/

using namespace std;

void mostrar_vector(int *V, int inicio, int fin)
{
    for (int i = inicio; i <= fin; i++)
    {
        cout << V[i] << " ";
    }
}

void intercambiar(int *V, int x, int y) 
{
    int temp;
    temp = V[x];
    V[x] = V[y];
    V[y] = temp;
}

// Estrategia 1: Mediana de tres (de la actividad anterior)
int seleccionar_pivote_mediana(int *V, int izq, int der)
{
    int medio = (izq + der) / 2;
    
    // Ordenar los tres elementos
    if (V[izq] > V[medio])
        intercambiar(V, izq, medio);
    if (V[izq] > V[der])
        intercambiar(V, izq, der);
    if (V[medio] > V[der])
        intercambiar(V, medio, der);
    
    return medio;
}

// Estrategia 2: Nueva estrategia (por ejemplo, pivote aleatorio o primer elemento)
int seleccionar_pivote_nuevo(int *V, int izq, int der)
{
    // Estrategia alternativa: elegir el elemento del medio (sin ordenar)
    // Esta es una estrategia diferente a la mediana de tres
    return (izq + der) / 2;
}

// Función para mostrar la traza
void mostrar_traza(int llamada, int *V, int izq, int der, int p, int pivote)
{
    cout << "(" << llamada << ") Quicksort(V," << izq << "," << der << "), ";
    cout << "p = " << p << ", Pivote = " << pivote << " --> ";
    mostrar_vector(V, izq, der);
    cout << endl;
}

int quicksort(int *V, int izq, int der, int estrategia, int &llamada)
{
    if (izq >= der)
        return 0;
    
    int i, d, p;
    int pivote;
    int llamada_actual = llamada++;
    
    // Seleccionar pivote según la estrategia
    if (estrategia == 1)
    {
        p = seleccionar_pivote_mediana(V, izq, der);
    }
    else
    {
        p = seleccionar_pivote_nuevo(V, izq, der);
    }
    
    pivote = V[p];
    
    // Mostrar traza antes de la partición
    cout << "(" << llamada_actual << ") Quicksort(V," << izq << "," << der << "), ";
    cout << "p = " << p << ", Pivote = " << pivote << " --> ";
    mostrar_vector(V, izq, der);
    cout << endl;
    
    // Mover el pivote al final temporalmente para facilitar la partición
    intercambiar(V, p, der);
    
    i = izq;
    d = der - 1;
    
    // Algoritmo de partición
    while (i <= d)
    {
        while (i <= d && V[i] <= pivote)
            i++;
        while (d >= i && V[d] >= pivote)
            d--;
        
        if (i < d)
        {
            intercambiar(V, i, d);
            i++;
            d--;
        }
    }
    
    // Colocar el pivote en su posición correcta
    intercambiar(V, i, der);
    
    // Mostrar estado después de la partición
    cout << "    Partición completada: ";
    mostrar_vector(V, izq, der);
    cout << " (Pivote en posición " << i << ")" << endl << endl;
    
    // Llamadas recursivas
    quicksort(V, izq, i-1, estrategia, llamada);
    quicksort(V, i+1, der, estrategia, llamada);
    
    return 0;
}

int main()
{
    int t, e, opcion;
    int llamada = 0;
    
    cout << "introduce Tamano del vector: ";
    cin >> t;
    
    if (t <= 0)
    {
        cout << "Error: El tamano debe ser mayor que 0" << endl;
        return -1;
    }
    
    // Usar memoria dinámica
    int *V = new int[t];
    
    for (int i = 0; i < t; i++)
    {
        cout << "introduce el elemento natural numero (" << i+1 << ") del vector: ";
        cin >> e;
        if (e < 0)
        { 
            cout << endl << "Error, hay un numero negativo en el vector." << endl;
            delete[] V;
            return -1;
        }
        V[i] = e;
    }
    
    // Mostrar estrategias disponibles
    cout << "\nEstrategias de selección de pivote:" << endl;
    cout << "1. Mediana de tres (primero, medio, último)" << endl;
    cout << "2. Elemento central" << endl;
    cout << "Seleccione estrategia (1 o 2): ";
    cin >> opcion;
    
    if (opcion != 1 && opcion != 2)
    {
        cout << "Estrategia no válida. Usando estrategia 1 por defecto." << endl;
        opcion = 1;
    }
    
    cout << "\nVector original: ";
    mostrar_vector(V, 0, t-1);
    cout << endl << endl;
    
    cout << "=== INICIO DEL PROCESO DE ORDENACIÓN ===" << endl;
    quicksort(V, 0, t-1, opcion, llamada);
    cout << "=== FIN DEL PROCESO DE ORDENACIÓN ===" << endl;
    
    cout << "\nVector ordenado: ";
    mostrar_vector(V, 0, t-1);
    cout << endl;
    
    cout << "Fin del programa" << endl;
    
    delete[] V;
    return 0;
}