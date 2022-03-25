#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	const string sexo[2] = { "varon","mujer"};
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		int prolly = rand() % 2;
		cout << "El bebe #" << i+1 << "ha nacido, y es "<<sexo[prolly]<<"!\n";
		if (prolly < 1) 
		{
			total++;
		}
	}
	cout << "despues de registrar los sexos de los bebes, fueron un " << total * 10 << "% de varones";
}
