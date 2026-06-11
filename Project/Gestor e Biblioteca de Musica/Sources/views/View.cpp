#include <iostream>
#include "View.h"
#include "Utils.h"
using namespace std;



//printa todos os menus
int View::menuPrincipal(){

    int op = -1;
    do{
        cout<<"\n\n********** Menu Principal **********\n";
        cout<<"1 - Pesquisar \n"<<endl;
        cout<<"2 - Listas de Reproducao \n"<<endl;
        cout<<"3 - Musica \n"<<endl;
        cout<<"4 - Albums \n"<<endl;
        cout<<"5 - Editoras \n"<<endl;
        cout<<"6 - Artistas \n"<<endl;
        cout<<"7 - Partilhar \n"<<endl;
        cout<<"0 - Sair da Conta \n"<<endl;
        op = Utils::getNumber("Opcao");

    }while(op < 0 || op > 8);
    return op;

}

int View::menuConta() {
    int op = -1;
    do {
        cout << "\n\n>>> Menu de contas <<<\n";
        cout << "1 - Criar Conta\n";
        cout << "2 - Iniciar Sessao\n";
        cout << "\n0 - Sair do Programa\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);
    return op;
}


int View::menuEscolhaPesquisa() {
    int op = -1;
    do {
        cout << "\n\n>>> Menu de pesquisa <<<\n";
        cout << "1 - Pesquisar Musica\n";
        cout << "2 - Pesquisar Album\n";
        cout << "3 - Pesquisar Editora\n";
        cout << "4 - Pesquisar Artista\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 4);
    return op;
}


int View::menuPesquisa() {
    int op = -1;
    do {
        cout << "\n\n>>> Pesquisar Musica <<<\n";
        cout << "1 - Por Titulo\n";
        cout << "2 - Por Album\n";
        cout << "3 - Por Artista\n";
        cout << "4 - Por Editora\n";
        cout << "\n0 - Voltar ao Menu de pesquisa\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 4);
    return op;
}

int View::menuLista() {
    int op = -1;
    do {
        cout << "\n\n>>> Listas de Reproducao <<<\n";
        cout << "1 - Ver Listas de Reproducao\n";
        cout << "2 - Adicionar Lista de Reproducao\n";
        cout << "3 - Remover Lista de Reproducao\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 3);
    return op;
}


int View::menuMusica() {
    int op = -1;
    do {
        cout << "\n\n>>> Menu de musicas <<<\n";
        cout << "1 - Ver Musicas\n";
        cout << "2 - Adicionar Musica\n";
        cout << "3 - Remover Musica\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 3);
    return op;
}

int View::menuAlbum() {
    int op = -1;
    do {
        cout << "\n\n>>> Albums <<<\n";
        cout << "1 - Ver Albums\n";
        cout << "2 - Adicionar Album\n";
        cout << "3 - Remover Album\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 3);
    return op;
}

int View::menuEditora() {
    int op = -1;
    do {
        cout << "\n\n>>> Editoras <<<\n";
        cout << "1 - Ver Editoras\n";
        cout << "2 - Adicionar Editora\n";
        cout << "3 - Remover Editora\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 3);
    return op;
}

int View::menuArtista() {
    int op = -1;
    do {
        cout << "\n\n>>> Artistas <<<\n";
        cout << "1 - Ver Artista\n";
        cout << "2 - Adicionar Artista\n";
        cout << "3 - Remover Artista\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 3);
    return op;
}

int View::menuPartilha() {
    int op = -1;
    do {
        cout << "\n\n>>> Partilhar <<<\n";
        cout << "1 - Partilhar Musica\n";
        cout << "2 - Partilhar Lista de Reproducao\n";
        cout << "\n0 - Voltar ao Menu Principal\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);
    return op;
}

int View::ArtistaEmEditora() {
    int op = -1;
    do {
        cout << "\n\n1 - Adicionar Artista à Editora\n";
        cout << "2 - Remover Artista da Editora\n";
        cout << "\n0 - Voltar ao Menu de Pesquisa\n";
        op = Utils::getNumber("Opcao");
    }
    while (op < 0 || op > 2);
    return op;
}


