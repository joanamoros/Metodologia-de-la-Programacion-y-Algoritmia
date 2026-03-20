#include<iostream>
#include<stdlib.h>

/*
Juan Manuel Garcia Cabot
Ainhoa Rodrigez Gonzalez
Joan Amoros Ramirez
*/

using namespace std;

void mostrar_vector(int *V, int t)
{
    for (int i = 0; i < t ; i++)
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

int seleccionar_pivote(int *V, int izq, int der, int estrategia)
{
    if (estrategia == 1)
    {
        int medio = (izq + der) / 2;
        
        // Mediana de tres: ordenar los tres elementos y devolver la posición del medio
        if (V[izq] > V[medio])
            intercambiar(V, izq, medio);
        if (V[izq] > V[der])
            intercambiar(V, izq, der);
        if (V[medio] > V[der])
            intercambiar(V, medio, der);
        
        return medio;
    }
    else if (estrategia == 2)
    {
        // Estrategia alternativa: elegir el mayor de los dos extremos
        if(V[izq] < V[der])
        {
            return der;
        }
        else
        {   
            return izq;
        }
    }
    
    return -1; // Valor inválido para indicar error
}

int quicksort (int *V, int izq, int der, int estrategia)
{
    // Caso base: si el subvector tiene menos de 2 elementos, ya está ordenado
    if (izq >= der)
        return 0;
    
    int i, d, p;
    int pivote;

    p = seleccionar_pivote(V, izq, der, estrategia);
    
    if (p != -1) // Si se seleccionó un pivote válido
    {
        pivote = V[p];
        i = izq;
        d = der;

        while (i <= d)
        {
            while (V[i] < pivote)
            {
                i = i + 1;
            }

            while (V[d] > pivote)
            {
                d = d - 1;
            }

            if (i <= d)
            {
                intercambiar(V, i, d);
                i = i + 1;
                d = d - 1;
            }
        }
        
        // Llamadas recursivas
        if (izq < d)
        {
            quicksort(V, izq, d, estrategia);
        }
        if (i < der)
        {
            quicksort(V, i, der, estrategia);
        }
    }
    
    return 0;
}

int main()
{
    int t, e, i, estrategia;

    estrategia = 1;

    cout << "introduce Tamano del vector: ";
    cin >> t;
    
    // Verificar que el tamaño sea válido
    if (t <= 0)
    {
        cout << endl << "Error: El tamano del vector debe ser mayor que 0." << endl;
        return -1;
    }

    // Usar memoria dinámica en lugar de VLA
    int *V = new int[t];
    
    for (i = 0; i < t ; i++)
    {
        cout << "introduce el elemento natural numero (" << i+1 << ") del vector: ";
        cin >> e;
        if (e < 0)
        { 
            cout << endl << "Error, hay un numero negativo en el vector."; 
            delete[] V; // Liberar memoria antes de salir
            return -1; 
        }
        V[i] = e;
    }

    cout << "Vector original: ";
    mostrar_vector(V, t);

    quicksort(V, 0, t-1, estrategia);

    cout << endl << "Vector ordenado: ";
    mostrar_vector(V, t);

    cout << endl << "Fin del programa" << endl;
    
    // Liberar memoria dinámica
    delete[] V;
    
    return 0;
}