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
#include "BaseView.h"
using namespace std;

Controller::Controller() {
    vector<Musica> musicas = repositorio.carregarMusicas();

    for (const auto& m : musicas) {
        musicaContainer.adicionarMusica(m);
    }

    vector<Album> albuns = repositorio.carregarAlbuns(musicaContainer);

    for (const auto& a : albuns) {
        albumContainer.adicionarAlbum(a);
    }

    vector<ListaReproducao> listas = repositorio.carregarListas(musicaContainer);

    for (const auto& l : listas) {
        listaReproducaoContainer.adicionarLista(l);
    }

    vector<Artista> artistas = repositorio.carregarArtistas(albumContainer);

    for (const auto& a : artistas) {
        artistaContainer.adicionarArtista(a);
    }

    vector<Editora> editoras = repositorio.carregarEditoras(artistaContainer);
    for (const auto& e : editoras) {
        editoraContainer.adicionarEditora(e);
    }

    vector<Utilizador> utilizadores = repositorio.carregarUtilizadores();

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
        msg = "Ja existe um utilizador com o nome " + nome + ".";
        Utils::printMessage(msg);
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
        msg = "Bem vindo/a, " + nome + "!!";
        Utils::printMessage(msg);
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
                        msg = "Musica nao encontrada.";
                        Utils::printMessage(msg);
                        break;
                    }
                    BaseView::listarAtributos(musica);

                    int opcao = -1;
                    do {
                        opcao = this->view.menuPesquisa();
                        switch(opcao) {
                            case 1:
                                musica->reproduzir();
                                break;
                            case 2:
                                msg = "Letra da Musica " + musica->getNome(); + ":";
                                Utils::printMessage(msg);
                                msg = musica->getNome();
                                Utils::printMessage(msg);
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
                        msg = "Album nao encontrado";
                        Utils::printMessage(msg);
                        break;
                    }
                    cout << ">>> " << nome << " (" << album->getDuracao() <<" minutos) <<<" << endl;
                    const auto& musicas = album->getMusicas();
                    if (musicas.empty()) {
                        msg = "Sem Musicas";
                        Utils::printMessage(msg);
                    }
                    else {
                        for (const auto& m : musicas) {
                            msg = "- " + m->getNome(); + " (" + to_string(m->getDuracao()) + " minutos)";
                            Utils::printMessage(msg);
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
                                    msg = "Musica nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (album->existeMusica(nomeM)) {
                                    msg = "Musica ja esta adicionada a este album.";
                                    Utils::printMessage(msg);
                                    break;
                                }

                                album->adicionarMusica(musica);
                                msg = "Musica adicionada com sucesso! ";
                                Utils::printMessage(msg);
                                break;
                            }
                            case 2: {
                                string nomeM = Utils::getString("Insira o nome da musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    msg = "Musica nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (!album->existeMusica(nomeM)) {
                                    msg = "Musica nao esta associada a este album.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                album->removerMusica(nomeM);
                                msg = "Musica removida com sucesso!";
                                Utils::printMessage(msg);
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
                        msg = "Editora nao encontrada";
                        Utils::printMessage(msg);
                        break;
                    }
                    msg = ">>> " + nome + " <<<";
                    Utils::printMessage(msg);
                    const auto& artistas = editora->getArtistas();
                    if (artistas.empty()) {
                        msg = "Sem artistas associados";
                        Utils::printMessage(msg);
                    }
                    else {
                        for (const auto& a : artistas) {
                            msg = "- " + a->getNome() + ": " + to_string(a->getIdade()) + " anos";
                            Utils::printMessage(msg);
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
                                    msg = "Artista nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (editora->existeArtista(nomeA)) {
                                    msg = "Artista ja esta associado a esta editora.";
                                    Utils::printMessage(msg);
                                    break;
                                }

                                editora->adicionarArtista(artista);
                                msg = "Artista adicionada com sucesso!";
                                Utils::printMessage(msg);
                                break;
                            }
                            case 2: {
                                string nomeA = Utils::getString("Insira o nome do artista");

                                Artista* artista = artistaContainer.procurarArtista(nomeA);

                                if (artista == nullptr) {
                                    msg = "Artista nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (!editora->existeArtista(nomeA)) {
                                    msg = "Artista nao esta associado a esta editora.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                editora->removerArtista(nomeA);
                                msg = "Artista removido com sucesso!";
                                Utils::printMessage(msg);
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
                        msg = "Artista nao encontrado.";
                        Utils::printMessage(msg);
                        break;
                    }
                    msg = ">>> " + nome + " <<<";
                    const auto& albuns = artista->getAlbuns();
                    if (albuns.empty()) {
                        msg = "Sem Albuns associados.";
                        Utils::printMessage(msg);
                    }
                    else {
                        for (const auto& a : albuns) {
                            msg = "- " + a->getNome() + " (" + to_string(a->getAnoLancamento()) + ")";
                            Utils::printMessage(msg);
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
                                    msg = "Album nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (artista->existeAlbum(nomeA)) {
                                    msg = "Album ja esta associado a este artista.";
                                    Utils::printMessage(msg);
                                    break;
                                }

                                artista->adicionarAlbum(album);
                                msg = "Album adicionado com sucesso! ";
                                Utils::printMessage(msg);
                                break;
                            }
                            case 2: {
                                string nomeA = Utils::getString("Insira o nome do album");

                                Album* album = albumContainer.procurarAlbum(nomeA);

                                if (album == nullptr) {
                                    msg = "Album nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (!artista->existeAlbum(nomeA)) {
                                    msg = "Album nao esta associado ao artista.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                artista->removerAlbum(nomeA);
                                msg = "Album removido com sucesso! ";
                                Utils::printMessage(msg);
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
                        msg = "Lista de Reproducao nao encontrada";
                        Utils::printMessage(msg);
                        break;
                    }
                    msg = ">>> " + nome + " (" + to_string(listaReproducao->getDuracao()) + " minutos) <<<";
                    Utils::printMessage(msg);
                    const auto& musicas = listaReproducao->getMusicas();
                    if (musicas.empty()) {
                        msg = "Sem Musicas.";
                        Utils::printMessage(msg);
                    }
                    else {
                        for (const auto& m : musicas) {
                            msg = "- " + m->getNome() + " (" + to_string(m->getDuracao()) + " minutos)";
                            Utils::printMessage(msg);
                        }
                    }
                    int opcao = -1;
                    do {
                        opcao = this->view.musicaEmLista();
                        switch(opcao) {
                            case 1: {
                                if (listaReproducao->getCriador() != utilizadorAtual->getNome() ) {
                                    msg = "So o criador da Lista de Reproducao tem permissao para alterar a lista  de reproducao: " + listaReproducao->getNome();
                                    Utils::printMessage(msg);
                                    break;
                                }
                                string nomeM = Utils::getString("Insira o nome da Musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    msg = "Musica nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (listaReproducao->existeMusica(nomeM)) {
                                    msg = "Musica ja esta adicionada a esta Lista de Reproducao.";
                                    Utils::printMessage(msg);
                                    break;
                                }

                                listaReproducao->adicionarMusica(musica);
                                msg = "Musica adicionada com sucesso! ";
                                Utils::printMessage(msg);
                                break;
                            }
                            case 2: {
                                if (listaReproducao->getCriador() != utilizadorAtual->getNome() ) {
                                    msg = "So o criador da Lista de Reproducao tem permissao para alterar a lista  de reproducao: " + listaReproducao->getNome();
                                    Utils::printMessage(msg);
                                    break;
                                }
                                string nomeM = Utils::getString("Insira o nome da musica");

                                Musica* musica = musicaContainer.procurarMusica(nomeM);

                                if (musica == nullptr) {
                                    msg = "Musica nao existe.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                if (!listaReproducao->existeMusica(nomeM)) {
                                    msg = "Musica nao esta associada a esta Lista de Reproducao.";
                                    Utils::printMessage(msg);
                                    break;
                                }
                                listaReproducao->removerMusica(nomeM);
                                msg = "Musica removida com sucesso! ";
                                Utils::printMessage(msg);
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
                        msg = "Ainda nao foram adicionadas listas de reproducao.";
                        Utils::printMessage(msg);
                        break;
                    }
                    msg = ">>> LISTAS DE REPRODUCAO <<<";
                    Utils::printMessage(msg);

                    for (const auto& l : listas) {
                        msg = "- " + l.getNome();
                        Utils::printMessage(msg);
                    }
                }
                break;
            case 2: {
                string nome = Utils::getString("Digite o nome da Lista de Reproducao");

                if (listaReproducaoContainer.existeLista(nome)) {
                    msg = "Essa Lista de Reproducao ja foi adicionada...";
                    Utils::printMessage(msg);
                    break;
                }

                ListaReproducao lista(nome, utilizadorAtual->getNome());

                listaReproducaoContainer.adicionarLista(lista);

                msg = "Lista de Reproducao criada com sucesso!";
                Utils::printMessage(msg);
                }
                break;
            case 3: {
                    string nome = Utils::getString("Digite o nome da Lista de Reproducao que quer remover");

                    if (listaReproducaoContainer.removerLista(nome)) {
                        repositorio.eliminarLista(nome);
                        msg = "A Lista de Reproducao " + nome + " foi removida com sucesso.";
                    }
                    else msg = "A Lista de Reproducao nao foi encontrada.";
                    Utils::printMessage(msg);
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
            case 1:
                {
                    const auto& musicas = musicaContainer.getMusicas();

                    if (musicas.empty()) {
                        msg = "Ainda nao foram adicionadas Musicas.";
                        Utils::printMessage(msg);
                        break;
                    }

                    msg = ">>> MUSICAS <<<";
                    for (const auto& m : musicas) {
                        msg = "- " + m->getNome() + " (" + to_string(m->getAnoDeLancamento()) + "): " + m->getNomeArtista();
                        Utils::printMessage(msg);
                    }
                }
                break;
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
                        msg = "Essa Musica ja foi adicionada...";
                        Utils::printMessage(msg);
                        break;
                    }

                    musicaContainer.adicionarMusica(musica);

                    Repositorio::guardarMusica(musica);

                    break;

                }

            case 3:
                {
                    string nome = Utils::getString("Digite o nome da Musica que quer remover");

                    if (musicaContainer.existeMusica(nome)) {
                        for (const auto& a : albumContainer.getAlbuns()) {
                            string nomeA = a.getNome();
                            Album* album = albumContainer.procurarAlbum(nomeA);
                            album->removerMusica(nome);
                        }
                        for (const auto& l : listaReproducaoContainer.getListas()) {
                            string nomeL = l.getNome();
                            ListaReproducao* lista = listaReproducaoContainer.procurar(nomeL);
                            lista->removerMusica(nome);
                        }
                    }
                    if (musicaContainer.removerMusica(nome)) {
                        repositorio.eliminarMusica(nome);
                        msg = "A Musica " + nome + " foi removida com sucesso.";
                    }
                    else msg = "A musica nao foi encontrada.";
                    Utils::printMessage(msg);
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
                        msg = "Ainda nao foram adicionados Albuns.";
                        Utils::printMessage(msg);
                        break;
                    }

                    msg = ">>> ALBUNS <<<";
                    Utils::printMessage(msg);
                    for (const auto& a : albuns) {
                        msg = "- " + a.getNome();
                        Utils::printMessage(msg);
                    }
                }
                break;
            case 2:
                {
                string nome = Utils::getString("Digite o nome do Album");

                if (albumContainer.existeAlbum(nome)) {
                    msg = "Esse Album ja foi adicionado...";
                    Utils::printMessage(msg);
                    break;
                }
                int ano = Utils::getNumber("Digite o ano de lancamento do Album");

                Album album(nome, ano);

                albumContainer.adicionarAlbum(album);

                msg = "Album adicionado com sucesso!";
                Utils::printMessage(msg);
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome do Album que quer remover");

                    if (albumContainer.existeAlbum(nome)) {
                        for (const auto& a : artistaContainer.getArtistas()) {
                            string nomeA = a.getNome();
                            Artista* artista = artistaContainer.procurarArtista(nomeA);
                            artista->removerAlbum(nome);
                        }
                    }

                    if (albumContainer.removerAlbum(nome)) {
                        repositorio.eliminarAlbum(nome);
                        msg = "O Album " + nome + " foi removido com sucesso.";
                }
                    else msg = "O Album nao foi encontrado.";
                    Utils::printMessage(msg);
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
                        msg = "Ainda nao foram adicionadas editoras.";
                        Utils::printMessage(msg);
                        break;
                    }

                    msg = ">>> EDITORAS <<<";
                    Utils::printMessage(msg);
                    for (const auto& e : editoras) {
                        msg = "- " + e.getNome();
                        Utils::printMessage(msg);
                    }
                }
                break;
            case 2:
                {
                    string nome = Utils::getString("Digite o nome da editora");

                    if (editoraContainer.existeEditora(nome)) {
                        msg = "Essa editora ja foi adicionada...";
                        Utils::printMessage(msg);
                        break;
                    }

                    editoraContainer.adicionarEditora(nome);
                    msg = "Editora adicionada com sucesso!";
                    Utils::printMessage(msg);
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome da editora que quer remover");

                    if (editoraContainer.removerEditora(nome)) {
                        repositorio.eliminarEditora(nome);
                        msg = "A editora " + nome + " foi removida com sucesso.";
                    }
                    else msg = "A editora nao foi encontrada.";
                    Utils::printMessage(msg);
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
                        msg = "Ainda nao foram adicionados artistas.";
                        Utils::printMessage(msg);
                        break;
                    }

                    msg = ">>> ARTISTAS <<<";
                    for (const auto& a : artistas) {
                        msg = "- " + a.getNome() + ": " + to_string(a.getIdade()) + " anos";
                        Utils::printMessage(msg);
                    }
                }

                break;
            case 2:
                {
                    string nome = Utils::getString("Digite o nome do artista");
                    int ano = Utils::getNumber("Digite a data de nascimento/fundacao do artista");

                    if (artistaContainer.existeArtista(nome)) {
                        msg = "Esse artista ja foi adicionado...";
                        Utils::printMessage(msg);
                        break;
                    }

                    artistaContainer.adicionarArtista(Artista(nome, ano));
                    msg = "Artista adicionado com sucesso!";
                    Utils::printMessage(msg);
                }
                break;
            case 3:
                {
                    string nome = Utils::getString("Digite o nome do artista que quer remover");

                     if (artistaContainer.existeArtista(nome)) {
                        for (const auto& e : editoraContainer.getEditoras()) {
                            string nomeE = e.getNome();
                            Editora* editora = editoraContainer.procurar(nomeE);
                            editora->removerArtista(nome);
                        }
                    }

                    if (artistaContainer.removerArtista(nome)) {
                        repositorio.eliminarArtista(nome);
                        msg = "O artista " + nome + " foi removido com sucesso.";
                    }
                    else msg = "O artista nao foi encontrado.";
                    Utils::printMessage(msg);
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

void Controller::guardarDados() {
    repositorio.guardarUtilizador(utilizadorContainer.getUtilizadores());
    repositorio.guardarArtista(artistaContainer.getArtistas());
    repositorio.guardarEditora(editoraContainer.getEditoras());
    repositorio.guardarAlbum(albumContainer.getAlbuns());
    repositorio.guardarLista(listaReproducaoContainer.getListas());
}