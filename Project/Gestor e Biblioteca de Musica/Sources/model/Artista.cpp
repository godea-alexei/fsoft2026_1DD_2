#include "Artista.h"
#include <list>
#include <string>
#include <iostream>
#include <Pessoa.h>
#include "Album.h"
using namespace std;

Artista::Artista() : Pessoa() {}

Artista::Artista(string nome, int ano) : Pessoa(nome, ano) {

    this->nome = nome;
    this->anoNascimento = ano;

}

string Artista::getNome() const {
    return this->nome;
}

int Artista::getAno() {
    return this->anoNascimento;
}


Artista::Artista(string nome, int ano, list<Album> &a) : Pessoa(nome, ano) {

    this->nome = nome;
    this->anoNascimento = ano;
    this->albums = a;

}

void Artista::adicionarAlbum(Album *album) {
    albuns.push_back(album);
}

bool Artista::existeAlbum(const string& nome) const {
    for (const auto& album : albuns) {
        if (album->getNome() == nome) return true;
    }
    return false;
}

Album *Artista::procurarAlbum(const std::string &nome) {
    for (auto& album : albuns) {
        if (album->getNome() == nome) return album;
    }
    return nullptr;
}

bool Artista::removerAlbum(const std::string &nome) {
    for (auto it = albuns.begin(); it != albuns.end(); it++) {
        if ((*it)->getNome() == nome) {
            albuns.erase(it);
            return true;
        }
    }
    return false;
}

const std::vector<Album *> &Artista::getAlbuns() const {
    return albuns;
}




Artista::~Artista(){}