#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int factorial(int f)
{
	int result = 1, movil = f;
	for (int i = 1; i < f + 1; i++)
	{
		result = result * i;
	}
	return result;
}
int main()
{
	//permutaciones tomando n cosas a la r vez, entonces asumo que n cosas es como el anterior, el indefinido, y r vez es el 10 del programa anterior
	cout << "Pon lo que gustes, aqui te lo combinamos: " << endl;
	int n, r;
	cin >> n;
	cout << "ahora dame R?" << endl;
	cin >> r;
	int nose = (factorial(n)) / (factorial(n - r));
	cout << "Lo que sea que busque esta pregunta, la documentacion de lo que es la permuta dice que la respuesta es:" << nose << endl;
}
