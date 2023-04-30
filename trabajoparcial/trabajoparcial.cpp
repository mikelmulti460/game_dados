#include "pch.h"
#include <iostream>
#include <locale>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

using namespace System;
using namespace std;

void print_ascii_art();
int score_rules(int dice_value_1, int dice_value_2, int score_player, string player_name, int current_player);
int turn_rules(int dice_value_1, int dice_value_2, int turn_player, int current_player, string player_name);
void animar_dados(int value, int current_player, int x, int y);
string get_player_name(int player_number);
int menu();
int get_turns_number();
void star_turns(string player_name_1, string player_name_2, int turn_player_1, int turn_player_2);
void print_graph(int value, int current_player, int x, int y);
int launch_dice(int current_player, int x, int y);
void clean_old_turn(int current_player, bool new_turn);
// int turno_cada_jugador(int N, int jugador, int contador_jugador, int dado1, int dado2);
int main()
{
    int option = 0;
    while (true) {
        string player_name_1;
        string player_name_2;
        int score_player_1 = 0;
        int score_player_2 = 0;
        int dice_value_1 = 0;
        int dice_value_2 = 0;
        int turn_player_1;
        int turn_player_2;
        option = menu();
        if (option == 2)
        {
            break;
        }
        system("cls");
        player_name_1 = get_player_name(1);
        player_name_2 = get_player_name(2);
        int num_turnos = get_turns_number();
        turn_player_1 = num_turnos;
        turn_player_2 = num_turnos;
        system("cls");
        star_turns(player_name_1, player_name_2, turn_player_1, turn_player_2);
    }
    return 0;
}

void print_ascii_art()
{
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
    Sleep(2000);
    Console::SetCursorPosition(0, 0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Sleep(1);
            cout << "                       ";
        }
        cout << endl;
    }
    Console::SetCursorPosition(0, 0);
    system("cls");
}

int menu()
{
    int option = 1;
    char key;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
    print_ascii_art();
    cout << "Bienvenido al juego de dados" << endl << endl;
    cout << "Seleccione una opcion:" << endl;
    while (true) { 
        if (option == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            Console::SetCursorPosition(0, 3);
            cout << "-> (*) Jugar" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            Console::SetCursorPosition(0, 4);
            cout << "   ( ) Salir" << endl;
        }
        else {
            Console::SetCursorPosition(0, 3);
            cout << "   ( ) Jugar" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            Console::SetCursorPosition(0, 4);
            cout << "-> (*) Salir " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        Sleep(100);
        if (kbhit()) {
            // Leemos la tecla presionada
            key = getch();
            if (key == 72) { // Tecla de arriba
                option = 1;
            }
            else if (key == 80) { // Tecla de abajo
                option = 2;
            }
            else if (key == 13) { // Tecla enter
                break;
            }
        }
    }
    return option;
}

string get_player_name(int player_number)
{
    string player_name;
    cout << "Ingrese el nombre del jugador " << player_number << endl;
    cin >> player_name;
    return player_name;
}

int get_turns_number()
{
    int num_turnos;
    bool is_valid = false;
    while (is_valid == false)
    {
        cout << "Ingresar numero de turnos: ";
        cin >> num_turnos;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Debe ingresar un numero" << endl;
            continue;
        }
        if (num_turnos >= 2)
        {
            is_valid = true;
        }
        if (num_turnos >= 15)
        {
            is_valid = false;
        }
    }
    cin.get();
    return num_turnos;
}

