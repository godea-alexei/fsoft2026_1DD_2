#include "UtilizadorContainer.h"
using namespace std;

UtilizadorContainer::UtilizadorContainer() {

}


void UtilizadorContainer::adicionarUtilizador(const Utilizador& utilizador) {
    utilizadores.push_back(utilizador);
};

bool UtilizadorContainer::existeUtilizador(const string& nome) const {
    for (const auto& u : utilizadores) {
        if (u.getNome() == nome) return true;
    }
    return false;
}

bool UtilizadorContainer::autenticar(
    const string& nome,
    const string& palavraPasse) const {

    for (const auto& u : utilizadores) {
        if (u.getNome() == nome &&
            u.getPalavraPasse() == palavraPasse) {
            return true;
        }
    }
    return false;
}

Utilizador *UtilizadorContainer::procurarUtilizador(const string& nome) {
    for (auto& u : utilizadores) {
        if (u.getNome() == nome) return &u;
    }

    return nullptr;
}


