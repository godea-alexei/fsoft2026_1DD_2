#include "Utilizador.h"

Utilizador::Utilizador(){};

Utilizador::Utilizador(std::string nome, int anoNascimento, std::string palavraPasse) : Pessoa(nome, anoNascimento){
    this->palavraPasse = palavraPasse;
}

Utilizador::~Utilizador(){}

string Utilizador::getPalavraPasse() const {
    return palavraPasse;
}

//verifica se as passes inseridas sao iguais
bool Utilizador::validarPalavraPasse(
    const std::string& pass,
    const std::string& confirmacao) {
    if (pass != confirmacao) return false;

    if (pass.length() < 1) return false;
    else return true;
}