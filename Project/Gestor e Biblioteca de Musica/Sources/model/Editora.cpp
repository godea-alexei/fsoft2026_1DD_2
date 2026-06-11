#include <Editora.h>
#include <list>
#include <string>
#include <iostream>

using namespace std;

Editora::Editora() {
}

Editora::Editora(string nome) {
    this->nome = nome;
}

string Editora::getNome() const {
    return nome;
}

void Editora::adicionarArtista(const Artista &artista) {
    artistas.push_back(artista);
}

bool Editora::existeArtista(const string &nome) {
    for (const auto& a : artistas) {
        if (getNome() == nome) return true;
    }
    return false;
}

bool Editora::removerArtista(const string &nome) {
    for (auto it = artistas.begin(); it != artistas.end(); it++) {
        if (it->getNome() == nome) {
            artistas.erase(it);
            return true;
        }
    }
    return false;
}

const std::vector<Artista>& Editora::getArtistas() const {
    return artistas;
}


