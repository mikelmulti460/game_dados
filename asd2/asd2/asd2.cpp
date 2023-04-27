#include "pch.h"
#include "pch.h"
#include <iostream>
#include <cstdlib>//rand
#include <ctime>
#include <windows.h>
// Añade paquete de idiomas
#include <locale.h>
using namespace std;

int lanzar_dado();
void imprimir_grafico(int valor, bool es_jugador);
int jugar_partida(int valor_objetivo, int num_partidas);
int menu();
int leer_valor_objetivo();
int leer_num_partidas();
char continuar();
void imprimir_ganador(int ganador);

int main() {
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish");
    // En el caso de srand, esta función se utiliza para inicializar el generador de números pseudoaleatorios.
    // Al pasar como semilla el valor devuelto por time, se asegura de que la secuencia de números generados varíe con cada ejecución del programa.
    srand(time(NULL));
    int opcion, num_partidas;
    int valor_objetivo = 0;
    int ganador = 0;
    //bool jugar_de_nuevo;
    char respuesta; // nueva variable para permitir jugar de nuevo

    cout << "Bienvenido al juego de los dados" << endl;
    do {
        opcion = menu();
        switch (opcion) {
        case 1:
            valor_objetivo = leer_valor_objetivo();
            break;
        case 2:
            valor_objetivo = rand() % 11 + 2;
            cout << "El valor objetivo generado al azar es: " << valor_objetivo << endl;
            break;
        case 3:
            cout << "Saliendo del juego de los dados..." << endl;
            return 0;
        default:
            cout << "Opción inválida, seleccione una opción válida" << endl;
            break;
        }

        num_partidas = leer_num_partidas();

        ganador = jugar_partida(valor_objetivo, num_partidas);

        imprimir_ganador(ganador);

        respuesta = continuar(); // cambiar el tipo de variable
        //system("cls"); // Limpiar la pantalla

    } while (respuesta == 'S');
    cout << "Gracias por jugar al juego de los dados." << endl;
    return 0;
}



int lanzar_dado() {
    return rand() % 6 + 1;
}


void imprimir_grafico(int valor, bool es_jugador) {
    // Establecer el color correspondiente
    if (es_jugador) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Rojo para el jugador
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde para el computador
    }

    // Imprimir el gráfico del dado
    cout << "+-------+" << endl;
    if (valor == 1) {
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
    }
    else if (valor == 2) {
        cout << "|     * |" << endl;
        cout << "|       |" << endl;
        cout << "| *     |" << endl;
    }
    else if (valor == 3) {
        cout << "|     * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *     |" << endl;
    }
    else if (valor == 4) {
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
    }
    else if (valor == 5) {
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
    }
    else if (valor == 6) {
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
    }
    cout << "+-------+" << endl;

    // Volver al color normal
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


int jugar_partida(int valor_objetivo, int num_partidas) {
    int jugador = 0;
    int computadora = 0;
    int intentos = 0;
    int dado1, dado2;
    int ganador = 0;
    bool hay_ganador = false;

    while (intentos < num_partidas && !hay_ganador) {
        // Imprimir el número de partida
        cout << endl << "Partida " << (intentos + 1) << endl;

        // Lanzar los dados del jugador y mostrar los resultados
        dado1 = lanzar_dado();
        dado2 = lanzar_dado();
        jugador = dado1 + dado2;
        cout << "Ptos Jugador: " << jugador << endl;
        imprimir_grafico(dado1, true);
        imprimir_grafico(dado2, true);
        cout << endl;

        // Lanzar los dados de la computadora y mostrar los resultados
        dado1 = lanzar_dado();
        dado2 = lanzar_dado();
        computadora = dado1 + dado2;
        cout << "Ptos Computadora: " << computadora << endl;
        imprimir_grafico(dado1, false);
        imprimir_grafico(dado2, false);
        cout << endl;

        // Sumar los resultados de los dados y verificar si se alcanzó el valor objetivo
        if (jugador == valor_objetivo) {
            cout << "El jugador ha alcanzado el valor objetivo " << valor_objetivo << " en la partida " << (intentos + 1) << "!" << endl;
            ganador = 1;
            hay_ganador = true;
        }
        else if (computadora == valor_objetivo) {
            cout << "La computadora ha alcanzado el valor objetivo " << valor_objetivo << " en la partida " << (intentos + 1) << "!" << endl;
            ganador = 2;
            hay_ganador = true;
        }

        // Salir del bucle si ya se jugaron todas las partidas
        if (intentos == num_partidas) {
            break;
        }

        // Mostrar el número de intentos y continuar a la siguiente iteración
        intentos++;
        cout << "Fin de la partida " << (intentos) << endl;
        system("pause");
    }

    return ganador;
}


int menu() {
    int opcion;

    do {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Ingresar valor objetivo" << endl;
        cout << "2. Generar valor objetivo al azar" << endl;
        cout << "3. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 3) {
            cout << "Opción invalida, seleccione una opcion valida" << endl;
        }
    } while (opcion < 1 || opcion > 3);

    return opcion;
}



int leer_valor_objetivo() {
    int valor_objetivo;
    do {
        cout << "Ingrese el valor objetivo (entre 2 y 12): ";
        cin >> valor_objetivo;
        if (valor_objetivo < 2 || valor_objetivo > 12) {
            cout << "Valor objetivo inválido, ingrese un valor objetivo válido." << endl;
        }
    } while (valor_objetivo < 2 || valor_objetivo > 12);
    return valor_objetivo;
}


int leer_num_partidas() {
    int num_partidas;
    do {
        cout << "Ingrese el numero de partidas: ";
        cin >> num_partidas;

        if (num_partidas < 1) {
            cout << "Número de partidas inválido, ingrese un número de partidas válido." << endl;
        }
    } while (num_partidas < 1);
    return num_partidas;
}


char continuar() {
    char respuesta;
    do {
        cout << "¿Desea continuar? (S/N): ";
        cin >> respuesta;
        respuesta = toupper(respuesta);
    } while (respuesta != 'S' && respuesta != 'N');
    return respuesta;
}



void imprimir_ganador(int ganador) {
    if (ganador == 1) {
        cout << "¡El jugador ha ganado el juego!" << endl;
    }
    else if (ganador == 2) {
        cout << "¡El computador ha ganado el juego!" << endl;
    }
    else {
        cout << "No hubo ganador en ninguna de las partidas" << endl;
    }
}
}
