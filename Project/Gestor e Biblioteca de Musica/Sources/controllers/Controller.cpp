#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "Controller.h"
#include "Utils.h"
#include "../../Headers/repo/Repositorio.h"
#include "ContaView.h"
#include "UtilizadorContainer.h"
#include "EditoraContainer.h"
using namespace std;

Controller::Controller() {
    vector<Utilizador> utilizadores = repositorio.carregarUtilizadores();
    vector<ListaReproducao> listas = repositorio.carregarListas();
    repositorio.carregarEditoras(editoraContainer, artistaContainer);

    for (const auto& u : utilizadores) {
        utilizadorContainer.adicionarUtilizador(u);
    }


}

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
        cout << "Ja existe um utilizador com o nome " << nome << "." << endl;
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

    repositorio.guardarUtilizador(utilizador);

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
            case 1:
                {
                    string titulo = Utils::getString("Insira o titulo da Musica");
                    Musica* musica = musicaContainer.procurarMusica(titulo);

                    if (musica == nullptr) {
                        cout << "Musica nao encontrada.\n";
                        break;
                    }
                    cout << ">>> " << titulo << " <<<" << endl;
                    cout << "Duracao: " << musica->getDuracao() << " minutos" <<endl;
                    cout << "Ano de Lancamento: " << musica->getAnoDeLancamento() << endl;
                    cout << "Genero: " << musica->getGenero() << endl;
                    cout << "Artista: " << musica->getNomeArtista() << endl;

                    int opcao = -1;
                    do {
                        opcao = this->view.menuPesquisa();
                        switch(opcao) {
                            case 1:
                                musica->reproduzir();
                                break;
                            case 2:
                                cout << "Letra da Musica " << musica->getNome() << ":"<< endl;
                                cout << musica->getLetra() << endl;
                            default:
                                break;
                        }
                    }
                    while(opcao != 0);
                }
                break;
            case 2:
                {
                    string nome = Utils::getString("Insira o nome do Album");
                    Album* album = albumContainer.procurarAlbum(nome);
                    if (album == nullptr) {
                        cout << "Album nao encontrado.\n";
                        break;
                    }
                    cout << ">>> " << nome << " (" << album->getDuracao() <<" minutos) <<<" << endl;
                    const auto& musicas = album->getMusicas();
                    if (musicas.empty()) {
                        cout << "Sem Musicas.\n";
                    }
                    else {
                        for (const auto& m : musicas) {
                            cout << "- " << m->getNome() << " (" << m->getDuracao() << " minutos)" << endl;
                        }
                    }
                    int opcao = -1;
                    do {
                        opcao = this->view.musicaEmAlbum();
                        switch(opcao) {
                            case 1: {
                                string nomeM = Utils::getString("Insira o nome da Musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    cout << "Musica nao existe.\n";
                                    break;
                                }
                                if (album->existeMusica(nomeM)) {
                                    cout << "Musica ja esta adicionada a este album.\n";
                                    break;
                                }

                                album->adicionarMusica(musica);
                                cout << "Musica adicionada com sucesso! " << endl;
                                break;
                            }
                            case 2: {
                                string nomeM = Utils::getString("Insira o nome da musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    cout << "Musica nao existe.\n";
                                    break;
                                }
                                if (!album->existeMusica(nomeM)) {
                                    cout << "Musica nao esta associada a este album.\n";
                                    break;
                                }
                                album->removerMusica(nomeM);
                                cout << "Musica removida com sucesso! " << endl;
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    while(opcao != 0);
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Insira o nome da editora");
                    Editora* editora = editoraContainer.procurar(nome);
                    if (editora == nullptr) {
                        cout << "Editora nao encontrada.\n";
                        break;
                    }
                    cout << ">>> " << nome << " <<<" << endl;
                    const auto& artistas = editora->getArtistas();
                    if (artistas.empty()) {
                        cout << "Sem artistas associados.\n";
                    }
                    else {
                        for (const auto& a : artistas) {
                            cout << "- " << a->getNome() << ": "<< a->getIdade() << " anos"<<endl;
                        }
                    }
                    int opcao = -1;
                    do {
                        opcao = this->view.artistaEmEditora();
                        switch(opcao) {
                            case 1: {
                                string nomeA = Utils::getString("Insira o nome do artista");

                                Artista* artista = artistaContainer.procurarArtista(nomeA);

                                if (artista == nullptr) {
                                    cout << "Artista nao existe.\n";
                                    break;
                                }
                                if (editora->existeArtista(nomeA)) {
                                    cout << "Artista ja esta associado a esta editora.\n";
                                    break;
                                }

                                editora->adicionarArtista(artista);
                                cout << "Artista adicionado com sucesso! " << endl;
                                break;
                            }
                            case 2: {
                                string nomeA = Utils::getString("Insira o nome do artista");

                                Artista* artista = artistaContainer.procurarArtista(nomeA);

                                if (artista == nullptr) {
                                    cout << "Artista nao existe.\n";
                                    break;
                                }
                                if (!editora->existeArtista(nomeA)) {
                                    cout << "Artista nao esta associado a editora.\n";
                                    break;
                                }
                                editora->removerArtista(nomeA);
                                cout << "Artista removido com sucesso! " << endl;
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    while(opcao != 0);
                }
                break;
            case 4:
                {
                    string nome = Utils::getString("Insira o nome do artista");
                    Artista* artista = artistaContainer.procurarArtista(nome);
                    if (artista == nullptr) {
                        cout << "Artista nao encontrado.\n";
                        break;
                    }
                    cout << ">>> " << nome << " <<<" << endl;
                    const auto& albuns = artista->getAlbuns();
                    if (albuns.empty()) {
                        cout << "Sem Albuns associados.\n";
                    }
                    else {
                        for (const auto& a : albuns) {
                            cout << "- " << a->getNome() << " (" << a->getAnoLancamento() << ")" <<endl;
                        }
                    }
                    int opcao = -1;
                    do {
                        opcao = this->view.albumEmArtista();
                        switch(opcao) {
                            case 1: {
                                string nomeA = Utils::getString("Insira o nome do Album");

                                Album* album = albumContainer.procurarAlbum(nomeA);

                                if (album == nullptr) {
                                    cout << "Album nao existe.\n";
                                    break;
                                }
                                if (artista->existeAlbum(nomeA)) {
                                    cout << "Album ja esta associado a este artista.\n";
                                    break;
                                }

                                artista->adicionarAlbum(album);
                                cout << "Album adicionado com sucesso! " << endl;
                                break;
                            }
                            case 2: {
                                string nomeA = Utils::getString("Insira o nome do album");

                                Album* album = albumContainer.procurarAlbum(nomeA);

                                if (album == nullptr) {
                                    cout << "Album nao existe.\n";
                                    break;
                                }
                                if (!artista->existeAlbum(nomeA)) {
                                    cout << "Album nao esta associado ao artista.\n";
                                    break;
                                }
                                artista->removerAlbum(nomeA);
                                cout << "Album removido com sucesso! " << endl;
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    while(opcao != 0);
                }
                break;
            case 5:
                {
                    string nome = Utils::getString("Insira o nome da Lista de Reproducao");
                    ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nome);
                    if (listaReproducao == nullptr) {
                        cout << "Lista de Reproducao nao encontrada.\n";
                        break;
                    }
                    cout << ">>> " << nome << " (" << listaReproducao->getDuracao() <<" minutos) <<<" << endl;
                    const auto& musicas = listaReproducao->getMusicas();
                    if (musicas.empty()) {
                        cout << "Sem Musicas.\n";
                    }
                    else {
                        for (const auto& m : musicas) {
                            cout << "- " << m->getNome() << " (" << m->getDuracao() << " minutos)" << endl;
                        }
                    }
                    int opcao = -1;
                    do {
                        opcao = this->view.musicaEmLista();
                        switch(opcao) {
                            case 1: {
                                string nomeM = Utils::getString("Insira o nome da Musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    cout << "Musica nao existe.\n";
                                    break;
                                }
                                if (listaReproducao->existeMusica(nomeM)) {
                                    cout << "Musica ja esta adicionada a esta Lista de Reproducao.\n";
                                    break;
                                }

                                listaReproducao->adicionarMusica(musica);
                                cout << "Musica adicionada com sucesso! " << endl;
                                break;
                            }
                            case 2: {
                                string nomeM = Utils::getString("Insira o nome da musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    cout << "Musica nao existe.\n";
                                    break;
                                }
                                if (!listaReproducao->existeMusica(nomeM)) {
                                    cout << "Musica nao esta associada a esta Lista de Reproducao.\n";
                                    break;
                                }
                                listaReproducao->removerMusica(nomeM);
                                cout << "Musica removida com sucesso! " << endl;
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    while(opcao != 0);
                }
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
            case 1: {
                    const auto& listas = listaReproducaoContainer.getListas();

                    if (listas.empty()) {
                        cout << "Ainda nao foram adicionadas listas de reproducao.\n";
                        break;
                    }

                    cout << ">>> LISTAS DE REPRODUCAO <<<" << endl;
                    for (const auto& l : listas) {
                        cout << "- " << l.getNome() << endl;
                    }
                }
                break;
            case 2: {
                string nome = Utils::getString("Digite o nome da Lista de Reproducao");

                if (listaReproducaoContainer.existeLista(nome)) {
                    cout << "Essa Lista de Reproducao ja foi adicionada...\n";
                    break;
                }

                time_t t = time(0);
                tm* now = localtime(&t);
                int ano = now->tm_year + 1900;

                ListaReproducao lista(nome, ano, utilizadorAtual->getNome());

                listaReproducaoContainer.adicionarLista(lista);

                repositorio.guardarLista(lista);

                cout << "Lista de Reproducao criada com sucesso!" << endl;
                }
                break;
            case 3: {
                    string nome = Utils::getString("Digite o nome da Lista de Reproducao que quer remover");

                    if (listaReproducaoContainer.removerLista(nome)) {
                        repositorio.eliminarLista(nome);
                        cout << "A Lista de Reproducao " << nome << " foi removida com sucesso." << endl;
                    }
                    else
                        cout << "A Lista de Reproducao nao foi encontrada." << endl;
                }
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
            /*
            case 1:
                MusicaContainer::removerMusica();
                break;
            case 2: //adicionar musica
                MusicaContainer::adicionarMusica();
                break;
            case 3: // Remover Musica
                MusicaContainer::removerMusica();
                break;
            case 4: // reproduzir Musica
                MusicaContainer::reproduzirMusica();
                break;
              */
          case 1:    
            {
                    const auto& musicas = musicaContainer.getMusicas();

                    if (musicas.empty()) {
                        cout << "Ainda nao foram adicionadas Musicas.\n";
                        break;
                    }

                    cout << ">>> MUSICAS <<<" << endl;
                    for (const auto& m : musicas) {
                        cout << "- " << m.getNome() << " ("<< m.getAnoDeLancamento() << "): " << m.getNomeArtista() << endl;
                    }
              
                    break;    
            }
            case 2:
                {
                    string nome = Utils::getString("Digite o Titulo da Musica");
                    int dur = Utils::getNumber("Digite a duracao da musica (em minutos)");
                    int ano = Utils::getNumber("Digite o ano de lancamento da musica");
                    string letra = Utils::getString("Digite a letra da musica");
                    string genero = Utils::getString("Digite o genero da musica");
                    string caminho = Utils::getString("Digite o caminho absoluto da musica");
                    string artista = Utils::getString("Digite o artista da Musica");

                    Musica musica = Musica(nome, dur, ano, letra, genero, caminho, artista);

                    if (musicaContainer.existeMusica(nome)) {
                        cout << "Essa Musica ja foi adicionada..." << endl;
                        break;
                    }

                    musicaContainer.adicionarMusica(musica);

                    Repositorio::guardarMusica(musica);

                    break;

                }

            case 3:
                {
                    string nome = Utils::getString("Digite o nome da Musica que quer remover");

                    if (musicaContainer.removerMusica(nome)) {
                        repositorio.eliminarMusica(nome);
                        cout << "A Musica " << nome << " foi removida com sucesso." << endl;
                    }
                    else
                        cout << "A musica nao foi encontrada." << endl;

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
            case 1: {
                    const auto& albuns = albumContainer.getAlbuns();

                    if (albuns.empty()) {
                        cout << "Ainda nao foram adicionados Albuns.\n";
                        break;
                    }

                    cout << ">>> ALBUNS <<<" << endl;
                    for (const auto& a : albuns) {
                        cout << "- " << a.getNome() << endl;
                    }
                }
                break;
            case 2:
                {
                string nome = Utils::getString("Digite o nome do Album");

                if (albumContainer.existeAlbum(nome)) {
                    cout << "Esse Album ja foi adicionado...\n";
                    break;
                }
                int ano = Utils::getNumber("Digite o ano de lancamento do Album");

                Album album(nome, ano);

                albumContainer.adicionarAlbum(album);

                repositorio.guardarAlbum(album);

                cout << "Album adicionado com sucesso!" << endl;
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome do Album que quer remover");

                    if (albumContainer.removerAlbum(nome)) {
                        repositorio.eliminarAlbum(nome);
                        cout << "O Album " << nome << " foi removido com sucesso." << endl;
                }
                    else
                        cout << "O Album nao foi encontrado." << endl;
                }
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
                        cout << "Ainda nao foram adicionadas editoras.\n";
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
                        cout << "Essa editora ja foi adicionada...\n";
                        break;
                    }

                    editoraContainer.adicionarEditora(nome);
                    repositorio.guardarEditora(nome);
                    cout << "Editora adicionada com sucesso!" << endl;
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome da editora que quer remover");

                    if (editoraContainer.removerEditora(nome)) {
                        repositorio.eliminarEditora(nome);
                        cout << "A editora " << nome << " foi removida com sucesso." << endl;
                    }
                    else
                        cout << "A editora nao foi encontrada." << endl;
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
            case 1:
                {
                    const auto& artistas = artistaContainer.getArtistas();

                    if (artistas.empty()) {
                        cout << "Ainda nao foram adicionados artistas.\n";
                        break;
                    }

                    cout << ">>> ARTISTAS <<<" << endl;
                    for (const auto& a : artistas) {
                        cout << "- " << a.getNome() << ": " << a.getIdade() << " anos" << endl;
                    }
                }

                break;
            case 2:
                {
                    string nome = Utils::getString("Digite o nome do artista");
                    int ano = Utils::getNumber("Digite a data de nascimento/fundacao do artista");

                    if (artistaContainer.existeArtista(nome)) {
                        cout << "Esse artista ja foi adicionado...\n";
                        break;
                    }

                    artistaContainer.adicionarArtista(Artista(nome, ano));
                    cout << "Artista adicionado com sucesso!" << endl;
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome do artista que quer remover");

                    if (artistaContainer.removerArtista(nome)) {
                        cout << "O artista " << nome << " foi removido com sucesso." << endl;
                    }
                    else
                        cout << "O artista nao foi encontrado." << endl;
                }
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



