#include "ArtistaContainer.h"
#include "BaseView.h"
#include <iostream>
using namespace std;

ArtistaContainer::ArtistaContainer() {
}

ArtistaContainer::~ArtistaContainer() {
    for (Artista* a : artistas) {
        delete a;
    }
    artistas.clear();
}

void ArtistaContainer::adicionarArtista() {
    string nome;
    cout << "Nome do artista: ";
    getline(cin, nome);

    if (procurarArtista(nome) != nullptr) {
        cout << "Ja existe um artista chamado \"" << nome << "\"." << endl;
        return;
    }

    Artista* novo = new Artista(nome);
    artistas.push_back(novo);
    cout << "Artista \"" << nome << "\" adicionado com sucesso." << endl;
}

void ArtistaContainer::removerArtista() {
    string nome;
    cout << "Nome do artista a remover: ";
    getline(cin, nome);

    list<Artista*>::iterator it;
    for (it = artistas.begin(); it != artistas.end(); it++) {
        if ((*it)->getNome() == nome) {
            delete *it;             // liberta a memoria do artista
            artistas.erase(it);     // tira-o da lista
            cout << "Artista \"" << nome << "\" removido." << endl;
            return;
        }
    }
    cout << "Nao existe nenhum artista chamado \"" << nome << "\"." << endl;
}

Artista* ArtistaContainer::procurarArtista(string nome) {
    for (Artista* a : artistas) {
        if (a->getNome() == nome) {
            return a;
        }
    }
    return nullptr;
}

list<Artista*>& ArtistaContainer::getAll() {
    if (artistas.size() == 0) {
        cout << "Nao existem artistas." << endl;
    } else {
        for (Artista* a : artistas) {
            listarAtributos(*a);  
            cout << endl;  
        }
    }
    return artistas;
}
