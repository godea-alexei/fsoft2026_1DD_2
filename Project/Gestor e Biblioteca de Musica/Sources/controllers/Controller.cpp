#include <iostream>
#include <string>
#include <ctime>
#include "Controller.h"
#include "BaseView.h"
#include "Utils.h"
#include "../../Headers/repo/Repositorio.h"
#include "ContaView.h"
#include "UtilizadorContainer.h"
#include "EditoraContainer.h"
#include "Musica.h"
#include "Partilha.h"



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

Controller::~Controller(){}


// ─────────────────────────────────────────────
//  Menu principal
// ─────────────────────────────────────────────
//Printa os menus
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
                utilizadorAtual = nullptr;
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
//  Fazer Registo
// ─────────────────────────────────────────────
void Controller::runRegisto() {

    string nome = this->contaView.getNome();
    int anoNascimento = this->contaView.getAnoNascimento();
    string palavraPasse = this->contaView.getPalavraPasse();
    string palavraPasseConfirmation = this->contaView.getPalavraPasseConfirmation();

    if (utilizadorContainer.existeUtilizador(nome)) {
        msg = "Ja existe um utilizador com o nome " + nome + ".";
        Utils::printMessage(msg);
        return;
    }

    if (!Utilizador::validarPalavraPasse( palavraPasse, palavraPasseConfirmation)) {
        contaView.falhaRegisto();
        return;
    }

    Utilizador utilizador(nome, anoNascimento, palavraPasse);

    utilizadorContainer.utilizadores.push_back(utilizador);
    repositorio.guardarUtilizador(utilizador);
    contaView.sucessoRegisto();
}

// ─────────────────────────────────────────────
//  Fazer Login
// ─────────────────────────────────────────────
void Controller::runLogin() {

    string nome = contaView.getNome();
    string palavraPasse = contaView.getPalavraPasse();

    if (utilizadorContainer.autenticar(nome, palavraPasse)) {
        utilizadorAtual = utilizadorContainer.procurarUtilizador(nome);
        contaView.sucessoLogin();

        run();
    }else contaView.falhaLogin();

}




