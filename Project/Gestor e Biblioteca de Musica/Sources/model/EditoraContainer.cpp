#include "EditoraContainer.h"

using namespace std;

void EditoraContainer::adicionarEditora(const Editora &editora) {
    editoras.push_back(editora);
}

bool EditoraContainer::existeEditora(const string& nome) const{
    for (const auto& e : editoras) {
        if (e.getNome() == nome) return true;
    }
    return false;
}



bool EditoraContainer::removerEditora(const string& nome) {
    for (auto it = editoras.begin(); it != editoras.end(); it++) {
        if (it->getNome() == nome) {
            editoras.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Editora>& EditoraContainer::getEditoras() const {
    return editoras;
}

Editora *EditoraContainer::procurar(const std::string &nome) {
    for (auto&  e : editoras) {
        if (e.getNome() == nome) return &e;
    }
    return nullptr;
}