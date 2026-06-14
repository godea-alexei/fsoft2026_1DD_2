#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#include <Musica.h>
#include <Artistacontainer.h>
#include <Album.h>
#include <ListaReproducao.h>
#include <EditoraContainer.h>
#include <Utilizador.h>
#include "MusicaContainer.h"
#include "ListaReproducaoContainer.h"
#include "AlbumContainer.h"
#include <nlohmann/json.hpp>
#include <UtilizadorContainer.h>

using json = nlohmann::json;
using namespace std;



class Repositorio {

    public:

        static string diretorioJSON;

        static void carregarMusicas(MusicaContainer mC);
        static void carregarEditoras(EditoraContainer eC, ArtistaContainer aC);
        static void carregarArtistas(ArtistaContainer aC, AlbumContainer alC);
        static void carregarAlbums(AlbumContainer alC, MusicaContainer mC);
        static void carregarUtilizadores(UtilizadorContainer uC);
        static void carregarListas(ListaReproducaoContainer lC, MusicaContainer mC);
        static void carregarAlbuns(AlbumContainer aC);

        //static void carregarTudo(MusicaContainer mC, EditoraContainer eC, ArtistaContainer aC, AlbumContainer alC, ListaReproducaoContainer lC);

        static void guardarMusica(Musica m);
        static void guardarEditora(const Editora& e);
        static void guardarArtista(const Artista& a);
        static void guardarAlbum(Album a);
        static void guardarUtilizador(Utilizador u);
        static void guardarLista(ListaReproducao l);

        // >>> CORRECAO: adicionados valores por omissao aos parametros-container destes metodos,
        // >>> para que as chamadas do Controller com apenas o nome compilem. Os corpos nao foram
        // >>> alterados: nestes metodos os containers ou estao em codigo ja comentado ou (no caso
        // >>> da editora) ficam vazios por omissao, preservando o comportamento (eliminacao no JSON).
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