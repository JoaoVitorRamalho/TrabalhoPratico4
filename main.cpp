#include <iostream>
#include <windows.h>
#include "list.cpp"
#include "list.hpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    //aqui criamos as variaveis basicas e definimos a senha
    int idlines = 1;
    string password;
    string correctPass = "amogus";

    //chamamos a função que cria as linhas já pré-definidas
    List lines;
    CreateEmptyList(&lines);
    Autofill(&lines, &idlines);
    //aqui mostramos ao usuário todas as linhas e paradas disponíveis
    PrintList2(&lines.Last->item.stops);
    cout << "--------------------------------------\n\n";
    int esc;
    //aqui o while repete o menu enquanto o usuário não sair do programa
    while (esc != 3)
    {
        Menu();

        cin >> esc;
        //lembrando que apenas o adiministrador que saber a senha tem acesso ao menu do administrador
        if (esc == 1)
        {
            system("cls");
            FindLine(&lines);
        }
        else if (esc == 2)
        {
            system("cls");

            cout << "Insert admin password: ";

            cin >> password;

            if (password == correctPass)
            {
                system("cls");
                Maintenance(&lines, &idlines);
            }
            else
            {
                cout << "\nWrong password.\nConsult your passwords if you have forgotten.\n";
            }
        }
    }
    return 0;
}