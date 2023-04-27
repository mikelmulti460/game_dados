
#include <iostream>
using namespace std;
int num_turnos = 0;

int main()
{
    do {
        cout << "Ingresar numero de turnos";
        cin >> num_turnos;
        if (num_turnos <= 2 && num_turnos >= 15)
        {
            cout << "Dato ingresado no valido.";
        }

    } while (num_turnos <= 2 && num_turnos >= 15);




    return 0;
}
