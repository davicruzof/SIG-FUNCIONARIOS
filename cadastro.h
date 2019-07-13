#include <iostream>
#include <conio2.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include "metodos.h"
using namespace std;

void opcMenu();
void tela();


struct funcionario
{
    int id;
    char nome[15];
    char cargo[15];
    char sexo;
    char local[15];
    float salario;
};

funcionario f;

funcionario clienteVazio = {0," "," ",' '," ",0.0};

void cadastrodefuncionarios()
{
    int cadastrado;

    char novoCad;

    char* arquivo = "cadastro.txt";

    ofstream outCadastro(arquivo,ios::app);
    ifstream inCadastro(arquivo);

    if (outCadastro.fail( ))
    {
        cout << "A abertura do arquivo de saída falhou.\n";
        exit(1);
    }

    if(inCadastro.fail())
    {
        cout << "A leitura do arquivo de saída falhou.\n";
        exit(1);
    }

    tela();

    gotoxy(30,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " CADASTRO ";
    do
    {
        gotoxy(10,10);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " ID ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(20+i,10);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(21,10);
        textcolor(WHITE);
        cin >> cadastrado;

        inCadastro.seekg((cadastrado - 1) * sizeof(funcionario));
        inCadastro.read((char *)(&cadastrado - 1),sizeof(funcionario));

        if( f.id == cadastrado)
        {
            gotoxy(10,12);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << "Este ID ja esta cadastrado";
            gotoxy(10,14);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << "Tente cadastrar novamente com um novo ID";
            _sleep(3000);
            cadastrodefuncionarios();
        }
        else
        {
            if( cadastrado > 0 || cadastrado <= 100)
            {
                f.id = cadastrado;
                gotoxy(10,12);
                textcolor(WHITE);
                textbackground(GREEN);
                cout << " NOME ";

                for (int i = 0; i < 15; i++)
                {
                    gotoxy(20+i,12);
                    textbackground(GREEN);
                    cout << '\0';
                }

                gotoxy(21,12);
                textcolor(WHITE);
                cin >> f.nome;

                gotoxy(10,14);
                textcolor(WHITE);
                textbackground(GREEN);
                cout << " CARGO ";

                for (int i = 0; i < 15; i++)
                {
                    gotoxy(20+i,14);
                    textbackground(GREEN);
                    cout << '\0';
                }

                gotoxy(21,14);
                textcolor(WHITE);
                cin >> f.cargo;

                gotoxy(10,16);
                textcolor(WHITE);
                textbackground(GREEN);
                cout << " SEXO (F/M) ";

                for (int i = 0; i < 5; i++)
                {
                    gotoxy(24+i,16);
                    textbackground(GREEN);
                    cout << '\0';
                }

                gotoxy(26,16);
                textcolor(WHITE);
                cin >> f.sexo;

                gotoxy(10,18);
                textcolor(WHITE);
                textbackground(GREEN);
                cout << " LOCAL ";

                for (int i = 0; i < 10; i++)
                {
                    gotoxy(20+i,18);
                    textbackground(GREEN);
                    cout << '\0';
                }

                gotoxy(21,18);
                textcolor(WHITE);
                cin >> f.local;

                gotoxy(10,20);
                textcolor(WHITE);
                textbackground(GREEN);
                cout << " SALARIO ";

                for (int i = 0; i < 10; i++)
                {
                    gotoxy(20+i,20);
                    textbackground(GREEN);
                    cout << '\0';
                }

                gotoxy(21,20);
                textcolor(WHITE);
                cin >> f.salario;

                outCadastro.seekp((f.id - 1) * sizeof(funcionario));
                outCadastro.write((const char *)(&f),sizeof(funcionario));

                gotoxy(10,22);
                textcolor(WHITE);
                textbackground(GREEN);
                cout << " CADASTRO REALIZADO COM SUCESSO ";
            }
        }

        gotoxy(10,24);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " REALIZAR NOVO CADASTRO (S/N) ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(20+i,24);
            textbackground(GREEN);
            cout << '\0';
        }

        gotoxy(43,24);
        textcolor(WHITE);
        cin >> novoCad;

        outCadastro.close();
    }
    while(novoCad == 's' || novoCad == 'S');

    opcMenu();

}

