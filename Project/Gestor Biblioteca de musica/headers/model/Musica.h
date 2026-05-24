#ifndef MUSICA_H
#define MUSICA_H

#endif //MUSICA_H

#include <string>

class Musica{

public:
    std::string nome;
    int duracao;
    int dataDeLancamento;
    std::string letra;

    static std::string verLetra();
    static void reproduzir();

}