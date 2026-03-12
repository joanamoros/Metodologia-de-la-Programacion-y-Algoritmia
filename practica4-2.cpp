#include <iostream>
#include <stack>

using namespace std;

int p42(int x, int y)
{
    int x1 = x;
    int y1 = y;
    int s;
    stack<int> px, py;

    // Paso 1: simular recursión apilando valores
    while(x1 > 4)
    {
        px.push(x1);
        py.push(y1);
        x1 -= 4;
        y1 /= 3;
    }

    // Base de la recursión
    s = x1 + y1;

    // Paso 2: desapilar y acumular
    while(!px.empty())
    {
        int xi = px.top();
        int yi = py.top();
        px.pop();
        py.pop();

        s += xi * yi; // coincide con "devolver p42(x, y) + x*y"
    }

    return s;
}

int main()
{
    int x, y;

    cout << "Introduce un numero entero: ";
    cin >> x;

    cout << "Introduce otro numero entero: ";
    cin >> y;

    cout << "Resultado: " << p42(x, y) << endl;

    return 0;
}