#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double A, B, C, Big;
    int S;
    cout << "Introduce 3 numeros positivos" << endl;
    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;
    cout << "C: ";
    cin >> C;
    if (A > B && A > C) {
        Big = A;
        S = 0;
    }
    else if (B > A && B > C) {
        Big = B;
        S = 1;
    }
    else {
        Big = C;
        S = 2;
    }

    if (A > 0 && B > 0 && C > 0) {
        switch (S)
        {
        case 0:
            if (Big == sqrt(pow(B, 2) + pow(C, 2)))
                cout << "Se puede crear un triangulo recto!" << endl;
            else
                cout << "No puede ser un triangulo recto" << endl;
            break;
        case 1:
            if (Big == sqrt(pow(A, 2) + pow(C, 2)))
                cout << "Se puede crear un triangulo recto!" << endl;
            else
                cout << "No puede ser un triangulo recto" << endl;
            break;
        case 2:
            if (Big == sqrt(pow(A, 2) + pow(B, 2)))
                cout << "Se puede crear un triangulo recto!" << endl;
            else
                cout << "No puede ser un triangulo recto" << endl;
            break;
        default:
            break;
        }
    }
    else
        cout << "No puede ser un triangulo recto" << endl;
}
