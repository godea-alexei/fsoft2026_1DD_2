#include "AlbumContainer.h"
#include "BaseView.h"
#include <iostream>
using namespace std;

AlbumContainer::AlbumContainer() {
}

AlbumContainer::~AlbumContainer() {
    for (Album* a : albuns) {
        delete a;
    }
    albuns.clear();
}

void AlbumContainer::adicionarAlbum() {
    string nome;
    cout << "Nome do album: ";
    getline(cin, nome);

    if (procurarAlbum(nome) != nullptr) {
        cout << "Ja existe um album chamado \"" << nome << "\"." << endl;
        return;
    }

    int duracao;
    int dataDeLancamento;
    cout << "Duracao (em segundos): ";
    cin >> duracao;
    cout << "Ano de lancamento: ";
    cin >> dataDeLancamento;
    cin.ignore();  // limpa o Enter depois do cin >>

    Album* novo = new Album(nome, duracao, dataDeLancamento);
    albuns.push_back(novo);
    cout << "Album \"" << nome << "\" adicionado com sucesso." << endl;
}

void AlbumContainer::removerAlbum() {
    string nome;
    cout << "Nome do album a remover: ";
    getline(cin, nome);

    list<Album*>::iterator it;
    for (it = albuns.begin(); it != albuns.end(); it++) {
        if ((*it)->getNome() == nome) {
            delete *it;
            albuns.erase(it);
            cout << "Album \"" << nome << "\" removido." << endl;
            return;
        }
    }
    cout << "Nao existe nenhum album chamado \"" << nome << "\"." << endl;
}

Album* AlbumContainer::procurarAlbum(string nome) {
    for (Album* a : albuns) {
        if (a->getNome() == nome) {
            return a;
        }
    }
    return nullptr;
}

list<Album*>& AlbumContainer::getAll() {
    if (albuns.size() == 0) {
        cout << "Nao existem albuns." << endl;
    } else {
        for (Album* a : albuns) {
            listarAtributos(*a);
            cout << endl;
        }
    }
    return albuns;
}
