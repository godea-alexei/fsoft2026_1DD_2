#include "Utilizador.h"
using namespace std;

Utilizador::Utilizador(){};

Utilizador::Utilizador(
    string nome,
    int anoNascimento,
    string palavraPasse)
    :Pessoa(nome, anoNascimento)
{
    this->palavraPasse = palavraPasse;
}

string Utilizador::getPalavraPasse() const {
    return palavraPasse;
}

bool Utilizador::validarPalavraPasse(
    const string& pass,
    const string& confirmacao) {
    if (pass != confirmacao) return false;

    if (pass.length() < 1) return false;
    else return true;
}

