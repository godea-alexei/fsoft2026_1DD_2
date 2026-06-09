#include <iostream>
#include <string>
#include <list>
#include "Controller.h"
#include "Utils.h"
#include "../../Headers/repo/Repositorio.h"
#include "ContaView.h"
#include "UtilizadorContainer.h"
#include "EditoraContainer.h"
using namespace std;

Controller::Controller(){}

//implementa os menus
void Controller::runConta(){
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
                utilizadorAtual = nullptr;
                break;
        }
    }while(op!=0);
}


// ─────────────────────────────────────────────
//  CONTA
// ─────────────────────────────────────────────
void Controller::run() {
    int op = -1;
    do {
        op = this->view.menuConta();
        switch(op) {
            case 1: runRegisto();
                break;
            case 2: runLogin();
                break;
            default:
                break;
        }
    } while(op != 0);
}

// ─────────────────────────────────────────────
//  Gestão de Registo
// ─────────────────────────────────────────────

void Controller::runRegisto() {
    ContaView contaView;

    string nome = contaView.getNome();
    int anoNascimento = contaView.getAnoNascimento();
    string palavraPasse = contaView.getPalavraPasse();
    string palavraPasseConfirmation = contaView.getPalavraPasseConfirmation();

    if (utilizadorContainer.existeUtilizador(nome)) {
        cout << "Já existe um utilizador com o nome " << nome << "." << endl;
        return;
    }

    if (!Utilizador::validarPalavraPasse(
        palavraPasse,
        palavraPasseConfirmation)) {
        contaView.falhaRegisto();
        return;
    }

    Utilizador utilizador(
    nome,
    anoNascimento,
    palavraPasse);

    utilizadorContainer.adicionarUtilizador(utilizador);
    contaView.sucessoRegisto();
}

// ─────────────────────────────────────────────
//  Gestão de Login
// ─────────────────────────────────────────────
void Controller::runLogin() {
    ContaView contaView;
    bool isLogged = false;


    string nome = contaView.getNome();
    string palavraPasse = contaView.getPalavraPasse();

    if (utilizadorContainer.autenticar(nome, palavraPasse)) {
        Utilizador* u = utilizadorContainer.procurarUtilizador(nome);
        utilizadorAtual = u;
        contaView.sucessoLogin();
        cout << "Bem vindo/a, " << nome << "!!" << endl;
        isLogged = true;
    }
    else contaView.falhaLogin();

    if (isLogged == true) runConta();

}

// ─────────────────────────────────────────────
//  ESCOLHER PESQUISA  (1º nível — tipo de pesquisa)
// ─────────────────────────────────────────────
void Controller::runEscolherPesquisa() {
    int op = -1;
    do {
        op = this->view.menuEscolhaPesquisa();
        switch(op) {
            case 1: runPesquisa();
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
                {
                    string nome;
                    cout << "\n Insira nome da musica a eliminar: ";
                    cin >> nome;
                    Repositorio::eliminarMusica(nome);
                    break;
                }

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
            case 1:
                {
                    const auto& editoras = editoraContainer.getEditoras();

                    if (editoras.empty()) {
                        cout << "Ainda não foram adicionadas editoras.\n";
                        break;
                    }

                    cout << ">>> EDITORAS <<<" << endl;
                    for (const auto& e : editoras) {
                        cout << "- " << e.getNome() << endl;
                    }
                }
                break;
            case 2:
                {
                    string nome = Utils::getString("Digite o nome da editora");

                    if (editoraContainer.existeEditora(nome)) {
                        cout << "Essa editora já foi adicionada...\n";
                        break;
                    }

                    editoraContainer.adicionarEditora(nome);
                    cout << "Editora adicionada com sucesso!" << endl;
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome da editora que quer remover");

                    if (editoraContainer.removerEditora(nome)) {
                        cout << "A editora " << nome << " foi removida com sucesso." << endl;
                    }
                    else
                        cout << "A editora não foi encontrada." << endl;
                }
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



