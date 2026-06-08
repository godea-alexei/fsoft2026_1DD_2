#ifndef ARTISTACONTAINER_H
#define ARTISTACONTAINER_H

#include <string>
#include <list>
#include "Artista.h"
using namespace std;

class ArtistaContainer {

private:
    list<Artista*> artistas;

public:
    ArtistaContainer();
    ~ArtistaContainer();

    void adicionarArtista();
    void removerArtista();
    Artista* procurarArtista(string nome);
    list<Artista*>& getAll();
};

#endif
