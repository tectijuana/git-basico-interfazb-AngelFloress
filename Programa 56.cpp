#include <iostream>
using namespace std;
int main()
{
	int edades[20];
	for (int i=0;i<20;i++)
	{
		if(i<6)
		{
			edades[i] = 18;
		}
		if (i >= 6 && i < 17)
		{
			edades[i] = 19;
		}
		if(i>16)
		{
			edades[i] = 20;
		}
	}
	cout << "La edad del alumno random es de " << edades[rand() % 20] << " años" << endl;
}
