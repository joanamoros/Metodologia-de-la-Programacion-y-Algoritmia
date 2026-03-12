#include <iostream>
using namespace std;

/*---------------------------------------------------
    ACTIVIDAD 1 - BINARIO RECURSIVO
---------------------------------------------------*/

void binario(int numero)
{
    if (numero > 1)
    {
        binario(numero / 2);
    }
    cout << numero % 2;
}

/*---------------------------------------------------
    ACTIVIDAD 2 - COMBINACIONES
---------------------------------------------------*/

int combinaciones(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return combinaciones(n - 1, k - 1) + combinaciones(n - 1, k);
}

/*---------------------------------------------------
    ACTIVIDAD 2b - COMBINACIONES CON TRAZA
---------------------------------------------------*/

int contador = 0;

int combinaciones_traza(int n, int k, int nivel)
{
    contador++;

    // Imprimir indentación
    for (int i = 0; i < nivel; i++)
        cout << "   ";

    cout << contador << ".- combinaciones_traza(" << n << "," << k << ")" << endl;

    if (k == 0 || k == n)
        return 1;
    else
        return combinaciones_traza(n - 1, k - 1, nivel + 1)
             + combinaciones_traza(n - 1, k, nivel + 1);
}

/*---------------------------------------------------
    MAIN
---------------------------------------------------*/

int main()
{
    int opcion;

    cout << "===== PRACTICA 3 - RECURSIVIDAD =====" << endl;
    cout << "1. Convertir numero a binario" << endl;
    cout << "2. Calcular combinaciones C(n,k)" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if (opcion == 1)
    {
        int ndecimal;

        cout << "Introduce valor: ";
        cin >> ndecimal;

        if (ndecimal < 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << "Binario: ";
            if (ndecimal == 0)
                cout << "0";
            else
                binario(ndecimal);
            cout << endl;
        }
    }
    else if (opcion == 2)
    {
        int n, k;

        cout << "Introduce n: ";
        cin >> n;
        cout << "Introduce k: ";
        cin >> k;

        if (k < 0 || n < 0 || k > n)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << "\nTotal combinaciones: " << combinaciones(n, k) << endl;

            cout << "\nTraza:\n";
            contador = 0;
            combinaciones_traza(n, k, 0);
        }
    }
    else
    {
        cout << "Opcion no valida." << endl;
    }

    cout << "\nFin del programa." << endl;

    return 0;
}