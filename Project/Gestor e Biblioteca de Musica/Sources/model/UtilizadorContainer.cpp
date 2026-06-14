#include "UtilizadorContainer.h"
#include "Utilizador.h"
#include <string>
#include <vector>



UtilizadorContainer::UtilizadorContainer(){}


void UtilizadorContainer::adicionarUtilizador(const Utilizador& utilizador) {
    utilizadores.push_back(utilizador);
}

//verifica se utilizador com nome=nome existe
bool UtilizadorContainer::existeUtilizador(const string& nome) const {
    for (const auto &u : utilizadores) {
        if (u.getNome() == nome) return true;
    }
    return false;
}

//verfica passe e nome
bool UtilizadorContainer::autenticar( const string& nome, const string& palavraPasse) const {

    for (const auto& u : utilizadores) {
        if (u.getNome() == nome && u.getPalavraPasse() == palavraPasse) {
            return true;
        }
    }
    return false;

}

//encontrar ref de utilizador com nome = nome se existir
Utilizador *UtilizadorContainer::procurarUtilizador(const string& nome) {

    for (auto& u : utilizadores) {
        if (u.getNome() == nome) return &u;
    }

    return nullptr;

}


