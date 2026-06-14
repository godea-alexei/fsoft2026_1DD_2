#ifndef UTILIZADORCONTAINER_H
#define UTILIZADORCONTAINER_H

#include "utilizador.h"
#include <vector>

class UtilizadorContainer {
private:
    std::vector<Utilizador> utilizadores;

public:
    UtilizadorContainer();

    void adicionarUtilizador(const Utilizador& utilizador);

    bool existeUtilizador(const std::string& nome) const;

    bool autenticar(
        const std::string& nome,
        const std::string& palavraPasse) const;

    Utilizador* procurarUtilizador(
        const std::string& nome);

    const std::vector<Utilizador>& getUtilizadores() const;
};



#endif //UTILIZADORCONTAINER_H
