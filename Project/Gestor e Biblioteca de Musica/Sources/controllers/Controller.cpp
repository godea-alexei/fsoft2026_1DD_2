#include <iostream>
#include <string>
#include <list>
#include "Controller.h"
#include "Utils.h"
#include "../../Headers/repo/Repositorio.h"
using namespace std;

Controller::Controller(){}

//implementa os menus
void Controller::run(){
    int op = -1;
    do{
        op = this->view.menuPrincipal();
        switch(op){
            case 1: runEscolherPesquisa();
                break;
            case 2: runListaReproducao();
                break;
            case 3: runMusica();
                break;
            case 4: runAlbum();
                break;
            case 5: runEditora();
                break;
            case 6: runArtista();
                break;
            case 7: runPartilhar();
                break;
            default:
                break;
        }
    }while(op!=0);
}


// ─────────────────────────────────────────────
//  CONTA
// ─────────────────────────────────────────────
void Controller::runConta() {
    int op = -1;
    do {
        op = this->view.menuConta();
        switch(op) {
            case 1: // Criar Conta
                break;
            case 2: // Iniciar Sessao
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  ESCOLHER PESQUISA  (1º nível — tipo de pesquisa)
// ─────────────────────────────────────────────
void Controller::runEscolherPesquisa() {
    int op = -1;
    do {
        op = this->view.menuEscolhaPesquisa();
        switch(op) {
            case 1: // Pesquisa (pesquisar musica por campo)
                break;
            case 2: // Pesquisar Album
                break;
            case 3: // Pesquisar Editora
                break;
            case 4: // Pesquisar Artista
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  PESQUISA  (2º nível — pesquisar música por campo)
// ─────────────────────────────────────────────
void Controller::runPesquisa() {
    int op = -1;
    do {
        op = this->view.menuPesquisa();
        switch(op) {
            case 1: // Por Titulo
                break;
            case 2: // Por Album
                break;
            case 3: // Por Artista
                break;
            case 4: // Por Editora
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  LISTA DE REPRODUCAO
// ─────────────────────────────────────────────
void Controller::runListaReproducao() {
    int op = -1;
    do {
        op = this->view.menuLista();
        switch(op) {
            case 1: // Ver Listas de Reproducao
                break;
            case 2: // Adicionar Lista de Reproducao
                break;
            case 3: // Remover Lista de Reproducao
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  MUSICA
// ─────────────────────────────────────────────
void Controller::runMusica() {
    int op = -1;
    do {
        op = this->view.menuMusica();
        switch(op) {
            case 1: // Ver Audio
                break;
            case 2:
            {

                string nome;
                int dur;
                int ano;
                string letra;
                string genero;
                string caminho;
                string artst;
                string album;

                cout << " Por favor insira (sem espaços): "  << endl;

                cout << "Nome: ";
                cin >> nome;
                cout << "\n Duracao em minutos: ";
                cin >> dur;
                cout << "\n Ano de lancamento: ";
                cin >> ano;
                cout << "\n Letra: ";
                cin >> letra;
                cout << "\n Genero Musical: ";
                cin >> genero;
                cout << "\n Caminho absoluto do ficheiro audio: ";
                cin >> caminho;
                cout << "\n Nome do artista: ";
                cin >> artst;
                cout << "\n Nome do album: ";
                cin >> album;

                Musica m = Musica(nome, dur, ano, letra, genero, caminho, artst, album);

                Repositorio::guardarMusica(m);

                break;

            }
            case 3: // Remover Musica
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  ALBUM
// ─────────────────────────────────────────────
void Controller::runAlbum() {
    int op = -1;
    do {
        op = this->view.menuAlbum();
        switch(op) {
            case 1: // Ver Albums
                break;
            case 2: // Adicionar Album
                break;
            case 3: // Remover Album
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  EDITORA
// ─────────────────────────────────────────────
void Controller::runEditora() {
    int op = -1;
    do {
        op = this->view.menuEditora();
        switch(op) {
            case 1: // Ver Editoras
                break;
            case 2: // Adicionar Editora
                break;
            case 3: // Remover Editora
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  ARTISTA
// ─────────────────────────────────────────────
void Controller::runArtista() {
    int op = -1;
    do {
        op = this->view.menuArtista();
        switch(op) {
            case 1: // Ver Artista
                break;
            case 2: // Adicionar Artista
                break;
            case 3: // Remover Artista
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  PARTILHAR
// ─────────────────────────────────────────────
void Controller::runPartilhar() {
    int op = -1;
    do {
        op = this->view.menuPartilha();
        switch(op) {
            case 1: // Partilhar Musica
                break;
            case 2: // Partilhar Lista de Reproducao
                break;
            default:
                break;
        }
    } while(op != 0);
}



