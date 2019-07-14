#include <iostream>
#include <conio2.h>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void opcMenu();
void tela();

constexpr const char* arquivo = "cadastro.txt";

struct funcionario
{
    int id;
    char nome[15];
    char cargo[15];
    char sexo;
    char local[15];
    float salario;
};

void inicializacao()
{
    fstream inicializar(arquivo,ios::out|ios::ate|ios::trunc);

    funcionario clienteVazio = {0," "," ",' '," ",0.0};

    if (inicializar.fail( ))
    {
        cout << "A abertura do arquivo de inicializacao falhou.\n";
        exit(1);
    }

    //CRIANDO OS BLOCOS DENTRO DO ARQUIVO

    for (int i = 0; i <= 100; i++)
    {
        inicializar.write((const char *)(&clienteVazio),sizeof(funcionario)); // ESCREVENDO 100 FUNCIONARIOS VAZIOS
    }

    inicializar.close( );
}

funcionario f;

ofstream outCadastro;
ifstream inCadastro;

void cadastrodefuncionarios()
{
    int cadastrado;

    fstream cadastro(arquivo,ios::in|ios::out|ios::ate);

    if(cadastro.fail())
    {
        cout << "A leitura do arquivo de leitura falhou.\n";
        exit(1);
    }

    char novoCad;

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

        cadastro.seekg((cadastrado - 1) * sizeof(funcionario));
        cadastro.read((char *)(&f),sizeof(funcionario));

        if( f.id == cadastrado )
        {
            gotoxy(10,12);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << "Este ID ja esta cadastrado";
            gotoxy(10,14);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << "Tente cadastrar novamente com um novo ID";
            Sleep(3000);
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

                cadastro.seekp((cadastrado - 1) * sizeof(funcionario));
                cadastro.write((const char *)(&f),sizeof(funcionario));

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
    }
    while(novoCad == 's' || novoCad == 'S');

    cadastro.close();

    opcMenu();

}

