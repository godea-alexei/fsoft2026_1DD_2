#include "Musica.h"
#include <string>
#include <iostream>
#include "windows.h"
#include <shellapi.h>

using namespace std;

Musica::Musica(){}

Musica::Musica(
    string nome,
    int duracao,
    int anoDeLancamento,
    string letra,
    string genero,
    string caminho,
    string nomeArtista){
    this->nome = nome;
    this->duracao = duracao;
    this->anoDeLancamento = anoDeLancamento;
    this->letra = letra;
    this->genero = genero;
    this->caminho = caminho;
    this->nomeArtista = nomeArtista;
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

void Musica::reproduzir() const
{
    ShellExecute(
        NULL,
        "open",
        caminho.c_str(),
        NULL,
        NULL,
        SW_SHOWNORMAL);
}

int Musica::getAnoDeLancamento() const {
    return anoDeLancamento;
}

string Musica::getCaminho() const {
    return caminho;
}

string Musica::getGenero() const {
    return genero;
}

string Musica::getLetra() const {
    return letra;
}

std::string Musica::getNomeArtista() const {
    return nomeArtista;
}







