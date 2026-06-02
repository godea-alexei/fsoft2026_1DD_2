#ifndef ARTISTA_H
#define ARTISTA_H
 
#include <string>
#include "Pessoa.h"
using namespace std;

class Artista : public Pessoa {
 
public:
    Artista();
    Artista(string nome);

    ~Artista();
};
 
#endif
