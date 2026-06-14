#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_BASEVIEW_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_BASEVIEW_H
#include "Artista.h"
#include "ListaReproducao.h"
#include "Album.h"
#include "Musica.h"
#include "Editora.h"



class BaseView {

        public:

                void listarObjeto(Artista artista);
                void listarObjeto(ListaReproducao listaReproducao);
                void listarObjeto(Album album);
                void listarObjeto(Musica musica);
                void listarObjeto(Editora editora);

                void listarAtributos(Artista artista);
                void listarAtributos(ListaReproducao listaReproducao);
                void listarAtributos(Album album);
                void listarAtributos(Musica musica);
                void listarAtributos(Editora editora);

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_BASEVIEW_H