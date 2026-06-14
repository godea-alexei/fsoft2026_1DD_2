#ifndef ARTISTACONTAINER_H
#define ARTISTACONTAINER_H
#include <string>
#include <vector>
#include "Artista.h"



class ArtistaContainer {

    public:

        vector<Artista> artistas;

        ArtistaContainer();
        ~ArtistaContainer();

    /*
        void adicionarArtista(string nome, int ano);
        void removerArtista(string nome);
        Artista* procurarArtista(string nome);
        vector<Artista*>& getAll();
    */

        void adicionarArtista(const Artista& artista);
        bool removerArtista(const std::string& nome);
        Artista* procurarArtista(const std::string& nome);
        const std::vector<Artista>& getArtistas() const;
        bool existeArtista(const std::string& nome);

};

#endif
