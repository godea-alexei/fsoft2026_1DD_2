#include "ListaReproducaoContainer.h"
using namespace std;

void ListaReproducaoContainer::adicionarLista(const ListaReproducao &lista) {
    listas.push_back(lista);
}

bool ListaReproducaoContainer::existeLista(const string& nome) const{
    for (const auto& lista : listas) {
        if (lista.getNome() == nome) return true;
    }
    return false;
}

ListaReproducao *ListaReproducaoContainer::procurar(const std::string& nome) {
    for (auto& lista : listas) {
        if (lista.getNome() == nome) return &lista;
    }
    return nullptr;
}

bool ListaReproducaoContainer::removerLista(const string& nome) {
    for (auto it = listas.begin(); it != listas.end(); it++) {
        if (it->getNome() == nome) {
            listas.erase(it);
            return true;
        }
    }
    return false;
}

const vector<ListaReproducao>& ListaReproducaoContainer::getListas() const {
    return listas;
}







