#ifndef EDITORA_H
#define EDITORA_H
#include <vector>
#include "Artista.h"
#include <string>

class Editora {
public:

    std::string nome;
    std::vector<Artista*> artistas;
    Editora();
    Editora(std::string nome);
    std::string getNome();

    void adicionarArtista(Artista* artista);
    bool removerArtista(const string& nome);
    bool existeArtista(const string& nome);
    Artista* procurarArtista(const std::string& nome);
    const std::vector<Artista*>& getArtistas() const;

};

#endif //EDITORA_H
