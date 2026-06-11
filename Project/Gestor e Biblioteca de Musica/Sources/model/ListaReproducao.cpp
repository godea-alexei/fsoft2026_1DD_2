#include <string>
#include <list>
#include <Musica.h>
#include <ListaReproducao.h>
using namespace std;

ListaReproducao::ListaReproducao() {

}

ListaReproducao::ListaReproducao(string nome, int dataCriacao) {
    this->nome = nome;
    this->dataCriacao = dataCriacao;
}

string ListaReproducao::getNome() const {
    return nome;
}

int ListaReproducao::getDataCriacao() const {
    return dataCriacao;
}

int ListaReproducao::getDuracao() const {
    int total = 0;

    for (const auto& musica : musicas) {
        total += musica.getDuracao();
    }
    return total;
}

void ListaReproducao::adicionarMusica(const Musica& musica) {
    musicas.push_back(musica);
}

bool ListaReproducao::removerMusica(const string &titulo) {
    for (auto it =  musicas.begin(); it != musicas.end(); it++) {
        if (it->getNome() == titulo) {
            musicas.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Musica>& ListaReproducao::getMusicas() const {
    return musicas;
}






ListaReproducao::~ListaReproducao(){}