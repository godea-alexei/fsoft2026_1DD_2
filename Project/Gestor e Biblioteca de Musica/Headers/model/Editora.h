#ifndef EDITORA_H
#define EDITORA_H
#include <vector>

#include "Artista.h"
#include <string>

class Editora {
public:
    std::string nome;
    std::vector<Artista> artistas;

    Editora();
    Editora(std::string nome);

    std::string getNome() const;



};

#endif //EDITORA_H
