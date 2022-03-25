#include <iostream>
#include <algorithm>
using namespace std;
int combina(int n, int r)//odio la probabilidad y estadistica con todo mi ser
{
    int respuesta = 0;
    string combinacion(r, 1);//lidera los unos
    combinacion.resize(n, 0);//camino de ceros entre n y r
    do { respuesta++; } while (std::prev_permutation(combinacion.begin(), combinacion.end()));//esto cuenta, permuta y agrega uno por cada permutacion, ya que sol oes calcular permutaciones
    return respuesta;
}//profesor, honestamente solo se la parte de programacion, se para que son las instrucciones pero no el motivo por el que las uso en este programa, ni en los previos 3
int main()
{
    int n, r;
    cout << "Hola, dame el valor de n:" << endl;
    cin >> n;
    cout << "Ahora el de R" << endl;
    cin >> r;
    int res = combina(n, r);
    cout << "n y r se combinan " << res << " veces" << endl;
}
