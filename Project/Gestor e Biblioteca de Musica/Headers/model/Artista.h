#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
#include <list>
#include "Pessoa.h"
#include "Album.h"
using namespace std;


class Artista : public Pessoa {
 
public:

    list<Album> albums;

    Artista();
    Artista(std::string nome, int ano);
    Artista(std::string nome, int ano, list<Album> &alb);
    ~Artista();

};
 
#endif
