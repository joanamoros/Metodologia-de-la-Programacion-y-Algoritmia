#include <iostream>
#include <stack>

using namespace std;

float p41(float x, int n)
{
    if(n < 0) return -1; // manejo de error

    stack<int> pn;
    int exp = n;

    // Paso 1: simular llamadas recursivas apilando exponentes
    while(exp > 0)
    {
        pn.push(exp);
        if(exp % 2 == 0)
            exp /= 2;     // si es par, divido entre 2
        else
            exp -= 1;     // si es impar, resto 1
    }

    float s = 1.0f;

    // Paso 2: desapilar y calcular la potencia
    while(!pn.empty())
    {
        int current = pn.top();
        pn.pop();

        if(current % 2 == 0 && current != 0)
        {
            s = s * s;    // caso par: elevar al cuadrado
        }
        else
        {
            s *= x;       // caso impar o 1: multiplicar por x
        }
    }

    return s;
}

int main()
{
    float x;
    int n;

    cout << "Introduce un numero real: ";
    cin >> x;

    cout << "Introduce un numero natural: ";
    cin >> n;

    if(n < 0)
    {
        cout << "Error" << endl;
        return -1;
    }

    cout << "Resultado: " << p41(x,n) << endl;

    return 0;
}