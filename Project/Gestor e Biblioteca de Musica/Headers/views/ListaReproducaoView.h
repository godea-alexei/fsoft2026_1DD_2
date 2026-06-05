#ifndef LISTAREPRODUCAOVIEW_H
#define LISTAREPRODUCAOVIEW_H

#include <string>
#include <list>
#include "ListaReproducao.h"
#include "Musica.h"
using namespace std;

class ListaReproducaoView {

public:
    ListaReproducaoView();
    ~ListaReproducaoView();

    ListaReproducao obterListaReproducao();

    ListaReproducao listarListaReproducao(list<ListaReproducao>& listas);

    Musica abrirLista(list<Musica>& musicas);
};

#endif