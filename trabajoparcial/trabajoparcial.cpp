#include "pch.h"
#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;
int num_turnos = 0;

using namespace std;

int score_rules(int die_value_1, int die_value_2, int score_player);
int turn_rules(int die_value_1, int die_value_2, int turn_player);
void print_ascii_art();
string get_player_name(int player_number);
void menu();
int get_turns_number();

int get_turn_player();
void star_turns(string player_name_1, string player_name_2, int turn_player_1, int turn_player_2);

int print_(int winner);
int launch_dice();
//int turno_cada_jugador(int N, int jugador, int contador_jugador, int dado1, int dado2);


int main()
{
    string player_name_1;
    string player_name_2;
    int score_player_1 = 0;
    int score_player_2 = 0;
    int die_value_1 = 0;
    int die_value_2 = 0;
    int turn_player_1;
    int turn_player_2;
    menu();
    player_name_1 = get_player_name(1);
    player_name_2 = get_player_name(2);
    num_turnos = get_turns_number();
    turn_player_1 = num_turnos;
    turn_player_2 = num_turnos;
    star_turns(player_name_1, player_name_2,turn_player_1,turn_player_2);
    return 0;
}


int score_rules(int die_value_1, int die_value_2, int score_player) {
    if (die_value_1 == 1 && die_value_2 == 1) {
        score_player = score_player + ((die_value_1 + die_value_2) * 2);
        return score_player;
    }

    //Si la suma de los dados es un número par y no son dobles,
    //el jugador suma la mitad de la suma de los dados a su puntuación
    if ((die_value_1 + die_value_2) % 2 == 0 && die_value_1 != die_value_2) {
        score_player = score_player + ((die_value_1 + die_value_2) / 2);
        return score_player;
    }

    if ((die_value_1 + die_value_2) % 2 != 0) {
        score_player = score_player + (die_value_1 + die_value_2);
        return score_player;
    }

    if ((die_value_1 + die_value_2) > 10) {
        score_player = score_player + 5;
        return score_player;
    }

    if ((die_value_1 + die_value_2) < 5) {
        score_player = score_player - 5;
        return score_player;
    }
}

int turn_rules(int die_value_1, int die_value_2, int turn_player) {
  do
     {
    if (die_value_1 == 6 && die_value_2 == 6) {
        turn_player = turn_player + 1;
    }

    if (die_value_1 == 1) {
        turn_player = turn_player - 1;
    }
        if (die_value_2 == 1) {
        turn_player = turn_player - 1;
    }
     } while (turn_player>0);
    return turn_player;
}

int get_turns_number() {
    int num_turnos;
    do {
        cout << "Ingresar numero de turnos: ";
        cin >> num_turnos;
        if (num_turnos <= 2 && num_turnos >= 15)
        {
            cout << "Dato ingresado no valido.";
             if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Debe ingresar un numero" << endl;
        }
        }
       

    } while (num_turnos <= 2 && num_turnos >= 15);
    return num_turnos;
}

void menu(){
    print_ascii_art();
    cout << "Bienvenido al juego de dados" << endl;
    cout << "Presione enter para continuar" << endl;
    cin.get();
    system("cls");
}

string get_player_name(int player_number){
    string player_name;
    cout << "Ingrese el nombre del jugador " << player_number << endl;
    cin >> player_name;
    return player_name;
}