void listar()
{
    int k=0;

    char* arquivo = "cadastro.txt";
    ifstream inCadastro(arquivo);

    if (inCadastro.fail( ))
    {
        cout << "A abertura do arquivo de entrada falhou.\n";
        exit(1);
    }

    inCadastro.read((char *)(&f),sizeof(funcionario));

    tela();

    gotoxy(20,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " FUNCIONARIOS CADASTRADOS ";

//    LENDO O ARQUIVO PARA LISTAR NA TELA

    while (!inCadastro.eof())
    {
        if(f.id != 0)
        {
            gotoxy(5,10);
            textcolor(WHITE);
            textbackground(RED);
            cout << " ID ";
            gotoxy(5,12+k);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << " " << f.id << " ";
            gotoxy(10,10);
            textcolor(WHITE);
            textbackground(RED);
            cout << " NOME ";
            gotoxy(10,12+k);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << " " << f.nome << " ";
            gotoxy(20,10);
            textcolor(WHITE);
            textbackground(RED);
            cout << " CARGO ";
            gotoxy(20,12+k);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << " " << f.cargo << " ";
            gotoxy(36,10);
            textcolor(WHITE);
            textbackground(RED);
            cout << " SEXO ";
            gotoxy(36,12+k);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << " " << f.sexo << " ";
            gotoxy(44,10);
            textcolor(WHITE);
            textbackground(RED);
            cout << " SALARIO ";
            gotoxy(44,12+k);
            textcolor(WHITE);
            textbackground(GREEN);
            printf("%.3f\n",f.salario);

            k++;
        }

        inCadastro.read((char *)(&f),sizeof(funcionario));
    }

    getch();

    inCadastro.close( );

    opcMenu();
}

void alterar()
{
    int idbusca;
    char novoalteracao;

    tela();

    char* arquivo = "cadastro.txt";

    gotoxy(20,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " ALTERAR SALARIO ";

    do
    {
        ofstream outCadastro(arquivo,ios::ate);

        if (outCadastro.fail( ))
        {
            cout << "A abertura do arquivo de saida falhou.\n";
            exit(1);
        }

        gotoxy(10,10);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " QUAL O ID QUE DESEJA ALTERAR O SALARIO ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(55+i,10);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(56,10);
        textcolor(WHITE);
        cin >> idbusca;

        gotoxy(10,12);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " QUAL O NOVO SALARIO ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(30+i,12);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(31,12);
        textcolor(WHITE);
        cin >>  f.salario;

        outCadastro.seekp((idbusca - 1)*sizeof(funcionario));
        outCadastro.write((const char*)(&f), sizeof(funcionario));

        gotoxy(10,22);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " SALARIO ALTERADO COM SUCESSO ";

        outCadastro.close();

        gotoxy(10,24);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " REALIZAR NOVA ALTERACAO (S/N) ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(45+i,24);
            textbackground(GREEN);
            cout << '\0';
        }

        gotoxy(47,24);
        textcolor(WHITE);
        cin >> novoalteracao;
    }
    while(novoalteracao == 's' || novoalteracao == 'S');

    opcMenu();

}


void zerar()
{
    int iderase;
    char erase,novoalteracao;

    tela();

    char* arquivo = "cadastro.txt";
    ofstream outCadastro(arquivo,ios::ate);

    if (outCadastro.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    gotoxy(20,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " REMOVER FUNCIONARIO ";

    do
    {
        gotoxy(7,10);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " QUAL O ID DO FUNCIONARIO QUE DESEJA REMOVER ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(55+i,10);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(56,10);
        textcolor(WHITE);
        cin >> iderase;

        outCadastro.seekp((iderase - 1) * sizeof(funcionario));
        outCadastro.write((const char *)(&clienteVazio),sizeof(funcionario));
        outCadastro.close();

        gotoxy(10,22);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << "  FUNCIONARIO REMOVIDO COM SUCESSO ";

        gotoxy(10,24);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " REMOVER OUTRO FUNCIONARIO (S/N) ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(45+i,24);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(47,24);
        textcolor(WHITE);
        cin >> novoalteracao;
    }
    while(novoalteracao == 's' || novoalteracao == 'S');

    opcMenu();
}

void blocos()
{
    char* arquivo = "cadastro.txt";
    ofstream outCadastro;
    outCadastro.open(arquivo,ios::out | ios::trunc);

    if (outCadastro.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    //CRIANDO OS BLOCOS DENTRO DO ARQUIVO
    for (int i = 0; i < 100; i++)
    {
        outCadastro.write((const char *)(&clienteVazio),sizeof(funcionario));
    }

    outCadastro.close( );
}


void tela()
{
    //cor de fundo
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<60; j++)
        {
            gotoxy(4+j,3+i);
            textcolor(BLUE);
            printf("\xdb");
        }
    }
    printf("\n");
}
