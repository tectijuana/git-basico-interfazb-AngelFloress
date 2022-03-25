#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	int X[2] = { 0,1 };
	int Y[3] = { 0,0,1 };
	bool vivoX = true, vivoY = true;
	while (vivoX == true && vivoY == true) 
	{
		cout << "Vaquero Y dispara su arma\n";
		int tiroY = rand() % 3;
		if (Y[tiroY] > 0) 
		{
			vivoX = false;
			break;
		}
		cout << "Vaquero X dispara su arma\n";
		int tiroX = rand() % 2;
		if (X[tiroX]>0)
		{
			vivoY = false;
			break;
		}
	}
	if (vivoY == true) 
	{
		cout << "Vaquero Y Gana!" << endl;
	}
	else
	{
		cout << "Vaquero X Gana el duelo!" << endl;
	}
}