// ─────────────────────────────────────────────
//  ESCOLHER PESQUISA
// ─────────────────────────────────────────────
void Controller::runEscolherPesquisa() {
    int op = -1;
    do {
        op = this->view.menuEscolhaPesquisa();
        switch(op) {
            case 1: //procurar musica
                {
                    string titulo = Utils::getString("Insira o titulo da Musica");
                    Musica* musica = musicaContainer.procurarMusica(titulo);
                    if (musica == nullptr) {
                        msg = "Musica nao encontrada.";
                        Utils::printMessage(msg);
                        break;
                    }
                    baseView.listarAtributos(*musica);
                    break;
                }
            case 2: // procurar album
                {

                    string nome = Utils::getString("Insira o nome do Album");
                    Album* album = albumContainer.procurarAlbum(nome);
                    if (album == nullptr) {
                        msg = "Album nao encontrado";
                        Utils::printMessage(msg);
                        break;
                    }

                    baseView.listarAtributos(*album);
                    break;
                }

            case 3: // procurar editora
                {
                    string nome = Utils::getString("Insira o nome da editora");
                    Editora* editora = editoraContainer.procurar(nome);
                    if (editora == nullptr) {
                        msg = "Editora nao encontrada";
                        Utils::printMessage(msg);
                        break;
                    }
                    baseView.listarAtributos(*editora);
                    break;
                }

            case 4: {
                string nome = Utils::getString("Insira o nome do artista");
                Artista* artista = artistaContainer.procurarArtista(nome);
                if (artista == nullptr) {
                    msg = "Artista nao encontrado.";
                    Utils::printMessage(msg);
                    break;
                }
                baseView.listarAtributos(*artista);
                break;
            }
            case 5: {
                string nome = Utils::getString("Insira o nome da Lista de Reproducao");
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nome);
                if (listaReproducao == nullptr) {
                    msg = "Lista de Reproducao nao encontrada";
                    Utils::printMessage(msg);
                    break;
                }
                baseView.listarAtributos(*listaReproducao);
                break;
            }
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
            case 1: { //listar playlists

                    const auto& listas = listaReproducaoContainer.getListas();
                    if (listas.empty()) {
                        msg = "Ainda nao foram adicionadas listas de reproducao.";
                        Utils::printMessage(msg);
                        break;
                    }
                    else {
                        for (const auto& l : listas) {baseView.listarObjeto(l);}
                    }


                    msg = ">>> AS SUAS LISTAS DE REPRODUCAO <<<";
                    Utils::printMessage(msg);
                    for (const auto& l : listas) {
                        if (l.getCriador() == utilizadorAtual->getNome()){ //VERIFICAÇÂO DO DONO DA LISTA
                            baseView.listarObjeto(l);
                        }
                    }

                }
                break;
            case 2: { //criar lista

                string nome = Utils::getString("Digite o nome da Lista de Reproducao");
                if (listaReproducaoContainer.existeLista(nome)) {
                    msg = "Essa Lista de Reproducao ja foi adicionada...";
                    Utils::printMessage(msg);
                    break;
                }

                time_t t = time(0);
                tm* now = localtime(&t);
                int ano = now->tm_year + 1900;

                ListaReproducao lista = ListaReproducao(nome, ano, utilizadorAtual->getNome());
                listaReproducaoContainer.adicionarLista(lista);
                repositorio.guardarLista(lista);

                msg = "Lista de Reproducao criada com sucesso!";
                Utils::printMessage(msg);
                break;

            }
            case 3: { //apagar lista

                    string nome = Utils::getString("Digite o nome da Lista de Reproducao que quer remover");
                    ListaReproducao* lista = listaReproducaoContainer.procurar(nome);
                    if (lista->getCriador() != utilizadorAtual->getNome() ) {
                        msg = "So o criador da Lista de Reproducao tem permissao para alterar a lista  de reproducao " + lista->getNome();
                        Utils::printMessage(msg);
                        break;
                    }
                    if (listaReproducaoContainer.existeLista(nome) && listaReproducaoContainer.procurar(nome)->criador == utilizadorAtual->getNome()) {
                        if (listaReproducaoContainer.removerLista(nome)) {
                            repositorio.eliminarLista(nome);
                            msg = "A Lista de Reproducao " + nome + " foi removida com sucesso.";
                            Utils::printMessage(msg);
                        }
                    }
                    else msg = "A Lista de Reproducao nao foi encontrada.";
                    Utils::printMessage(msg);
                    break;

            }
            case 4: { //adicionar musica á lista

                string nomeLista = Utils::getString("Insira o nome da Lista");
                ListaReproducao* lista = listaReproducaoContainer.procurar(nomeLista);
                if (lista->getCriador() != utilizadorAtual->getNome() ) {
                    msg = "So o criador da Lista de Reproducao tem permissao para alterar a lista  de reproducao " + lista->getNome();
                    Utils::printMessage(msg);
                    break;
                }
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nomeLista);
                if (listaReproducao == nullptr) {
                    msg = "Lista de reproducao nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da Musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    msg = "Musica nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (listaReproducao->existeMusica(nomeMusica)) {
                    msg = "Musica ja esta adicionada a esta Lista de Reproducao.";
                    Utils::printMessage(msg);
                    break;
                }

                listaReproducao->adicionarMusica(musica);
                repositorio.eliminarLista(nomeLista);
                repositorio.guardarLista(*listaReproducao);
                ListaReproducao a = *listaReproducao;
                listaReproducaoContainer.removerLista(nomeMusica);
                listaReproducaoContainer.adicionarLista(a);
                msg = "Musica adicionada com sucesso! ";
                break;

            }
            case 5: { //eliminar musica da playlist
                string nomeLista = Utils::getString("Insira o nome da Lista");
                ListaReproducao* lista = listaReproducaoContainer.procurar(nomeLista);
                if (lista->getCriador() != utilizadorAtual->getNome() ) {
                    msg = "So o criador da Lista de Reproducao tem permissao para alterar a lista  de reproducao " + lista->getNome();
                    Utils::printMessage(msg);
                    break;
                }
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nomeLista);
                if (listaReproducao == nullptr) {
                    msg = "Nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    msg = "Musica nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (!listaReproducao->existeMusica(nomeMusica)) {
                    msg = "Musica nao esta associada a esta Lista de Reproducao.";
                    Utils::printMessage(msg);
                    break;
                }

                listaReproducao->removerMusica(nomeMusica);
                repositorio.eliminarLista(nomeLista);
                repositorio.guardarLista(*listaReproducao);
                ListaReproducao a = *listaReproducao;
                listaReproducaoContainer.removerLista(nomeMusica);
                listaReproducaoContainer.adicionarLista(a);
                msg = "Musica removida com sucesso! ";
                Utils::printMessage(msg);
                break;

            }case 6: { //ver musicas numa playlist
                string nomeLista = Utils::getString("Insira o nome da Lista");
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nomeLista);
                if (listaReproducao == nullptr) {
                    msg = "Nao existe.";
                    Utils::printMessage(msg);
                    break;
                }
                baseView.listarAtributos(*listaReproducao);
                break;
            }
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
          case 1: //listr musicas
            {
                    const auto& musicas = musicaContainer.getMusicas();

                    if (musicas.empty()) {
                        msg = "Ainda nao foram adicionadas Musicas.";
                        Utils::printMessage(msg);
                        break;
                    }

                    msg = ">>> MUSICAS <<<";
                    Utils::printMessage(msg);
                    for (const auto& m : musicas) {
                        baseView.listarObjeto(m);
                    }
              
                    break;    
            }
            case 2: //adicionar musica
                {
                    string nome = Utils::getString("Digite o Titulo da Musica");
                    if (musicaContainer.existeMusica(nome)) {
                        msg = "Essa Musica ja foi adicionada...";
                        Utils::printMessage(msg);
                        break;
                    }
                    int dur = Utils::getNumber("Digite a duracao da musica (em minutos)");
                    int ano = Utils::getNumber("Digite o ano de lancamento da musica");
                    string letra = Utils::getString("Digite a letra da musica");
                    string genero = Utils::getString("Digite o genero da musica");
                    string caminho = Utils::getString("Digite o caminho absoluto da musica");
                    string artista = Utils::getString("Digite o artista da Musica");

                    Musica musica = Musica(nome, dur, ano, letra, genero, caminho, artista);

                    musicaContainer.adicionarMusica(musica);
                    Repositorio::guardarMusica(musica);

                    break;

                }
            case 3: //eliminar de musicas
                {
                    string nome = Utils::getString("Digite o nome da Musica que quer remover");
                    if (musicaContainer.removerMusica(nome)) {
                        repositorio.eliminarMusica(nome);
                        msg = "A Musica " + nome + " foi removida com sucesso.";
                    }
                    else msg = "A musica nao foi encontrada.";
                    Utils::printMessage(msg);

                    break;
                }
            case 4: { //reprodução

              string nome = Utils::getString("Digite o Titulo da Musica");
              if (musicaContainer.existeMusica(nome)) {
                  musicaContainer.procurarMusica(nome)->reproduzir();
                  break;
              }
              msg = "Musica nao encontrada";
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
                        baseView.listarObjeto(a);
                    }
                break;
            }
            case 2:{

                string nome = Utils::getString("Digite o nome do Album");

                if (albumContainer.existeAlbum(nome)) {
                    msg = "Esse Album ja foi adicionado...";
                    Utils::printMessage(msg);
                    break;
                }
                int ano = Utils::getNumber("Digite o ano de lancamento do Album");

                Album album = Album(nome, ano);
                albumContainer.adicionarAlbum(album);
                repositorio.guardarAlbum(album);

                msg = "Album adicionado com sucesso!";
                Utils::printMessage(msg);
                break;
            }
            case 3:
                {
                    string nome = Utils::getString("Digite o nome do Album que quer remover");
                    if (albumContainer.removerAlbum(nome)) {
                        repositorio.eliminarAlbum(nome);
                        msg = "O Album " + nome + " foi removido com sucesso.";
                    }
                    else msg = "O Album nao foi encontrado.";
                    Utils::printMessage(msg);
                    break;
                }
            case 4: {

                string nomeAlbum = Utils::getString("Insira o nome do Album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    msg = "Nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da Musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    msg = "Musica nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (album->existeMusica(nomeMusica)) {
                    msg = "Musica ja foi adicionada a este album.";
                    Utils::printMessage(msg);
                    break;
                }

                album->adicionarMusica(musica);
                repositorio.eliminarAlbum(nomeAlbum);
                repositorio.guardarAlbum(*album);
                Album a = *album;
                albumContainer.removerAlbum(nomeAlbum);
                albumContainer.adicionarAlbum(a);
                msg = "Musica adicionada com sucesso! ";
                Utils::printMessage(msg);
                break;
            }
            case 5: {
                string nomeAlbum = Utils::getString("Insira o nome do Album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    msg = "Nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    msg = "Musica nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (!album->existeMusica(nomeMusica)) {
                    msg = "Musica nao esta associada a este album.";
                    Utils::printMessage(msg);
                    break;
                }

                album->removerMusica(nomeMusica);
                repositorio.eliminarAlbum(nomeAlbum);
                repositorio.guardarAlbum(*album);
                Album a = *album;
                albumContainer.removerAlbum(nomeAlbum);
                albumContainer.adicionarAlbum(a);
                msg = "Musica removida com sucesso! ";
                Utils::printMessage(msg);
                break;
            }
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
                        baseView.listarObjeto(e);
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
                    Editora editora = Editora(nome);
                    editoraContainer.adicionarEditora(editora);
                    repositorio.guardarEditora(editora);
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
            case 4: {
                string nomeEditora = Utils::getString("Insira o nome da editora: ");
                Editora* editora = editoraContainer.procurar(nomeEditora);
                if (editora == nullptr) {
                    msg = "Editora nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeArtista = Utils::getString("Insira o nome do artista a associar: ");
                Artista* artista = artistaContainer.procurarArtista(nomeArtista);
                if (artista == nullptr) {
                    msg = "Artista nao existe.";
                    Utils::printMessage(msg);
                    break;
                }
                if (editora->existeArtista(nomeArtista)) {
                    msg = "Artista ja esta associado a esta editora.";
                    Utils::printMessage(msg);
                    break;
                }

                editora->adicionarArtista(artista);
                repositorio.eliminarEditora(nomeEditora);
                repositorio.guardarEditora(*editora);
                Editora a = *editora;
                editoraContainer.removerEditora(nomeEditora);
                editoraContainer.adicionarEditora(a);

                msg = "Artista adicionado com sucesso! ";
                Utils::printMessage(msg);
                break;

            }
            case 5: {

                string nomeEditora = Utils::getString("Insira o nome da editora: ");
                Editora* editora = editoraContainer.procurar(nomeEditora);
                if (editora == nullptr) {
                    msg = "Editora nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeA = Utils::getString("Insira o nome do artista");
                Artista* artista = artistaContainer.procurarArtista(nomeA);
                if (artista == nullptr) {
                    msg = "Artista nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (!editora->existeArtista(nomeA)) {
                    msg = "Artista nao esta associado a editora.";
                    Utils::printMessage(msg);
                    break;
                }

                editora->removerArtista(nomeA);
                repositorio.eliminarEditora(nomeEditora);
                repositorio.guardarEditora(*editora);
                Editora a = *editora;
                editoraContainer.removerEditora(nomeEditora);
                editoraContainer.adicionarEditora(a);
                msg = "Artista removido com sucesso! ";
                Utils::printMessage(msg);
                break;

            }
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
            case 1: //listar artistas
                {
                    const auto& artistas = artistaContainer.getArtistas();
                    if (artistas.empty()) {
                        msg = "Ainda nao foram adicionados artistas.";
                        Utils::printMessage(msg);
                        break;
                    }

                    msg = ">>> ARTISTAS <<<";
                    Utils::printMessage(msg);
                    for (const auto& a : artistas) {
                        baseView.listarObjeto(a);
                    }
                }

                break;
            case 2: //adicionar artistas
            {
                string nome = Utils::getString("Digite o nome do artista");
                int ano = Utils::getNumber("Digite a data de nascimento/fundacao do artista");

                if (artistaContainer.existeArtista(nome)) {
                    msg = "Esse artista ja foi adicionado...";
                    Utils::printMessage(msg);
                    break;
                }
                Artista artista = Artista(nome, ano);
                artistaContainer.adicionarArtista(artista);
                repositorio.guardarArtista(artista);

                msg = "Artista adicionado com sucesso!";
                Utils::printMessage(msg);

                break;

            }
            case 3: {

                string nome = Utils::getString("Digite o nome do artista que quer remover");
                if (artistaContainer.removerArtista(nome)) {
                    repositorio.eliminarArtista(nome);
                    msg = "O artista " + nome + " foi removido com sucesso.";
                }
                else msg = "O artista nao foi encontrado.";
                Utils::printMessage(msg);

                break;

            }
            case 4: { //adicionar album ao artista

                string nomeArtista = Utils::getString("Insira o nome do Artista: ");
                Artista* artista = artistaContainer.procurarArtista(nomeArtista);
                if (artista == nullptr) {
                    msg = "Nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeAlbum = Utils::getString("Insira o nome do Album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    msg = "Album nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (artista->existeAlbum(nomeAlbum)) {
                    msg = "Album ja esta associado a este artista.";
                    Utils::printMessage(msg);
                    break;
                }
                artista->adicionarAlbum(album);
                repositorio.eliminarArtista(nomeArtista);
                repositorio.guardarArtista(*artista);
                Artista a = *artista;
                artistaContainer.removerArtista(nomeArtista);
                artistaContainer.adicionarArtista(a);
                msg = "Album adicionado com sucesso! ";
                Utils::printMessage(msg);

                break;

            }
            case 5: { //remover album do artista

                string nomeArtista = Utils::getString("Insira o nome do Artista: ");
                Artista* artista = artistaContainer.procurarArtista(nomeArtista);
                if (artista == nullptr) {
                    msg = "Nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                string nomeAlbum = Utils::getString("Insira o nome do album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    msg = "Album nao existe.";
                    Utils::printMessage(msg);
                    break;
                }

                if (!artista->existeAlbum(nomeAlbum)) {
                    msg = "Album nao esta associado ao artista.";
                    Utils::printMessage(msg);
                    break;
                }

                artista->removerAlbum(nomeAlbum);
                repositorio.eliminarArtista(nomeArtista);
                repositorio.guardarArtista(*artista);
                Artista a = *artista;
                artistaContainer.removerArtista(nomeArtista);
                artistaContainer.adicionarArtista(a);
                msg = "Album removido com sucesso! ";
                Utils::printMessage(msg);

                break;

            }

            default:
                break;
        }
    } while(op != 0);
}






