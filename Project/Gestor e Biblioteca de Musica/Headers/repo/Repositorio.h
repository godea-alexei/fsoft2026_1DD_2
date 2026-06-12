#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#include <Musica.h>
#include <Artista.h>
#include <Album.h>
#include <ListaReproducao.h>
#include <Editora.h>
#include <Utilizador.h>
#include "MusicaContainer.h"
#include "ListaReproducaoContainer.h"
#include "Artistacontainer.h"
#include "EditoraContainer.h"
#include "AlbumContainer.h"
#include <string.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;



class Repositorio {

    public:

        static string diretorioJSON;

        static void carregarMusicas(MusicaContainer mC);
        static void carregarEditoras(EditoraContainer eC, ArtistaContainer aC);
        static void carregarArtistas(ArtistaContainer aC, AlbumContainer alC);
        static void carregarAlbums(AlbumContainer alC, MusicaContainer mC);
        static void carregarUtilizadores();
        static void carregarListas(ListaReproducaoContainer lC, MusicaContainer mC);
        static void carregarAlbuns(AlbumContainer aC);

        static void carregarTudo(MusicaContainer mC, EditoraContainer eC, ArtistaContainer aC, AlbumContainer alC, ListaReproducaoContainer lC);

        static void guardarMusica(Musica m);
        static void guardarEditora(Editora e);
        static void guardarArtista(Artista a);
        static void guardarAlbum(Album a);
        static void guardarUtilizador(Utilizador u);
        static void guardarLista(ListaReproducao l);

        static void eliminarMusica(string n, MusicaContainer mC);
        static void eliminarEditora(string n, MusicaContainer mC, EditoraContainer eC, ArtistaContainer aC, AlbumContainer alC, ListaReproducaoContainer lC);
        static void eliminarArtista(string n, ArtistaContainer aC, AlbumContainer alC, MusicaContainer mC);
        static void eliminarAlbum(string n, AlbumContainer aC, MusicaContainer mC);
        static void eliminarUtilizador(string n);
        static void eliminarLista(string n, ListaReproducaoContainer lC);


        static json lerFicheiroJSON(string caminho);

        Repositorio();

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H