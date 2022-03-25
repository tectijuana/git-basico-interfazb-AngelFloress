#include <iostream>
using namespace std;
int main()
{
	int pagolegaldiario = 0.05 * 20;
	int acummulta = 0, torcidas = 0;
	srand(time(0));
	for(int i=0;i<20;i++)
	{
		if((rand()%2)%2==0)
		{
			cout << "Pillado infraganti, pague multa" << endl;
			torcidas++;
			if(torcidas==2)
			{
				acummulta = acummulta + 0.5;
			}
			if(i>2)
			{
				acummulta = acummulta + 1;
			}
		}
		else
		{
			cout << "Hoy no hay multa :)" << endl;
		}
	}
	cout << "El valor de pagar el parquimetro diario seria de " << pagolegaldiario << " dolar,\nlo cual es baratisimo la verdad y esto te costo parquearte\naqui las ultimas 20 veces sin pagar el parquimetro: " << acummulta << " dolares, te recomiendo juntar monedas de 5 centavos" << endl;
}
