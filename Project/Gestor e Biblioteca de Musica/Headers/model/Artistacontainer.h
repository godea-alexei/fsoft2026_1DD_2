#ifndef ARTISTACONTAINER_H
#define ARTISTACONTAINER_H

#include <vector>
#include "Artista.h"

class ArtistaContainer {
private:
    std::vector<Artista> artistas;

public:
    void adicionarArtista(const Artista& artista);

    bool removerArtista(const std::string& nome);

    bool existeArtista(const std::string& nome) const;

    Artista* procurarArtista(const std::string& nome);

    const std::vector<Artista>& getArtistas() const;
};
#endif