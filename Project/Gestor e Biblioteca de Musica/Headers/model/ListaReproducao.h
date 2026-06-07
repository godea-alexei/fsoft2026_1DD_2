#ifndef LISTADEREPRODUCAO_H
#define LISTADEREPRODUCAO_H
#include <string>
#include <list>
#include <Musica.h>
using namespace  std;

class ListaReproducao {


    public:
        std::string nome;
        int duracao;
        int anoCriacao;
        list<Musica> musicas;

    ListaReproducao();
    ListaReproducao(std::string nom, int dur, int ano);
    ListaReproducao(std::string nom, int dur, int ano, list<Musica> &mus);
    ~ListaReproducao();

};

#endif //LISTADEREPRODUCAO_H