void print_ascii_art(){
    string ascii_art = R"(                          .         .                                                                          
        8 888888888o.            ,8.       ,8.                   .8.           ,o888888o.     8 8888     ,o888888o.    
        8 8888    `^888.        ,888.     ,888.                 .888.         8888     `88.   8 8888    8888     `88.  
        8 8888        `88.     .`8888.   .`8888.               :88888.     ,8 8888       `8.  8 8888 ,8 8888       `8. 
        8 8888         `88    ,8.`8888. ,8.`8888.             . `88888.    88 8888            8 8888 88 8888           
        8 8888          88   ,8'8.`8888,8^8.`8888.           .8. `88888.   88 8888            8 8888 88 8888           
        8 8888          88  ,8' `8.`8888' `8.`8888.         .8`8. `88888.  88 8888            8 8888 88 8888           
        8 8888         ,88 ,8'   `8.`88'   `8.`8888.       .8' `8. `88888. 88 8888   8888888  8 8888 88 8888           
        8 8888        ,88',8'     `8.`'     `8.`8888.     .8'   `8. `88888.`8 8888       .8'  8 8888 `8 8888       .8' 
        8 8888    ,o88P' ,8'       `8        `8.`8888.   .888888888. `88888.  8888     ,88'   8 8888    8888     ,88'  
        8 888888888P'   ,8'         `         `8.`8888. .8'       `8. `88888.  `8888888P'     8 8888     `8888888P'    
                                                        .         .                                                    
            ,o888888o.          .8.                   ,8.       ,8.          8 8888888888                             
            8888     `88.       .888.                 ,888.     ,888.         8 8888                                   
        ,8 8888       `8.     :88888.               .`8888.   .`8888.        8 8888                                   
        88 8888              . `88888.             ,8.`8888. ,8.`8888.       8 8888                                   
        88 8888             .8. `88888.           ,8'8.`8888,8^8.`8888.      8 888888888888                           
        88 8888            .8`8. `88888.         ,8' `8.`8888' `8.`8888.     8 8888                                   
        88 8888   8888888 .8' `8. `88888.       ,8'   `8.`88'   `8.`8888.    8 8888                                   
        `8 8888       .8'.8'   `8. `88888.     ,8'     `8.`'     `8.`8888.   8 8888                                   
            8888     ,88'.888888888. `88888.   ,8'       `8        `8.`8888.  8 8888                                   
            `8888888P' .8'       `8. `88888. ,8'         `         `8.`8888. 8 888888888888
    )";
    cout << ascii_art << endl;

}
void print_graph(int value, int current_player ) {
    // Establecer el color correspondiente
    if (current_player == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red for player 1
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Red for player 2
    }
    // Imprimir el gráfico del dado
    cout << "+-------+" << endl;
    if (value == 1) {
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
    }
    else if (value == 2) {
        cout << "|     * |" << endl;
        cout << "|       |" << endl;
        cout << "| *     |" << endl;
    }
    else if (value == 3) {
        cout << "|     * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *     |" << endl;
    }
    else if (value == 4) {
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
    }
    else if (value == 5) {
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
    }
    else if (value == 6) {
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
    }
    cout << "+-------+" << endl;

    // Volver al color normal
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


int launch_dice(int current_player) {
    int random_number = rand() % 6 + 1;
    print_graph(random_number, current_player);
    return random_number;
}

// validamos que se ingrese un n�mero 
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
//     score_player1 = score_rules(num_turnos, dado1, dado2, score_player1);
//     turn_player = turn_rules(num_turnos, dado1, dado2, turn_player);
// }



void star_turns(
    string player_name_1,
    string player_name_2,
    int turn_player_1,
    int turn_player_2
){
    string winner,
    int score_player_1 = 0;
    int score_player_2 = 0;
    int dice_value_1 = 0;
    int dice_value_2 = 0;
    

    while(turn_player_1 != 0 || turn_player_2 != 0 ){
        if (turn_player_1 != 0){
            cout << "Es el turno de " << player_name_1<< endl;
            cout << "Presione enter para lanzar sus dados" << endl;
            cin.get();
            turn_player_1--;
            //dice_value_1 = lanzar_dado();
            //dice_value_2 = lanzar_dado();
            score_player_1 = score_rules(dice_value_1, dice_value_2, score_player_1);
            turn_player_1 = turn_rules(dice_value_1, dice_value_2, turn_player_1);
        }
        if (turn_player_2 != 0){
            cout << "Es el turno de " << player_name_2 << endl;
            cout << "Presione enter para lanzar sus dados" << endl;
            cin.get();
            turn_player_2--;
            //dice_value_1 = lanzar_dado();
            //dice_value_2 = lanzar_dado();
            score_player_2 = score_rules(dice_value_1, dice_value_2, score_player_2);
            turn_player_2 = turn_rules(dice_value_1, dice_value_2, turn_player_2);
        }
    }

        cout << "Puntaje: " << endl;
        cout <<player_name_1<<": " << score_player_1 << endl;
        cout <<player_name_2<<": " << score_player_2 << endl;

        if (score_player_1>score_player_2){
                winner= player_name_1;
                cout << "El ganador es: " << winner << endl;
        }

        if (score_player_2>score_player_1){
                winner= player_name_2;
                cout << "El ganador es: " << winner << endl;
        }

        if (score_player_2==score_player_1){
            cout << "Empate" << endl;
        }
    //TODO: Definir Ganador, puntaje
}





