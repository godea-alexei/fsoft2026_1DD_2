#ifndef ARTISTACONTAINER_H
#define ARTISTACONTAINER_H
 
#include <string>
#include <vector>
#include "Artista.h"
using namespace std;

class ArtistaContainer {
 
private:
    vector<Artista*> artistas;
 
public:
    ArtistaContainer();
    ~ArtistaContainer();

    void adicionarArtista(string nome, int ano);
    void removerArtista(string nome);
    Artista* procurarArtista(string nome);
    vector<Artista*>& getAll();
};
 
#endif
