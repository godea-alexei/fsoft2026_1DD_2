#include <Editora.h>
#include <list>
#include <string>
#include <iostream>

using namespace std;

Editora::Editora() {
}

Editora::Editora(string nome) {
    this->nome = nome;
}

string Editora::getNome() const {
    return nome;

}