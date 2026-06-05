#include "AlbumView.h"
#include <iostream>
using namespace std;



AlbumView::AlbumView() {
}

AlbumView::~AlbumView() {
}
/*
Album AlbumView::obterAlbum() {
    string nome;
    int duracao;
    int ano;

    cout << "=== Add Album ===" << endl;

    cout << "Album name: ";
    getline(cin, nome);

    cout << "Duration (in seconds): ";
    cin >> duracao;

    cout << "Release year: ";
    cin >> ano;
    cin.ignore();   // clears the Enter left in the buffer after cin >>

    //Album novo(nome, duracao, ano);
    //return novo;
}

// Shows the numbered list of albums and returns the chosen album.
Album AlbumView::listarAlbums(list<Album>& albums) {
    cout << "=== Album List ===" << endl;

    // If there are no albums, there is nothing to choose.
    if (albums.size() == 0) {
        cout << "There are no albums to show." << endl;
        return Album();   // returns an empty album
    }

    int numero = 1;
    for (Album& a : albums) {
        cout << numero << " - " << a.nome
             << " (" << a.dataLancamento << ")" << endl;
        numero++;
    }

    int escolha;
    cout << "Choose an album (number): ";
    cin >> escolha;
    cin.ignore();

    numero = 1;
    for (Album& a : albums) {
        if (numero == escolha) {
            return a;
        }
        numero++;
    }
    cout << "Invalid choice." << endl;
    return Album();
}

// Shows the songs of an album and returns the chosen song.
Musica AlbumView::abrirAlbum(list<Musica>& musicas) {
    cout << "=== Album Songs ===" << endl;

    if (musicas.size() == 0) {
        cout << "This album doesn't have any songs yet." << endl;
        return Musica();
    }

    // Shows each song numbered.
    int numero = 1;
    for (Musica& m : musicas) {
        cout << numero << " - " << m.nome << endl;
        numero++;
    }

    int escolha;
    cout << "Choose a song (number): ";
    cin >> escolha;
    cin.ignore();

    // Finds the song that matches the chosen number.
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

*/