#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

/*
Ainhoa Rodriguez Gonzalez
Juan Manuel Garcia Cabot
Joan Amorós Ramirez
*/

void mostrar_vector(float *V, int t)
{
    cout << "[ ";
    for(int i = 1; i <= t; i++)
    {
        cout << V[i];
        if(i < t) cout << " , ";
    }
    cout << " ]" << endl;
}

void intercambiar(float *V, int x, int y) 
{
    float temp;  // Corregido: debe ser float, no int
    temp = V[x];
    V[x] = V[y];
    V[y] = temp;
}

void OrdenarDecreciente(float O[], float V[], float P[], int n)
{
    int i, j, posmax;
    float ratio1, ratio2;
    
    // Ordenación por selección en orden decreciente según valor/peso
    for (i = 1; i < n; i++)
    {
        posmax = i;
        for (j = i+1; j <= n; j++)
        {
            ratio1 = V[posmax] / P[posmax];
            ratio2 = V[j] / P[j];
            if (ratio2 > ratio1)
            {
                posmax = j;
            }   
        }
        
        if (posmax != i)
        {
            intercambiar(O, i, posmax);
            intercambiar(P, i, posmax);
            intercambiar(V, i, posmax);
        }
    }
}

void Mochila(float M, float O[], float P[], float V[], int n, float X[])
{
    float peso = 0;
    int i = 1;
    
    // Inicializar X a 0
    for (i = 1; i <= n; i++)
    {
        X[i] = 0;
    }
    
    // Ordenar objetos por ratio valor/peso decreciente
    OrdenarDecreciente(O, V, P, n);
    
    i = 1;
    peso = 0;
    
    // Seleccionar objetos
    while (peso < M && i <= n)
    {
        if (peso + P[i] <= M)
        {
            X[i] = 1;  // Tomar objeto completo
            peso = peso + P[i];
        }
        else
        {
            X[i] = (M - peso) / P[i];  // Tomar fracción del objeto
            peso = M;
        }
        i++;
    }
}

int main()
{
    int n;
    float M, valor_total = 0;
    
    cout << "Introduce el peso maximo de la mochila: ";
    cin >> M;
    if (M < 0)
    {
        cout << endl << "Error: el peso maximo es negativo." << endl;
        return -1;
    }
    
    cout << "Introduce el numero de objetos: ";
    cin >> n;
    if (n <= 0)
    {
        cout << endl << "Error: el numero de objetos debe ser positivo." << endl;
        return -1;
    }
    
    // Usar memoria dinámica en lugar de VLA
    float *O = new float[n+1];  // Índices de objetos
    float *P = new float[n+1];  // Pesos
    float *V = new float[n+1];  // Valores
    float *X = new float[n+1];  // Solución (fracciones)
    
    // Inicializar identificadores de objetos
    for (int i = 1; i <= n; i++)
    {
        O[i] = i;
    }
    
    // Leer pesos
    for (int i = 1; i <= n; i++)
    {
        cout << "Introduce el peso del objeto " << i << ": ";
        cin >> P[i];
        if (P[i] < 0)
        {
            cout << endl << "Error: peso negativo." << endl;
            delete[] O; delete[] P; delete[] V; delete[] X;
            return -1;
        }
    }
    
    // Leer valores
    for (int i = 1; i <= n; i++)
    {
        cout << "Introduce el valor del objeto " << i << ": ";
        cin >> V[i];
        if (V[i] < 0)
        {
            cout << endl << "Error: valor negativo." << endl;
            delete[] O; delete[] P; delete[] V; delete[] X;
            return -1;
        }
    }
    
    // Resolver el problema de la mochila fraccionaria
    Mochila(M, O, P, V, n, X);
    
    // Calcular valor total
    valor_total = 0;
    for (int i = 1; i <= n; i++)
    {
        valor_total += X[i] * V[i];
    }
    
    // Mostrar resultados
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Valor total de la mochila: " << valor_total << endl;
    cout << "\nDetalle de objetos seleccionados:" << endl;
    cout << "Objeto\tPeso\tValor\tFracción\tValor aportado" << endl;
    cout << "------------------------------------------------" << endl;
    
    for (int i = 1; i <= n; i++)
    {
        if (X[i] > 0)
        {
            cout << O[i] << "\t" << P[i] << "\t" << V[i] << "\t";
            cout << X[i] << "\t\t" << X[i] * V[i] << endl;
        }
    }
    
    // Mostrar arrays completos (para depuración)
    cout << "\n=== ARRAYS ORDENADOS (por ratio valor/peso) ===" << endl;
    cout << "Objetos: ";
    mostrar_vector(O, n);
    cout << "Pesos:   ";
    mostrar_vector(P, n);
    cout << "Valores: ";
    mostrar_vector(V, n);
    cout << "Solución: ";
    mostrar_vector(X, n);
    
    cout << "\nFin del programa" << endl;
    
    // Liberar memoria dinámica
    delete[] O;
    delete[] P;
    delete[] V;
    delete[] X;
    
    return 0;
}
