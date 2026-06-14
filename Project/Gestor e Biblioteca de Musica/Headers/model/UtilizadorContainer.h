#ifndef UTILIZADORCONTAINER_H
#define UTILIZADORCONTAINER_H
#include "utilizador.h"
#include <vector>
#include <string>

class UtilizadorContainer {

    public:

        std::vector<Utilizador> utilizadores;

        UtilizadorContainer();

        void adicionarUtilizador(const Utilizador& utilizador);

        bool existeUtilizador(const std::string& nome) const;

        bool autenticar(const std::string& nome, const std::string& palavraPasse) const;

        Utilizador* procurarUtilizador(const std::string& nome);

};

#endif //UTILIZADORCONTAINER_H
