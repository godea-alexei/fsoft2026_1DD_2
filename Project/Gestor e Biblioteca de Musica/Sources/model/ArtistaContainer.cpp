#include "ArtistaContainer.h"
#include <iostream>
using namespace std;



void ArtistaContainer::adicionarArtista(const Artista &artista) {
    artistas.push_back(artista);
}

bool ArtistaContainer::existeArtista(const std::string &nome) const {
    for (const auto&  a : artistas) {
        if (a.getNome() == nome) return true;
    }
    return false;
}

Artista* ArtistaContainer::procurarArtista(const std::string& nome) {
    for(auto& a : artistas)
    {
        if(a.getNome() == nome)
            return &a;
    }

    return nullptr;
}


bool ArtistaContainer::removerArtista(const string& nome) {
    for (auto it = artistas.begin(); it != artistas.end(); it++) {
        if (it->getNome() == nome) {
            artistas.erase(it);
            return true;
        }
    }
    return false;
}


const std::vector<Artista>& ArtistaContainer::getArtistas() const {
    return artistas;
}
