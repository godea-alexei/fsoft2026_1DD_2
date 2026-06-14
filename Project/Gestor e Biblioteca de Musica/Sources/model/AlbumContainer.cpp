#include "AlbumContainer.h"
#include "Album.h"
#include <string>
#include <iostream>
#include <vector>

void AlbumContainer::adicionarAlbum(const Album &album) {
    albuns.push_back(album);
}

Album *AlbumContainer::procurarAlbum(const string &nome) {
    for (auto& album : albuns) {
        if (album.getNome() == nome) {
            return &album;
        }
    }
    return nullptr;
}

bool AlbumContainer::existeAlbum(const string &nome) const {
    for (auto& album : albuns) {
        if (album.getNome() == nome) return true;
    }
    return false;
}

bool AlbumContainer::removerAlbum(const string &nome) {
    for (auto it = albuns.begin(); it != albuns.end(); it++) {
        if (it->getNome() == nome) {
            albuns.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Album> &AlbumContainer::getAlbuns() const {
    return albuns;
}