void listar()
{
    int k=0;

    inCadastro.open(arquivo,ios::in);

    if (inCadastro.fail( ))
    {
        cout << "A abertura do arquivo de leitura falhou.\n";
        exit(1);
    }

    tela();

    gotoxy(20,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " FUNCIONARIOS CADASTRADOS ";

//    LENDO O ARQUIVO PARA LISTAR NA TELA

    inCadastro.read((char *)(&f),sizeof(funcionario));

    while (inCadastro && !inCadastro.eof())
    {
        if(f.id != 0 /* && k != x*/)
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



    inCadastro.close( );

    gotoxy(10,20);
    textcolor(WHITE);
    textbackground(RED);
    cout << " APERTE QUALQUER TECLA PARA VOLTAR PARA O MENU ";

    getch();

    opcMenu();
}

void alterar()
{
    int idbusca;
    char novoalteracao;

    tela();

    gotoxy(20,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " ALTERAR SALARIO ";


    fstream cadastro(arquivo,ios::in|ios::out|ios::ate);

    if (cadastro.fail( ))
    {
        cout << "A abertura do arquivo de leitura falhou.\n";
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

    cadastro.seekg((idbusca - 1) * sizeof(funcionario));
    cadastro.read((char *)(&f),sizeof(funcionario));

    if(f.id != 0)
    {
        gotoxy(10,12);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " QUAL O NOVO SALARIO DE " << f.nome;

        for (int i = 0; i < 10; i++)
        {
            gotoxy(45+i,12);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(46,12);
        textcolor(WHITE);
        cin >>  f.salario;

        cadastro.seekp((idbusca - 1)*sizeof(funcionario));
        cadastro.write((const char*)(&f), sizeof(funcionario));

        gotoxy(10,22);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " SALARIO ALTERADO COM SUCESSO ";
    }
    else
    {
        gotoxy(10,16);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " ESSE ID NAO PERTENCE A NEHUM FUNCIONARIO ";
        gotoxy(10,18);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " DESEJA CADASTRAR ESSE ID (S/N) ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(45+i,18);
            textbackground(GREEN);
            cout << '\0';
        }

        gotoxy(47,18);
        textcolor(WHITE);
        cin >> novoalteracao;

        if(novoalteracao == 's' || novoalteracao == 'S')
        {
            cadastrodefuncionarios();
        }
        if(novoalteracao == 'n' || novoalteracao == 'N')
        {
            gotoxy(10,20);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << " REALIZAR NOVA ALTERACAO (S/N) ";

            for (int i = 0; i < 5; i++)
            {
                gotoxy(45+i,20);
                textbackground(GREEN);
                cout << '\0';
            }

            gotoxy(47,20);
            textcolor(WHITE);
            cin >> novoalteracao;

            if(novoalteracao == 's' || novoalteracao == 'S')
            {
                alterar();
            }
            else
            {
                opcMenu();
            }
        }
    }

    cadastro.close();

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

    if(novoalteracao == 's' || novoalteracao == 'S')
    {
        alterar();
    }
    else
    {
        opcMenu();
    }


}


void zerar()
{
    int iderase;
    char novoalteracao;

    tela();

    gotoxy(20,5);
    textcolor(WHITE);
    textbackground(GREEN);
    cout << " REMOVER FUNCIONARIO ";

    fstream cadastro(arquivo,ios::in|ios::out|ios::ate);

    if (cadastro.fail( ))
    {
        cout << "A abertura do arquivo de leitura falhou.\n";
        exit(1);
    }

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

    cadastro.seekg((iderase - 1) * sizeof(funcionario));
    cadastro.read((char *)(&f),sizeof(funcionario));

    if(f.id != 0)
    {
        gotoxy(10,12);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << "DESEJA REMOVER O FUNCIONARIO " << f.nome << " (S/N) ";
        for (int i = 0; i < 5; i++)
        {
            gotoxy(55+i,12);
            textbackground(GREEN);
            cout << '\0';
        }
        gotoxy(56,12);
        textcolor(WHITE);
        cin >> novoalteracao;
        if(novoalteracao == 'S' || novoalteracao == 's')
        {
            funcionario clienteVazio = {0," "," ",' '," ",0.0};

            cadastro.seekp((iderase - 1) * sizeof(funcionario));
            cadastro.write((const char *)(&clienteVazio),sizeof(funcionario));

            gotoxy(10,22);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << "  FUNCIONARIO REMOVIDO COM SUCESSO ";

        }
        if(novoalteracao == 'n' || novoalteracao == 'N')
        {
            gotoxy(10,18);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << "  OPERACAO CANCELADA ";
            Sleep(2000);
            opcMenu();
        }
    }
    else
    {
        gotoxy(10,16);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " ESSE ID NAO PERTENCE A NEHUM FUNCIONARIO ";
        gotoxy(10,18);
        textcolor(WHITE);
        textbackground(GREEN);
        cout << " DESEJA CADASTRAR ESSE ID (S/N) ";

        for (int i = 0; i < 5; i++)
        {
            gotoxy(45+i,18);
            textbackground(GREEN);
            cout << '\0';
        }

        gotoxy(47,18);
        textcolor(WHITE);
        cin >> novoalteracao;

        if(novoalteracao == 's' || novoalteracao == 'S')
        {
            cadastrodefuncionarios();
        }
        if(novoalteracao == 'n' || novoalteracao == 'N')
        {
            gotoxy(10,20);
            textcolor(WHITE);
            textbackground(GREEN);
            cout << " REALIZAR OUTRA EXCLUSAO (S/N) ";

            for (int i = 0; i < 5; i++)
            {
                gotoxy(45+i,20);
                textbackground(GREEN);
                cout << '\0';
            }

            gotoxy(47,20);
            textcolor(WHITE);
            cin >> novoalteracao;

            if(novoalteracao == 's' || novoalteracao == 'S')
            {
                zerar();
            }
            else
            {
                opcMenu();
            }
        }
    }
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

    cadastro.close();

    if(novoalteracao == 's' || novoalteracao == 'S')
    {
        zerar();
    }
    else
    {
        opcMenu();
    }


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
