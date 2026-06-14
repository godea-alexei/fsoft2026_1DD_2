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
        cout << "\n\n>>> Opcoes - Conta <<<\n";
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
        cout << "\n\n>>> Opcoes - pesquisa <<<\n";
        cout << "1 - Pesquisar Musica\n";
        cout << "2 - Pesquisar Album\n";
        cout << "3 - Pesquisar Editora\n";
        cout << "4 - Pesquisar Artista\n";
        cout << "5 - Pesquisar Listas de Reproducao\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 5);
    return op;
}


int View::menuLista() {
    int op = -1;
    do {
        cout << "\n\n>>> Opcoes - Listas de Reproducao <<<\n";
        cout << "1 - Ver Listas de Reproducao\n";
        cout << "2 - Adicionar Lista de Reproducao\n";
        cout << "3 - Remover Lista de Reproducao\n";
        cout << "4 - Adicionar Musica a Lista de Reproducao\n";
        cout << "5 - Remover Musica da Lista de Reproducao\n";
        cout << "6 - Abrir lista de reproducao\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 6);
    return op;
}


int View::menuMusica() {
    int op = -1;
    do {
        cout << "\n\n>>> Opcoes - Musicas <<<\n";
        cout << "1 - Listar Musicas\n";
        cout << "2 - Adicionar Musica\n";
        cout << "3 - Remover Musica\n";
        cout << "4 - Reproduzir Musica\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 4);
    return op;
}

int View::menuAlbum() {
    int op = -1;
    do {
        cout << "\n\n>>> Opcoes - Albums <<<\n";
        cout << "1 - Ver Albums\n";
        cout << "2 - Adicionar Album\n";
        cout << "3 - Remover Album\n";
        cout << "4 - Adicionar Musica ao Album\n";
        cout << "5 - Remover Musica do Album\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 5);
    return op;
}

int View::menuEditora() {
    int op = -1;
    do {
        cout << "\n\n>>> Opcoes - Editoras <<<\n";
        cout << "1 - Listar Editoras\n";
        cout << "2 - Adicionar Editora\n";
        cout << "3 - Remover Editora\n";
        cout << "4 - Adicionar Artista a Editora\n";
        cout << "5 - Remover Artista da Editora\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 5);
    return op;
}

int View::menuArtista() {
    int op = -1;
    do {
        cout << "\n\n>>> Opcoes Artistas <<<\n";
        cout << "1 - Listar Artistas\n";
        cout << "2 - Adicionar Artista\n";
        cout << "3 - Remover Artista\n";
        cout << "4 - Adicionar Album ao Artista\n";
        cout << "5 - Remover Album do Artista\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 5);
    return op;
}

int View::menuPartilha() {
    int op = -1;
    do {
        cout << "\n\n>>> Opcoes - Partilha <<<\n";
        cout << "1 - Partilhar Musica\n";
        cout << "2 - Partilhar Lista de Reproducao\n";
        cout << "\n0 - Voltar \n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);
    return op;
}






