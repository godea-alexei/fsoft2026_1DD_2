#include <string>
#include <list>
#include <Musica.h>
#include <ListaReproducao.h>
using namespace std;

ListaReproducao::ListaReproducao() {

ListaReproducao::ListaReproducao(string nome, int dataCriacao, string criador) {
    this->nome = nome;
    this->dataCriacao = dataCriacao;
    this->criador = criador;
}

string ListaReproducao::getNome() const {
    return nome;
}

string ListaReproducao::getCriador() const {
    return criador;
}

int ListaReproducao::getDataCriacao() const {
    return dataCriacao;
}

int ListaReproducao::getDuracao() const {
    int total = 0;

    for (const auto& musica : musicas) {
        total += musica->getDuracao();
    }
    return total;
}

void ListaReproducao::adicionarMusica(Musica* musica) {
    musicas.push_back(musica);
}

bool ListaReproducao::existeMusica(const std::string &titulo) const {
    for (const auto& musica : musicas) {
        if (musica->getNome() == titulo) {
            return true;
        }
    }
    return false;
}

Musica *ListaReproducao::procurarMusica(const std::string& titulo) {
    for (auto& musica : musicas) {
        if (musica->getNome() == titulo) return musica;
    }
    return nullptr;
}


bool ListaReproducao::removerMusica(const string& titulo) {
    for (auto it =  musicas.begin(); it != musicas.end(); it++) {
        if ((*it)->getNome() == titulo) {
            musicas.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Musica*>& ListaReproducao::getMusicas() const {
    return musicas;
}






ListaReproducao::~ListaReproducao(){}