#include "Musica.h"
#include <string>
#include <iostream>
#include <sstream>



Musica::Musica(){}

Musica::Musica(
    std::string nome,
    int duracao,
    int anoDeLancamento,
    std::string letra,
    std::string genero,
    std::string caminho,
    std::string nomeArtista){

    this->nome = nome;
    this->duracao = duracao;
    this->anoDeLancamento = anoDeLancamento;
    this->letra = letra;
    this->genero = genero;
    this->caminho = caminho;
    this->nomeArtista = nomeArtista;

};

Musica::~Musica(){}

std::string Musica::getLetra() const {

    std::cout << letra << std::endl;
    return letra;

};

int Musica::getDuracao() const {
    return duracao;
}

std::string Musica::getNome() const {
    return nome;
}

void Musica::reproduzir(){
    std::string comando = "start \"\" \"" + caminho + "\"";
    system(comando.c_str());

};

int Musica::getAnoDeLancamento() const {
    return anoDeLancamento;
}

std::string Musica::getCaminho() const {
    return caminho;
}

std::string Musica::getGenero() const {
    return genero;
}

std::string Musica::getNomeArtista() const {
    return nomeArtista;
}








