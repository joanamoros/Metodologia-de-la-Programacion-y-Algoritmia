#include <iostream>
#include <cstdlib> // para NULL y exit (opcional)
using namespace std;

// Prototipo de la función Contar (también se puede definir directamente antes de main)
int Contar(int *V, int n, int x);

int main() {
    int n, x;

    // 1.1 - Pedir tamaño y valor a buscar
    cout << "Introduce el tamaño del vector (n): ";
    cin >> n;
    cout << "Introduce el valor a buscar (x): ";
    cin >> x;

    // 1.2 - Reservar memoria para los tres vectores (n+1 elementos cada uno)
    int *vpeor = new (nothrow) int[n+1];
    int *vmejor = new (nothrow) int[n+1];
    int *vacu = new (nothrow) int[n+1];

    // Comprobar que la memoria se ha reservado correctamente
    if (vpeor == NULL || vmejor == NULL || vacu == NULL) {
        cout << "Error al reservar memoria." << endl;
        return -1;  // o exit(-1);
    }

    // 1.3 - Inicializar cada vector según su caso
    // vpeor: todos los elementos iguales a x
    for (int i = 1; i <= n; i++) {
        vpeor[i] = x;
    }

    // vmejor: todos los elementos distintos de x (por ejemplo, x+1)
    for (int i = 1; i <= n; i++) {
        vmejor[i] = x + 1;
    }

    // vacu: distribución mixta (mitad iguales a x, mitad diferentes)
    // Para este ejemplo, las primeras n/2 posiciones son x y el resto x+1
    int mitad = n / 2;
    for (int i = 1; i <= n; i++) {
        if (i <= mitad)
            vacu[i] = x;
        else
            vacu[i] = x + 1;
    }

    // Mostrar los tres vectores generados
    cout << "\nVector PEOR (todos iguales a " << x << "):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << vpeor[i] << " ";
    }
    cout << endl;

    cout << "\nVector MEJOR (todos distintos de " << x << "):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << vmejor[i] << " ";
    }
    cout << endl;

    cout << "\nVector CUALQUIERA (mitad iguales, mitad distintos):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << vacu[i] << " ";
    }
    cout << endl;

    // 1.5 - Llamar a Contar para cada vector e imprimir resultados
    int veces_peor = Contar(vpeor, n, x);
    int veces_mejor = Contar(vmejor, n, x);
    int veces_vacu = Contar(vacu, n, x);

    cout << "\nResultados:" << endl;
    cout << "Número de veces que aparece " << x << " en el vector PEOR: " << veces_peor << endl;
    cout << "Número de veces que aparece " << x << " en el vector MEJOR: " << veces_mejor << endl;
    cout << "Número de veces que aparece " << x << " en el vector CUALQUIERA: " << veces_vacu << endl;

    // Liberar la memoria reservada
    delete[] vpeor;
    delete[] vmejor;
    delete[] vacu;

    return 0;
}

// 1.4 - Implementación de la función Contar según el pseudocódigo
int Contar(int *V, int n, int x) {
    int nveces = 0;
    for (int i = 1; i <= n; i++) {
        if (V[i] == x) {
            nveces++;
        }
    }
    return nveces;
}