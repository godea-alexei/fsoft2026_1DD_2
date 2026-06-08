#include "EditoraContainer.h"
#include "BaseView.h"
#include <iostream>
using namespace std;

EditoraContainer::EditoraContainer() {
}

EditoraContainer::~EditoraContainer() {
    for (Editora* e : editoras) {
        delete e;
    }
    editoras.clear();
}

void EditoraContainer::adicionarEditora() {
    string nome;
    cout << "Nome da editora: ";
    getline(cin, nome);

    if (procurarEditora(nome) != nullptr) {
        cout << "Ja existe uma editora chamada \"" << nome << "\"." << endl;
        return;
    }

    Editora* nova = new Editora(nome);
    editoras.push_back(nova);
    cout << "Editora \"" << nome << "\" adicionada com sucesso." << endl;
}

void EditoraContainer::removerEditora() {
    string nome;
    cout << "Nome da editora a remover: ";
    getline(cin, nome);

    list<Editora*>::iterator it;
    for (it = editoras.begin(); it != editoras.end(); it++) {
        if ((*it)->getNome() == nome) {
            delete *it;
            editoras.erase(it);
            cout << "Editora \"" << nome << "\" removida." << endl;
            return;
        }
    }
    cout << "Nao existe nenhuma editora chamada \"" << nome << "\"." << endl;
}

Editora* EditoraContainer::procurarEditora(string nome) {
    for (Editora* e : editoras) {
        if (e->getNome() == nome) {
            return e;
        }
    }
    return nullptr;
}

list<Editora*>& EditoraContainer::getAll() {
    if (editoras.size() == 0) {
        cout << "Nao existem editoras." << endl;
    } else {
        for (Editora* e : editoras) {
            listarAtributos(*e);
            cout << endl;
        }
    }
    return editoras;
}
