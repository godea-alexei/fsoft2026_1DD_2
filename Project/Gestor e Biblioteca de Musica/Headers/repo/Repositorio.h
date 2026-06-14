#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#include <Musica.h>
#include <Artistacontainer.h>
#include <Album.h>
#include <ListaReproducao.h>
#include <EditoraContainer.h>
#include <Utilizador.h>
#include "MusicaContainer.h"
#include "AlbumContainer.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;


class Repositorio {

    public:

        static string diretorioJSON;

        std::vector<Musica> carregarMusicas();
        std::vector<Editora> carregarEditoras(ArtistaContainer& artistas);
        std::vector<Artista> carregarArtistas(AlbumContainer& albuns);
        std::vector<Utilizador> carregarUtilizadores();
        std::vector<ListaReproducao> carregarListas(MusicaContainer& musicas);
        std::vector<Album> carregarAlbuns(MusicaContainer& musicas);


        static void guardarMusica(Musica m);
        static void guardarEditora(const Editora& e);
        static void guardarArtista(const Artista& a);
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

        Repositorio();

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H