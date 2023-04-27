#include <iostream>
using namespace std;
int num_turnos=0;

using namespace std;

int reglas_puntos(int valor_dado_1, int valor_dado_2, int puntos_jugador);
int regla_turnos(int valor_dado_1, int valor_dado_2, int turnos_jugador);

int main()
{

 do{
    cout<<"Ingresar numero de turnos";
    cin>>num_turnos;
    if(num_turnos<=2 && num_turnos>=15)
    {
        cout<<"Dato ingresado no valido.";
    }

 }while(num_turnos<=2 && num_turnos>=15);




    return 0;
}


int reglas_puntos(int valor_dado_1, int valor_dado_2, int puntos_jugador){
    if (valor_dado_1 == 1 && valor_dado_2 == 1) {
        puntos_jugador = puntos_jugador + ((valor_dado_1 + valor_dado_2)*2);
        return puntos_jugador;
    }

    //Si la suma de los dados es un número par y no son dobles,
    //el jugador suma la mitad de la suma de los dados a su puntuación
    if ((valor_dado_1 + valor_dado_2) % 2 == 0 && valor_dado_1 != valor_dado_2) {
        puntos_jugador = puntos_jugador + ((valor_dado_1 + valor_dado_2)/2);
        return puntos_jugador;
    }


}

int regla_turnos(int valor_dado_1, int valor_dado_2, int puntos_jugador){

}





        // validamos que se ingrese un número 
        // if (cin.fail()) {
        //     cin.clear();
        //     cin.ignore(1000, '\n');
        //     cout << "Debe ingresar un numero" << endl;
        //     num_turnos = 0;
        // }
    // int num_turnos;
    // do {
    //     cout << "Ingrese el numero de turnos: ";
    //     cin >> num_turnos;


    // } while (num_turnos < 1 || num_turnos > 16);


    // if (jugador1){
    //     cout << "Turno del jugador 2" << endl;
    //     "presione 1 para lanzar sus dados"
    //     dado1 = lanzar_dados();
    //     dado2 = lanzar_dados();
    //     puntos_jugador1 = reglas_puntos(num_turnos, dado1, dado2, puntos_jugador1);
    //     turnos_jugador = reglas_turnos(num_turnos, dado1, dado2, turnos_jugador);
    // }