#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H
#include <Musica.h>
#include <Artistacontainer.h>
#include <Album.h>
#include <ListaReproducao.h>
#include <EditoraContainer.h>
#include <Utilizador.h>
#include <AlbumContainer.h>
#include <MusicaContainer.h>
#include <string.h>
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
        static void guardarEditora(const std::vector<Editora>& e);
        static void guardarArtista(const std::vector<Artista>& a);
        static void guardarAlbum(const std::vector<Album>& a);
        static void guardarUtilizador(const std::vector<Utilizador>& u);
        static void guardarLista(const std::vector<ListaReproducao>& l);

        static void eliminarMusica(std::string n);
        static void eliminarEditora(std::string n);
        static void eliminarArtista(std::string n);
        static void eliminarAlbum(std::string n);
        static void eliminarUtilizador(std::string n);
        static void eliminarLista(std::string n);

        static json lerFicheiroJSON(string caminho);

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_REPOSITORIO_H