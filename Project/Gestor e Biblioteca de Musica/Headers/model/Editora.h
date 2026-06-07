#ifndef EDITORA_H
#define EDITORA_H
#include "Artista.h"

class Editora {

    public:

        std::string nome;
        list<Artista> artistas;

        Editora(std::string nom);
        Editora(std::string nom, list<Artista> &artsts);
        ~Editora();


};

#endif //EDITORA_H
