#include "Pessoa.h"
#include <string>
#include <ctime>



std::string Pessoa::getNome(){

    return nome;

}

int Pessoa::getIdade(){

    time_t t = time(0);
    tm* now = localtime(&t);
    int ano = now->tm_year + 1900;
    return year-anoNascimento;

}

