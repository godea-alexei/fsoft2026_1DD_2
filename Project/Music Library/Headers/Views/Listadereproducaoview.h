#ifndef LISTADEREPRODUCAOVIEW_H
#define LISTADEREPRODUCAOVIEW_H

#include <string>
#include <list>
#include "ListaDeReproducao.h"
#include "Musica.h"
using namespace std;

class ListaDeReproducaoView {

public:
    ListaDeReproducaoView();
    ~ListaDeReproducaoView();

    ListaDeReproducao obterListaReproducao();

    ListaDeReproducao listarListaReproducao(list<ListaDeReproducao>& listas);

    Musica abrirLista(list<Musica>& musicas);
};

#endif