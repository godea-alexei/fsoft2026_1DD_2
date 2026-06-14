#include "MusicaContainer.h"
#include <string>
#include <ctime>

using namespace std;

MusicaContainer::MusicaContainer() {

}

void MusicaContainer::adicionarMusica(const Musica& musica) {
    musicas.push_back(new Musica(musica));
}

Musica *MusicaContainer::procurarMusica(const std::string &nome) {
    for (Musica* m : musicas) {
        if (m->getNome() == nome) {
            return m;
        }
    }
    return nullptr;
}

bool MusicaContainer::existeMusica(const std::string &nome) {
    for (auto* musica : musicas) {
        if (musica->getNome() == nome) {
            return true;
        }
    }
    return false;
}

bool MusicaContainer::removerMusica(const std::string &nome) {
    for (auto it = musicas.begin(); it != musicas.end(); it++) {
        if ((*it)->getNome() == nome) {
            delete *it;
            musicas.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Musica*> &MusicaContainer::getMusicas() const {
    return musicas;
}
