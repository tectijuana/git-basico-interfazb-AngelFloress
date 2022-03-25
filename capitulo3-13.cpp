#include <iostream>
using namespace std;
int main()
{
    double A, B, C;
    cout << "Introduce el lado A: ";
    cin >> A;
    cout << "Introduce el lado B: ";
    cin >> B;
    cout << "Introduce el lado C: ";
    cin >> C;
    if ((A + B) > C && (B + C) > A && (C + A) > B)
        cout << "Pueden ser lados de un triangulo" << endl;
    else
        cout << "No pueden ser un triangulo" << endl;
}
