#include <Editora.h>
#include <list>
#include <string>
#include <iostream>

Editora::Editora(std::string nom) {
    this->nome = nom;
}

Editora::Editora(std::string nom, list<Artista> &artsts) {

    this->nome = nom;
    this->artistas = artsts;

}