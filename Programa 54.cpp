#include <iostream>
using namespace std;
int main()
{//viene de subida, si sube hoy, mañana puede subir por .60, si baja hoy, mañana puede subir por .30
    bool stonks = true;
    srand(time(0));
    for(int dias = 1; dias < 11 ;dias++)
    {
        if(stonks==true)
        {
            if(rand()%100>60)
            {
                cout << "los stonks han caido :(\n";
                stonks = false;
            }
            else
            {
                cout << "los stonks van para arriba :)\n";
            }
        }
        else
        {
            if (rand() % 100 > 30)
            {
                cout << "los stonks han caido :(\n";
                stonks = false;
            }
            else
            {
                cout << "los stonks van para arriba :)\n";
            }
        }
    }//la economía es deplorable
}
