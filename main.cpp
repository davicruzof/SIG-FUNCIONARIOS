#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio2.h>
#include <locale.h>
#include "listar.h"
#include "cadastro.h"
#define txt textcolor
//#define back textbackgroud
#define xy gotoxy

using namespace std;

void opcMenu();
void tela();

int main()
{
    opcMenu();

    cout << "\n\n\n\n";

    return 0;
}

void opcMenu()
{
    int opc;
    tela();

    xy(25,5);
    txt(WHITE);
    textbackground(GREEN);
    cout << " SEJA BEM VINDO ";
    xy(20,10);
    txt(WHITE);
    textbackground(GREEN);
    cout << " 1 - CRIAR ARQUIVO DE INICIALIZACAO ";
    xy(20,12);
    txt(WHITE);
    textbackground(GREEN);
    cout << " 2 - CADASTRAR FUNCIONARIO ";
    xy(20,14);
    txt(WHITE);
    textbackground(GREEN);
    cout << " 3 - LISTAR FUNCIONARIOS ";
    xy(20,16);
    txt(WHITE);
    textbackground(GREEN);
    cout << " 4 - ATUALIZAR SALARIO ";
    xy(20,18);
    txt(WHITE);
    textbackground(GREEN);
    cout << " 5 - REMOVER FUNCIONARIO ";
    xy(20,20);
    txt(WHITE);
    textbackground(GREEN);
    cout << " 6 - SAIR ";

    for (int i = 0; i < 5; i++)
    {
        xy(20+i,22);
        textbackground(GREEN);
        cout << '\0';
    }
    xy(22,22);
    txt(WHITE);
    cin >> opc;



    switch(opc)
    {
    case 1:
        xy(25,5);
        txt(WHITE);
        textbackground(GREEN);
        cout << " SEJA BEM VINDO ";
        xy(20,10);
        txt(WHITE);
        textbackground(RED);
        cout << " 1 - CRIAR ARQUIVO DE INICIALIZACAO ";
        blocos();
        xy(20,8);
        txt(WHITE);
        textbackground(GREEN);
        cout << " ARQUIVO CRIADO COM SUCESSO ";
        _sleep(2000);
        opcMenu();
        break;
    case 2:
        xy(20,12);
        txt(WHITE);
        textbackground(RED);
        cout << " 1 - CADASTRAR FUNCIONARIO ";
        _sleep(900);
        cadastrodefuncionarios();
        break;
    case 3:
        xy(20,14);
        txt(WHITE);
        textbackground(RED);
        cout << " 2 - LISTAR FUNCIONARIOS ";
        _sleep(900);
        listar();
        break;
    case 4:
        xy(20,16);
        txt(WHITE);
        textbackground(RED);
        cout << " 3 - ATUALIZAR SALARIO ";
        _sleep(900);
        alterar();
        break;
    case 5:
        xy(20,18);
        txt(WHITE);
        textbackground(RED);
        cout << " 4 - REMOVER FUNCIONARIO ";
        zerar();
        break;
    case 6:
        exit(1);
        break;
    default:
        xy(20,25);
        txt(WHITE);
        textbackground(RED);
        cout << "OPCAO NAO DISPONIVEL";
        break;
    };

};
