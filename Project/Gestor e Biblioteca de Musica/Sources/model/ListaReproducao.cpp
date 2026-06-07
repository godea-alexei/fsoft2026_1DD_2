#include <string>
#include <list>
#include <Musica.h>
#include <ListaReproducao.h>
using namespace std;

ListaReproducao::ListaReproducao(){}

ListaReproducao::ListaReproducao(std::string nom, int dur, int ano) {
    this->nome = nom;
    this->duracao = dur;
    this->anoCriacao = ano;
}
ListaReproducao::ListaReproducao(std::string nom, int dur, int ano, list<Musica> &mus) {
    this->nome = nom;
    this->duracao = dur;
    this->anoCriacao = ano;
    musicas = mus;
}

ListaReproducao::~ListaReproducao(){}