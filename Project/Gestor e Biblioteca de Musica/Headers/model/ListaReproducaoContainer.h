#ifndef LISTAREPRODUCAOCONTAINER_H
#define LISTAREPRODUCAOCONTAINER_H

#include <vector>
#include "Headers/model/ListaReproducao.h"

class ListaReproducaoContainer {
private:
    std::vector<ListaReproducao> listas;

public:
    void adicionarLista(const ListaReproducao& lista);

    bool removerLista(const std::string& nome);

    bool existeLista(const std::string& nome) const;

    ListaReproducao* procurar(const std::string& nome);

    const std::vector<ListaReproducao>& getListas() const;
};

#endif //LISTAREPRODUCAOCONTAINER_H
