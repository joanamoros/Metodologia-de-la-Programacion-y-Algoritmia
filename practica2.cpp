#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

// Integrantes:
// Ainhoa Rodríguez González
// Juan Manuel García Cabot
// Joan Amorós Ramírez

void Intercambiar(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void Seleccion(vector<int> &V) {
    int n = V.size();
    for (int i = 0; i < n - 1; i++) {
        int posmin = i;
        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[posmin]) {
                posmin = j;
            }
        }
        Intercambiar(V[i], V[posmin]);
    }
}

int main() {
    clock_t tinicio, tfin;
    int t, seed, p1, p2;
    double tiempo;

    // Entrada de datos
    cout << "Semilla para generar aleatorios: ";
    cin >> seed;
    cout << "Introduce tamanyo del vector: ";
    cin >> t;
    cout << "Posiciones INICIAL y FINAL del vector para mostrar" << endl;
    cout << "INICIAL: ";
    cin >> p1;
    cout << "FINAL: ";
    cin >> p2;

    // Convertir a índices base 0
    p1 = p1 - 1;
    // p2 se mantiene como 1-indexado para el bucle (i < p2)

    cout << endl;

    // Generar vector aleatorio
    srand(seed);
    vector<int> V(t);
    for (int i = 0; i < t; i++) {
        V[i] = rand();
    }

    cout << "ALGORITMO DE SELECCION" << endl;

    // CASO CUALQUIERA
    cout << "CASO CUALQUIERA" << endl;
    cout << "Vector a ordenar: ";
    for (int i = p1; i < p2; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    tinicio = clock();
    Seleccion(V);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vector ordenado: ";
    for (int i = p1; i < p2; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
    cout << "El tiempo de ejecucion en ms es " << tiempo << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;

    // CASO MEJOR (el vector ya está ordenado)
    cout << "CASO MEJOR" << endl;
    cout << "Vector a ordenar: ";
    for (int i = p1; i < p2; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    tinicio = clock();
    Seleccion(V);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vector ordenado: ";
    for (int i = p1; i < p2; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
    cout << "El tiempo de ejecucion en ms es " << tiempo << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;

    // CASO PEOR: invertir el vector ordenado
    cout << "CASO PEOR" << endl;
    // Invertir el vector
    for (int i = 0; i < t / 2; i++) {
        int aux = t - 1 - i;
        Intercambiar(V[i], V[aux]);
    }
    cout << "Vector a ordenar: ";
    for (int i = p1; i < p2; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    tinicio = clock();
    Seleccion(V);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vector ordenado: ";
    for (int i = p1; i < p2; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
    cout << "El tiempo de ejecucion en ms es " << tiempo << endl;
    cout << "FIN DEL PROGRAMA" << endl;

    return 0;
}