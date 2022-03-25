#include <iostream>
using namespace std;
int main()
{
	int skillA = 83;//la skill se define de 0 a 100, esto es la p del problema 53
	//se gana al que anote 15 puntos primero, pero si A falla el tiro, hay un 75% de chances de que le anoten punto, also cada que recibe un tiro directo en vez de una respuesta la chance es de 80% de recibir un punto en contra sin capacidad de responder
	srand(time(0));
	int winsA = 0;
	for (int juegos = 0; juegos < 10; juegos++)
	{
		cout << "Game #" << juegos + 1 << ", start!" << endl;
		int puntosa = 0, puntosb = 0;
		while (puntosa < 15 && puntosb < 15)
		{
			cout << "Jugador A tira y...    ";
			if (rand() % 100 <= skillA)
			{
				cout << "ANOTA UN PUNTO!" << endl;
				puntosa++;
				if (puntosa == 15) break;
			}
			else
			{
				cout << "Ha fallado..." << endl << "El Jugador B responde y... ";
				if (rand()%100 <= 75)
				{
					cout << "ANOTA UN PUNTO!" << endl;
					puntosb++;
					if (puntosb == 15)break;
				}
				else
				{
					cout << "Ha fallado..." << endl;
				}
			}
			cout << "El Jugador B tira y...";
			if(rand()%100<=80)
			{
				cout << "ANOTA UN PUNTO!" << endl;
				puntosb++;
				if (puntosb == 15)break;
			}
			else
			{
				cout << "Ha fallado..." << endl;
			}
		}
		if (puntosa == 15)
		{
			cout << "Tras un largo duelo, el jugador A ha ganado el partido #"<< juegos+1 <<" con una puntuacion de " << puntosa << " a " << puntosb << "!" << endl;
			winsA = winsA + 10;
		}
		else if(puntosb == 15)
		{
			cout << "Tras un largo duelo, el jugador B ha ganado el partido #" << juegos+1 << " con una puntuacion de " << puntosa << " a " << puntosb << "!" << endl;
		}
	}
	cout << "El jugador A tiene un " << winsA << "% de winrate" << endl;//el winrate a favor surge a partir de brindarle un 85% de chance de anotar punto en cada tiro
}
