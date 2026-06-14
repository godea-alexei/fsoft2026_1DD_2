#ifndef EDITORA_H
#define EDITORA_H
#include <vector>
#include "Artista.h"
#include <string>
using namespace std;

class Editora {
public:

    string nome;
    vector<Artista*> artistas;
    Editora();
    Editora(string nome);
    string getNome() const;

    void adicionarArtista(Artista* artista);
    bool removerArtista(const string& nome);
    bool existeArtista(const string& nome);
    Artista* procurarArtista(const string& nome);
    const vector<Artista*>& getArtistas() const;

};

#endif //EDITORA_H
