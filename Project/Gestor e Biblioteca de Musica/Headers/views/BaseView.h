#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_BASEVIEW_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_BASEVIEW_H
#include "Artista.h"
#include "ListaReproducao.h"
#include "Album.h"
#include "Musica.h"
#include "Editora.h"

class BaseView {


public:

        void listarObjeto(Artista artista); //views Artista
        void listarObjeto(ListaReproducao listaReproducao); //views Lista reprodução
        void listarObjeto(Album album); //views albums
        void listarObjeto(Musica musica); //views Musica
        void listarObjeto(Editora editora); //editora

        void listarAtributos(Artista artista); //views Artista
        void listarAtributos(ListaReproducao listaReproducao); //views Lista reprodução
        void listarAtributos(Album album); //views albums
        void listarAtributos(Musica musica); //views Musica
        void listarAtributos(Editora editora); //editora


};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_BASEVIEW_H