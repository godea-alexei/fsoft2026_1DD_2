#include "Musica.h"
#include <string>
#include <iostream>
#include <windows.h>
//#pragma comment(lib, "winmm.lib")
using namespace std;

Musica::Musica(){}

Musica::Musica(string nom, int dur, int ano, string let, string gen, string cam, string artst, string nomeAlbm){
    this->nome = nom;
    this->duracao = dur;
    this->dataDeLancamento = ano;
    this->letra = let;
    this->genero = gen;
    this->caminho = cam;
    this->nomeArtista = artst;
    this->nomeAlbum = nomeAlbm;

};

Musica::~Musica(){}

string Musica::verLetra(){

    cout << letra << endl;
    return letra;

};

int Musica::getDuracao() const {
    return duracao;
}

string Musica::getNome() const {
    return nome;
}

void Musica::reproduzir(){

    PlaySound(caminho.c_str(), NULL, SND_FILENAME | SND_SYNC);

};


