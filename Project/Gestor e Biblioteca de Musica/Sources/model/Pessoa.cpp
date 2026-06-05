#include "Pessoa.h"
#include <string>
#include <ctime>

Pessoa::Pessoa() {

}

Pessoa::Pessoa(std::string nom, int ano) {
    this->nome = nom;
    this->anoNascimento = ano;
}

Pessoa::~Pessoa(){}

std::string Pessoa::getNome(){

    return nome;

}

int Pessoa::getIdade(){

    time_t t = time(0);
    tm* now = localtime(&t);
    int ano = now->tm_year + 1900;
    return ano - anoNascimento;

}