void star_turns(
    string player_name_1,
    string player_name_2,
    int turn_player_1,
    int turn_player_2)
{
    string winner;
    int p1_x = 0;
    int p1_y = 0;
    int p2_x = 50;
    int p2_y = 0;
    int current_player = 0;
    int score_player_1 = 0;
    int score_player_2 = 0;
    int dice_value_1 = 0;
    int dice_value_2 = 0;

    srand(GetCurrentProcessId());

    while (turn_player_1 > 0 || turn_player_2 > 0)
    {
        if (turn_player_1 != 0)
        {
            current_player = 1;
            Console::SetCursorPosition(0, 0);
            cout << "Es el turno de " << player_name_1 << endl;
            cout << "Presione enter para lanzar sus dados" << endl;
            cout << "Turnos restantes: " << turn_player_1;
            cin.get();
            clean_old_turn(current_player, true);
            turn_player_1 = turn_player_1 - 1;
            dice_value_1 = launch_dice(current_player, 0, 3);
            dice_value_2 = launch_dice(current_player, 9, 3);
            score_player_1 = score_rules(dice_value_1, dice_value_2, score_player_1, player_name_1, current_player);
            turn_player_1 = turn_rules(dice_value_1, dice_value_2, turn_player_1, current_player, player_name_1);
            Console::SetCursorPosition(0, 2);
            cout << "Turnos restantes: " << turn_player_1;
            clean_old_turn(current_player, false);
        }
        else {
            Console::SetCursorPosition(0, 0);
            cout << "Se acabaron los turnos de" << player_name_1 << endl;
        }
        if (turn_player_2 != 0)
        {
            current_player = 2;
            Console::SetCursorPosition(60, 0);
            cout << "Es el turno de " << player_name_2 << endl;
            Console::SetCursorPosition(60, 1);
            cout << "Presione enter para lanzar sus dados" << endl;
            Console::SetCursorPosition(60, 2);
            cout << "Turnos restantes: " << turn_player_2;
            cin.get();
            clean_old_turn(current_player, true);
            turn_player_2 = turn_player_2 - 1;
            p2_x = p2_x + 9;
            dice_value_1 = launch_dice(current_player, 59, 3);
            p2_x = p2_x + 9;
            dice_value_2 = launch_dice(current_player, 68, 3);
            score_player_2 = score_rules(dice_value_1, dice_value_2, score_player_2, player_name_2, current_player);
            turn_player_2 = turn_rules(dice_value_1, dice_value_2, turn_player_2, current_player, player_name_2);
            Console::SetCursorPosition(60, 2);
            cout << "Turnos restantes: " << turn_player_2;
            clean_old_turn(current_player, false);
        } else {
            Console::SetCursorPosition(60, 0);
            cout << "Se acabaron los turnos de " << player_name_2 << endl;
        }
    }
    Console::SetCursorPosition(30, 21);
    cout << "Puntajes: " << endl;
    Console::SetCursorPosition(30, 22);
    cout << player_name_1 << ": " << score_player_1 << endl;
    Console::SetCursorPosition(30, 23);
    cout << player_name_2 << ": " << score_player_2 << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    Console::SetCursorPosition(30, 24);
    if (score_player_1 > score_player_2)
    {
        winner = player_name_1;
        
        cout << "EL GANADOR ES: " << winner << endl;
        
    }

    if (score_player_2 > score_player_1)
    {
        winner = player_name_2;
        
        cout << "EL GANADOR ES: " << winner << endl;
    }

    if (score_player_2 == score_player_1)
    {
        cout << "EMPATE" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Presione enter para continuar" << endl;
    cin.get();
    system("cls");
}

int launch_dice(int current_player, int x, int y)
{   
    int random_number = rand() % 6 + 1;
    animar_dados(random_number, current_player, x, y);
    return random_number;
}

int score_rules(int dice_value_1, int dice_value_2, int score_player, string player_name, int current_player)
{
    int score_change = 0;
    int current_x = 0 + (current_player == 2) * 60;
    int current_y = 12;
    if (dice_value_1 == dice_value_2)
    {
        score_change = (dice_value_1 + dice_value_2) * 2;
        score_player = score_player + score_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name << " ha sacado dobles, su puntaje se duplica!!!" << endl;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << "Su puntaje actual es: " << score_player << endl;
    }
    // Si la suma de los dados es un número par y no son dobles,
    // el jugador suma la mitad de la suma de los dados a su puntuación
    if ((dice_value_1 + dice_value_2) % 2 == 0 && dice_value_1 != dice_value_2)
    {
        score_change = (dice_value_1 + dice_value_2) / 2;
        score_player = score_player + score_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name << " ha ganado "<< score_change << " puntos con esta jugada"<< "                " << endl;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << "Su puntaje actual es: " << score_player << endl;
    }

    if ((dice_value_1 + dice_value_2) % 2 != 0)
    {
        score_change = (dice_value_1 + dice_value_2);
        score_player = score_player + score_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name << " ha ganado "<< score_change << " puntos por sacar una suma impar"<<"       " << endl;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << "Su puntaje actual es: " << score_player << endl;
    }

    if ((dice_value_1 + dice_value_2) > 10)
    {
        score_change = 5;
        score_player = score_player + score_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name << " ha ganado "<< score_change << " puntos por sacar una suma mayor a 10" << endl;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << "Su puntaje actual es: " << score_player << endl;
    }

    if ((dice_value_1 + dice_value_2) < 5)
    {
        score_change = 5;
        score_player = score_player - score_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name << " ha perdido "<< score_change << " puntos por sacar una suma menor a 5" << endl;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << "Su puntaje actual es: " << score_player << endl;
    }
    if (score_player<0)
    {
        score_player = 0;
    }
    current_y = current_y + 1;
    Console::SetCursorPosition(current_x, current_y);
    cout << "Su puntaje final en este turno es: " << score_player << endl;
    return score_player;
}

int turn_rules(int dice_value_1, int dice_value_2, int turn_player, int current_player, string player_name)
{    
    int current_x = 0 + (current_player == 2) * 60;
    int current_y = 18;
    int turn_change = 0;
    if (dice_value_1 == 6 && dice_value_2 == 6)
    {
        turn_change = 1;
        turn_player = turn_player + turn_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name <<" ha sacado dobles 6, por lo que tiene un turno extra" << endl;
    }

    if (dice_value_1 == 1 || dice_value_2 == 1)
    {
        turn_change = 1;
        turn_player = turn_player - turn_change;
        current_y = current_y + 1;
        Console::SetCursorPosition(current_x, current_y);
        cout << player_name << " ha sacado un 1, por lo que pierde un turno"<< endl; 
    }
    if (turn_player<0)
    {
        turn_player = 0;
    }
    return turn_player;
}

void clean_old_turn(int current_player, bool new_turn)
{
    
    if (!new_turn){
        int initial_y = 0;
        int initial_x = 0 + (current_player - 1) * 60;
        Console::SetCursorPosition(initial_x, 18);
        cout << "                                                         " << endl;
        Console::SetCursorPosition(initial_x, 0);
        cout << "                                                         " << endl;
        cout << "                                                         " << endl;
    }else {
        int current_x = 0 + (current_player - 1) * 60;
        int current_y = 12;
        
        for (int i = 0; i < 7; i++)
        {
            Console::SetCursorPosition(current_x, 3+i);
            cout << "                                                        " << endl;
        }
        Console::SetCursorPosition(current_x, current_y);
        for (int i = 0; i < 8; i++)
        {
            Console::SetCursorPosition(current_x, current_y+i);
            cout << "                                                        " << endl;
        }
    }
}
//int menu()
//{
//    print_ascii_art();
//    cout << "Bienvenido al juego de dados" << endl;
//    cout << "(*) Presione enter para continuar" << endl;
//    cout << "(*) Presione CTRL + E para salir" << endl;
//    cin.get();
//    system("cls");
//}
void print_graph(int value, int current_player, int x, int y)
{
    // Establecer el color correspondiente
    if (current_player == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red for player 1

        // cout << "10 puntos"

        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), "negro"); // Red for player 1
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Red for player 2
    }
    // Imprimir el gráfico del dado
    y = y + 1;
    cout << "+-------+" << endl;
    Console::SetCursorPosition(x, y);
    if (value == 1)
    {
        cout << "|       |" << endl;
        Console::SetCursorPosition(x, y+1);
        cout << "|   *   |" << endl;
        Console::SetCursorPosition(x, y+2);
        cout << "|       |" << endl;
        Console::SetCursorPosition(x, y+3);
    }
    else if (value == 2)
    {
        cout << "|     * |" << endl;
        Console::SetCursorPosition(x, y+1);
        cout << "|       |" << endl;
        Console::SetCursorPosition(x, y+2);
        cout << "| *     |" << endl;
        Console::SetCursorPosition(x, y+3);
    }
    else if (value == 3)
    {
        cout << "|     * |" << endl;
        Console::SetCursorPosition(x, y+1);
        cout << "|   *   |" << endl;
        Console::SetCursorPosition(x, y+2);
        cout << "| *     |" << endl;
        Console::SetCursorPosition(x, y+3);
    }
    else if (value == 4)
    {
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+1);
        cout << "|       |" << endl;
        Console::SetCursorPosition(x, y+2);
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+3);
    }
    else if (value == 5)
    {
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+1);
        cout << "|   *   |" << endl;
        Console::SetCursorPosition(x, y+2);
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+3);
    }
    else if (value == 6)
    {
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+1);
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+2);
        cout << "| *   * |" << endl;
        Console::SetCursorPosition(x, y+3);
    }
    cout << "+-------+" << endl;
    Console::SetCursorPosition(x, y+4);

    // Volver al color normal
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void animar_dados(int value, int current_player, int x, int y)
{
    // Establecer el color correspondiente
    if (current_player == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Rojo para jugador 1
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde para jugador 2
    }

    // Animar los dados
    for (int i = 1; i <= 6; i++)
    {
        Console::SetCursorPosition(x, y); 
        print_graph(i, current_player, x, y);
        Sleep(700);
    }
    Console::SetCursorPosition(x, y); 
    print_graph(value, current_player, x, y);
    // Volver al color normal
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}