// ─────────────────────────────────────────────
//  PARTILHA
// ─────────────────────────────────────────────
void Controller::runPartilhar() {
    int op = -1;
    do {
        op = this->view.menuPartilha();
        switch(op) {
            case 1: // Partilhar Musica
            {

                string nomeDestinatario = Utils::getString("Insire nome do utilizador com quem queres partilhar");
                Utilizador* destinatario = utilizadorContainer.procurarUtilizador(nomeDestinatario);
                if (destinatario == nullptr) {
                    msg = "Esse utilizador nao existe.";
                    Utils::printMessage(msg);
                    return;
                }

                string nomeMusica = Utils::getString("Insere nome da musica que queres partilhar");
                if (!musicaContainer.existeMusica(nomeMusica)) {
                    msg = "Essa musica nao existe.";
                    Utils::printMessage(msg);
                    return;
                }

                string mensagem = "O utilizador " + utilizadorAtual->getNome() + " acha que podes gostar desta musica: " + nomeMusica;
                Partilha::partilharMusica(destinatario,mensagem);
                msg = "Musica partilhada com " + nomeDestinatario + " com sucesso!";
                Utils::printMessage(msg);

                break;

            }
            case 2: // Partilhar Lista de Reproducao
            {
                string nomeDestinatario = Utils::getString("Nome do utilizador com quem queres partilhar");
                Utilizador* destinatario = utilizadorContainer.procurarUtilizador(nomeDestinatario);
                if (destinatario == nullptr) {
                    msg = "Esse utilizador nao existe.";
                    Utils::printMessage(msg);
                    return;
                }

                string nomeLista = Utils::getString("Nome da lista de reproducao que queres partilhar");
                ListaReproducao* original = listaReproducaoContainer.procurar(nomeLista);
                if (original == nullptr) {
                    msg = "Essa lista de reproducao nao existe.";
                    Utils::printMessage(msg);
                    return;
                }

                Partilha::partilharLista(destinatario, original, listaReproducaoContainer);

                msg = "Lista de reproducao partilhada com " + nomeDestinatario + " com sucesso!\n";
                Utils::printMessage(msg);

                break;
            }
            default:
                break;
        }
    } while(op != 0);
}







