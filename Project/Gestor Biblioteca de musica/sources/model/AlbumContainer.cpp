#include "ArtistaContainer.h"
#include <iostream>
using namespace std;

ArtistaContainer::ArtistaContainer() {
}

ArtistaContainer::~ArtistaContainer() {
    for (int i = 0; i < (int)artistas.size(); i++) {
        delete artistas[i];
    }
    artistas.clear();
}

// Creates a new artist and adds it to the vector.
void ArtistaContainer::adicionarArtista(string nome) {
    if (procurarArtista(nome) != nullptr) {
        cout << "An artist named \"" << nome << "\" already exists." << endl;
        return;
    }

    // Creates the artist in memory and stores its address in the vector.
    Artista* novo = new Artista(nome);
    artistas.push_back(novo);
    cout << "Artist \"" << nome << "\" added successfully." << endl;
}

// Searches for an artist by name and removes it from the vector.
void ArtistaContainer::removerArtista(string nome) {
    for (int i = 0; i < (int)artistas.size(); i++) {
        if (artistas[i]->getNome() == nome) {
            delete artistas[i];                    // frees the memory
            artistas.erase(artistas.begin() + i);
            cout << "Artist \"" << nome << "\" removed." << endl;
            return;
        }
    }
    cout << "There is no artist named \"" << nome << "\"." << endl;
}

// Searches for an artist by name.
// Returns the pointer to the artist, or nullptr if it doesn't exist.
Artista* ArtistaContainer::procurarArtista(string nome) {
    for (int i = 0; i < (int)artistas.size(); i++) {
        if (artistas[i]->getNome() == nome) {
            return artistas[i];
        }
    }
    return nullptr;   // none found
}

vector<Artista*>& ArtistaContainer::getAll() {
    return artistas;
}
