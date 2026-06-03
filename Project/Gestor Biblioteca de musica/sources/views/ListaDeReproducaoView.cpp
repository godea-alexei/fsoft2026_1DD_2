#include "ListaDeReproducaoView.h"
#include <iostream>
using namespace std;

ListaDeReproducaoView::ListaDeReproducaoView() {
}

ListaDeReproducaoView::~ListaDeReproducaoView() {
}

// Asks the user for data and returns a new playlist.
ListaDeReproducao ListaDeReproducaoView::obterListaReproducao() {
    string nome;
    int ano;

    cout << "=== Create Playlist ===" << endl;

    cout << "Playlist name: ";
    getline(cin, nome);

    cout << "Creation year: ";
    cin >> ano;
    cin.ignore();

    // Duration starts at 0 because the playlist has no songs yet.
    ListaDeReproducao nova(nome, 0, ano);
    return nova;
}

// Shows all playlists and returns the chosen one.
ListaDeReproducao ListaDeReproducaoView::listarListaReproducao(list<ListaDeReproducao>& listas) {
    cout << "=== Playlists ===" << endl;

    if (listas.size() == 0) {
        cout << "There are no playlists." << endl;
        return ListaDeReproducao();
    }

    int numero = 1;
    for (ListaDeReproducao& l : listas) {
        cout << numero << " - " << l.getNome() << endl;
        numero++;
    }

    int escolha;
    cout << "Choose a playlist (number): ";
    cin >> escolha;
    cin.ignore();

    // Iterates again; returns the playlist that matches the chosen number.
    numero = 1;
    for (ListaDeReproducao& l : listas) {
        if (numero == escolha) {
            return l;
        }
        numero++;
    }

    cout << "Invalid choice." << endl;
    return ListaDeReproducao();
}


Musica ListaDeReproducaoView::abrirLista(list<Musica>& musicas) {
    cout << "=== Playlist Songs ===" << endl;

    if (musicas.size() == 0) {
        cout << "This playlist doesn't have any songs yet." << endl;
        return Musica();
    }

    int numero = 1;
    for (Musica& m : musicas) {
        cout << numero << " - " << m.getNome() << endl;
        numero++;
    }

    int escolha;
    cout << "Choose a song (number): ";
    cin >> escolha;
    cin.ignore();

    numero = 1;
    for (Musica& m : musicas) {
        if (numero == escolha) {
            return m;
        }
        numero++;
    }

    cout << "Invalid choice." << endl;
    return Musica();
}
