#include "MusicaContainer.h"
#include "Musica.h"
#include "../Headers/repo/Repositorio.h"
#include <string>



std::vector<Musica> MusicaContainer::musicas;

MusicaContainer::MusicaContainer() {}

void MusicaContainer::adicionarMusica(const Musica& musica) {
    musicas.push_back(musica);
}

bool MusicaContainer::removerMusica(const std::string& nome) {
    for (auto it = musicas.begin(); it != musicas.end(); ++it) {
        if (it->getNome() == nome) {
            musicas.erase(it);
            return true;
        }
    }
    return false;
}

bool MusicaContainer::existeMusica(const std::string& nome) {
    for (auto& m : musicas) {
        if (m.getNome() == nome) return true;
    }
    return false;
}

Musica* MusicaContainer::procurarMusica(const std::string& nome) {
    for (auto& m : musicas) {
        if (m.getNome() == nome) return &m;
    }
    return nullptr;
}

const std::vector<Musica>& MusicaContainer::getMusicas() const {
    return musicas;
}

void MusicaContainer::reproduzirMusica(std::string n) {

    for (int i = 0; i < musicas.size(); i++) {
        if (musicas[i].getNome() == n) { // >>> CORRECAO: 'nome' e privado em Musica; usado o getter publico getNome()
            musicas[i].reproduzir();
        }
    }

};



