#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#include <Musica.h>
#include <Artista.h>
#include <Album.h>
#include <ListaReproducao.h>
#include <Editora.h>
#include <Utilizador.h>
#include <string.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;



class Repositorio {


    public:

        static string diretorioJSON;

        static void carregarMusicas();
        static void carregarEditoras();
        static void carregarArtistas();
        static void carregarAlbums();
        static void carregarUtilizadores();
        static void carregarListas();
        static void carregarAlbuns();

        static void guardarMusica(Musica m);
        static void guardarEditora(Editora e);
        static void guardarArtista(Artista a);
        static void guardarAlbum(Album a);
        static void guardarUtilizador(Utilizador u);
        static void guardarLista(ListaReproducao l);

        static void eliminarMusica(string n);
        static void eliminarEditora(string n);
        static void eliminarArtista(string n);
        static void eliminarAlbum(string n);
        static void eliminarUtilizador(string n);
        static void eliminarLista(string n);

        static json lerFicheiroJSON(string caminho);

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H