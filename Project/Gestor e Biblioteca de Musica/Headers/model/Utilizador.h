#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#include "Pessoa.h"
#include <string>

class Utilizador : public Pessoa {
    private:
        std::string palavraPasse;

    public:

    Utilizador(
        std::string nome,
        int anoNascimento,
        std::string palavraPasse);

    Utilizador();

    std::string getPalavraPasse() const;

    static bool validarPalavraPasse(
        const std::string& pass,
        const std::string& confirmacao);
};


#endif //UTILIZADOR_H
