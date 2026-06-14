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
        cout << "Ja existe um utilizador com o nome " << nome << "." << endl;
        return;
    }

    if (!Utilizador::validarPalavraPasse( palavraPasse, palavraPasseConfirmation)) {
        contaView.falhaRegisto();
        return;
    }

    Utilizador utilizador(nome, anoNascimento, palavraPasse);

    utilizadorContainer.utilizadores.push_back(utilizador);
    repositorio.guardarUtilizador(utilizador);
    cout<<"utilizador registado com sucesso";
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
                        cout << "Musica nao existe.\n";
                        break;}
                    baseView.listarAtributos(*musica);
                    break;
                }
            case 2: // procurar album
                {

                    string nome = Utils::getString("Insira o nome do Album");
                    Album* album = albumContainer.procurarAlbum(nome);
                    if (album == nullptr) {
                        cout << "Album nao encontrado.\n";
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
                        cout << "Editora nao encontrada.\n";
                        break;
                    }
                    baseView.listarAtributos(*editora);
                    break;
                }

            case 4: {
                string nome = Utils::getString("Insira o nome do artista");
                Artista* artista = artistaContainer.procurarArtista(nome);
                if (artista == nullptr) {
                    cout << "Artista nao encontrado.\n";
                    break;
                }
                baseView.listarAtributos(*artista);
                break;
            }
            case 5: {
                string nome = Utils::getString("Insira o nome da Lista de Reproducao");
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nome);
                if (listaReproducao == nullptr) {
                    cout << "Lista de Reproducao nao encontrada.\n";
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
                        cout << "Ainda nao foram adicionadas listas de reproducao.\n";
                        break;
                    }


                    cout << ">>> AS SUAS LISTAS DE REPRODUCAO <<<" << endl;
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
                    cout << "Essa Lista de Reproducao ja foi adicionada...\n";
                    break;
                }

                time_t t = time(0);
                tm* now = localtime(&t);
                int ano = now->tm_year + 1900;

                ListaReproducao lista = ListaReproducao(nome, ano, utilizadorAtual->getNome());
                listaReproducaoContainer.adicionarLista(lista);
                repositorio.guardarLista(lista);

                cout << "Lista de Reproducao criada com sucesso!" << endl;
                break;

            }
            case 3: { //apagar lista

                    string nome = Utils::getString("Digite o nome da Lista de Reproducao que quer remover");

                    if (listaReproducaoContainer.existeLista(nome) && listaReproducaoContainer.procurar(nome)->criador == utilizadorAtual->getNome()) {
                        if (listaReproducaoContainer.removerLista(nome)) {
                            repositorio.eliminarLista(nome);
                            cout << "A Lista de Reproducao " << nome << " foi removida com sucesso." << endl;
                        }
                    }
                    cout << "A Lista de Reproducao nao foi encontrada." << endl;
                    break;

            }
            case 4: { //adicionar musica á lista

                string nomeLista = Utils::getString("Insira o nome da Lista");
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nomeLista);
                if (listaReproducao == nullptr) {
                    cout << "Nao existe.\n";
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da Musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    cout << "Musica nao existe.\n";
                    break;
                }

                if (listaReproducao->existeMusica(nomeMusica)) {
                    cout << "Musica ja esta adicionada a esta Lista de Reproducao.\n";
                    break;
                }

                listaReproducao->adicionarMusica(musica);
                repositorio.eliminarLista(nomeLista);
                repositorio.guardarLista(*listaReproducao);
                ListaReproducao a = *listaReproducao;
                listaReproducaoContainer.removerLista(nomeMusica);
                listaReproducaoContainer.adicionarLista(a);
                cout << "Musica adicionada com sucesso! " << endl;
                break;

            }
            case 5: { //eliminar musica da playlist
                string nomeLista = Utils::getString("Insira o nome da Lista");
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nomeLista);
                if (listaReproducao == nullptr) {
                    cout << "Nao existe.\n";
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    cout << "Musica nao existe.\n";
                    break;
                }

                if (!listaReproducao->existeMusica(nomeMusica)) {
                    cout << "Musica nao esta associada a esta Lista de Reproducao.\n";
                    break;
                }

                listaReproducao->removerMusica(nomeMusica);
                repositorio.eliminarLista(nomeLista);
                repositorio.guardarLista(*listaReproducao);
                ListaReproducao a = *listaReproducao;
                listaReproducaoContainer.removerLista(nomeMusica);
                listaReproducaoContainer.adicionarLista(a);
                cout << "Musica removida com sucesso! " << endl;
                break;

            }case 6: { //ver musicas numa playlist
                string nomeLista = Utils::getString("Insira o nome da Lista");
                ListaReproducao* listaReproducao = listaReproducaoContainer.procurar(nomeLista);
                if (listaReproducao == nullptr) {
                    cout << "Nao existe.\n";
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
                        cout << "Ainda nao foram adicionadas Musicas.\n";
                        break;
                    }

                    cout << ">>> MUSICAS <<<" << endl;
                    for (const auto& m : musicas) {
                        baseView.listarObjeto(m);
                    }
              
                    break;    
            }
            case 2: //adicionar musica
                {
                    string nome = Utils::getString("Digite o Titulo da Musica");
                    if (musicaContainer.existeMusica(nome)) {
                      cout << "Essa Musica ja foi adicionada..." << endl;
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
                        cout << "A Musica " << nome << " foi removida com sucesso." << endl;
                    }
                    else
                        cout << "A musica nao foi encontrada." << endl;

                    break;
                }
            case 4: { //reprodução

              string nome = Utils::getString("Digite o Titulo da Musica");
              if (musicaContainer.existeMusica(nome)) {
                  musicaContainer.procurarMusica(nome)->reproduzir();
                  break;
              }
              cout << "Musica nao encontrada" << endl;
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
                        baseView.listarObjeto(a);
                    }
                break;
            }
            case 2:{

                string nome = Utils::getString("Digite o nome do Album");

                if (albumContainer.existeAlbum(nome)) {
                    cout << "Esse Album ja foi adicionado...\n";
                    break;
                }
                int ano = Utils::getNumber("Digite o ano de lancamento do Album");

                Album album = Album(nome, ano);
                albumContainer.adicionarAlbum(album);
                repositorio.guardarAlbum(album);

                cout << "Album adicionado com sucesso!" << endl;
                break;
            }
            case 3:
                {
                    string nome = Utils::getString("Digite o nome do Album que quer remover");
                    if (albumContainer.removerAlbum(nome)) {
                        repositorio.eliminarAlbum(nome);
                        cout << "O Album " << nome << " foi removido com sucesso." << endl;
                    }
                    else
                        cout << "O Album nao foi encontrado." << endl;

                    break;
                }
            case 4: {

                string nomeAlbum = Utils::getString("Insira o nome do Album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    cout << "Nao existe.\n";
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da Musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    cout << "Musica nao existe.\n";
                    break;
                }

                if (album->existeMusica(nomeMusica)) {
                    cout << "Musica ja foi adicionada a este album.\n";
                    break;
                }

                album->adicionarMusica(musica);
                repositorio.eliminarAlbum(nomeAlbum);
                repositorio.guardarAlbum(*album);
                Album a = *album;
                albumContainer.removerAlbum(nomeAlbum);
                albumContainer.adicionarAlbum(a);
                cout << "Musica adicionada com sucesso! " << endl;
                break;
            }
            case 5: {
                string nomeAlbum = Utils::getString("Insira o nome do Album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    cout << "Nao existe.\n";
                    break;
                }

                string nomeMusica = Utils::getString("Insira o nome da musica");
                Musica* musica = musicaContainer.procurarMusica(nomeMusica);
                if (musica == nullptr) {
                    cout << "Musica nao existe.\n";
                    break;
                }

                if (!album->existeMusica(nomeMusica)) {
                    cout << "Musica nao esta associada a este album.\n";
                    break;
                }

                album->removerMusica(nomeMusica);
                repositorio.eliminarAlbum(nomeAlbum);
                repositorio.guardarAlbum(*album);
                Album a = *album;
                albumContainer.removerAlbum(nomeAlbum);
                albumContainer.adicionarAlbum(a);
                cout << "Musica removida com sucesso! " << endl;
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
                        cout << "Ainda nao foram adicionadas editoras.\n";
                        break;
                    }
                    cout << ">>> EDITORAS <<<" << endl;
                    for (const auto& e : editoras) {
                        baseView.listarObjeto(e);
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
                    Editora editora = Editora(nome);
                    editoraContainer.adicionarEditora(editora);
                    repositorio.guardarEditora(editora);
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
            case 4: {
                string nomeEditora = Utils::getString("Insira o nome da editora: ");
                Editora* editora = editoraContainer.procurar(nomeEditora);
                if (editora == nullptr) {
                    cout << "Editora nao existe.\n";
                    break;
                }

                string nomeArtista = Utils::getString("Insira o nome do artista a associar: ");
                Artista* artista = artistaContainer.procurarArtista(nomeArtista);
                if (artista == nullptr) {
                    cout << "Artista nao existe.\n";
                    break;
                }
                if (editora->existeArtista(nomeArtista)) {
                    cout << "Artista ja esta associado a esta editora.\n";
                    break;
                }

                editora->adicionarArtista(artista);
                repositorio.eliminarEditora(nomeEditora);
                repositorio.guardarEditora(*editora);
                Editora a = *editora;
                editoraContainer.removerEditora(nomeEditora);
                editoraContainer.adicionarEditora(a);

                cout << "Artista adicionado com sucesso! " << endl;
                break;

            }
            case 5: {

                string nomeEditora = Utils::getString("Insira o nome da editora: ");
                Editora* editora = editoraContainer.procurar(nomeEditora);
                if (editora == nullptr) {
                    cout << "Editora nao existe.\n";
                    break;
                }

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
                repositorio.eliminarEditora(nomeEditora);
                repositorio.guardarEditora(*editora);
                Editora a = *editora;
                editoraContainer.removerEditora(nomeEditora);
                editoraContainer.adicionarEditora(a);
                cout << "Artista removido com sucesso! " << endl;
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
                        cout << "Ainda nao foram adicionados artistas.\n";
                        break;
                    }

                    cout << ">>> ARTISTAS <<<" << endl;
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
                    cout << "Esse artista ja foi adicionado...\n";
                    break;
                }
                Artista artista = Artista(nome, ano);
                artistaContainer.adicionarArtista(artista);
                repositorio.guardarArtista(artista);

                cout << "Artista adicionado com sucesso!" << endl;

                break;

            }
            case 3: {

                string nome = Utils::getString("Digite o nome do artista que quer remover");
                if (artistaContainer.removerArtista(nome)) {
                    repositorio.eliminarArtista(nome);
                    cout << "O artista " << nome << " foi removido com sucesso." << endl;
                }
                else
                    cout << "O artista nao foi encontrado." << endl;

                break;

            }
            case 4: { //adicionar album ao artista

                string nomeArtista = Utils::getString("Insira o nome do Artista: ");
                Artista* artista = artistaContainer.procurarArtista(nomeArtista);
                if (artista == nullptr) {
                    cout << "Nao existe.\n";
                    break;
                }

                string nomeAlbum = Utils::getString("Insira o nome do Album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    cout << "Album nao existe.\n";
                    break;
                }

                if (artista->existeAlbum(nomeAlbum)) {
                    cout << "Album ja esta associado a este artista.\n";
                    break;
                }
                artista->adicionarAlbum(album);
                repositorio.eliminarArtista(nomeArtista);
                repositorio.guardarArtista(*artista);
                Artista a = *artista;
                artistaContainer.removerArtista(nomeArtista);
                artistaContainer.adicionarArtista(a);
                cout << "Album adicionado com sucesso! " << endl;

                break;

            }
            case 5: { //remover album do artista

                string nomeArtista = Utils::getString("Insira o nome do Artista: ");
                Artista* artista = artistaContainer.procurarArtista(nomeArtista);
                if (artista == nullptr) {
                    cout << "Nao existe.\n";
                    break;
                }

                string nomeAlbum = Utils::getString("Insira o nome do album");
                Album* album = albumContainer.procurarAlbum(nomeAlbum);
                if (album == nullptr) {
                    cout << "Album nao existe.\n";
                    break;
                }

                if (!artista->existeAlbum(nomeAlbum)) {
                    cout << "Album nao esta associado ao artista.\n";
                    break;
                }

                artista->removerAlbum(nomeAlbum);
                repositorio.eliminarArtista(nomeArtista);
                repositorio.guardarArtista(*artista);
                Artista a = *artista;
                artistaContainer.removerArtista(nomeArtista);
                artistaContainer.adicionarArtista(a);
                cout << "Album removido com sucesso! " << endl;

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
                    cout << "Esse utilizador nao existe.\n";
                    return;
                }

                string nomeMusica = Utils::getString("Insere nome da musica que queres partilhar");
                if (!musicaContainer.existeMusica(nomeMusica)) {
                    cout << "Essa musica nao existe.\n";
                    return;
                }

                string mensagem = "O utilizador " + utilizadorAtual->getNome() + " acha que podes gostar desta musica: " + nomeMusica;
                Partilha::partilharMusica(destinatario,mensagem);
                cout << "Musica partilhada com " << nomeDestinatario << " com sucesso!\n";

                break;

            }
            case 2: // Partilhar Lista de Reproducao
            {
                string nomeDestinatario = Utils::getString("Nome do utilizador com quem queres partilhar");
                Utilizador* destinatario = utilizadorContainer.procurarUtilizador(nomeDestinatario);
                if (destinatario == nullptr) {
                    cout << "Esse utilizador nao existe.\n";
                    return;
                }

                string nomeLista = Utils::getString("Nome da lista de reproducao que queres partilhar");
                ListaReproducao* original = listaReproducaoContainer.procurar(nomeLista);
                if (original == nullptr) {
                    cout << "Essa lista de reproducao nao existe.\n";
                    return;
                }

                Partilha::partilharLista(destinatario, original, listaReproducaoContainer);

                cout << "Lista de reproducao partilhada com " << nomeDestinatario << " com sucesso!\n";

                break;
            }
            default:
                break;
        }
    } while(op != 0);
}







