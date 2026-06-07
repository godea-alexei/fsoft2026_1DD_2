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

Artista::Artista(string nome, int ano, list<Album> &a) : Pessoa(nome, ano) {

    this->nome = nome;
    this->anoNascimento = ano;
    this->albums = a;

}

Artista::~Artista(){}

