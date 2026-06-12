#include "../../Headers/views/BaseView.h"
#include "Artista.h"
#include "ListaReproducao.h"
#include "Album.h"
#include "Musica.h"
#include "Editora.h"
#include "iostream"
#include "vector"


void listarObjeto(Artista artista)
{
    std::cout << "Artista: " << artista.nome << std::endl;
}

void listarObjeto(ListaReproducao listaReproducao)
{
    std::cout << "Lista de Reproducao: " << listaReproducao.nome << std::endl;
}

void listarObjeto(Album album)
{
    std::cout << "Album: " << album.nome << std::endl;
}
void listarObjeto(Musica musica)
{
    std::cout << "Musica: " << musica.nome << std::endl;
}

void listarObjeto(Editora editora)
{
    std::cout << "Editora: " << editora.nome << std::endl;
}



void listarAtributos(Artista artista)
{
    std::cout << "Nome: " << artista.nome << std::endl;
    std::cout << "Idade: " << artista.getIdade() << std::endl;
    std::cout << "Albums: " << std::endl;
    if (artista.albums.size() > 0){
        for (const auto& album : artista.albums) {
            std::cout << "Nome do album: " << album.nome  << std::endl;
        }
    }else {
        std::cout << "O artista nao possui albums" << std::endl;
    }
}

void listarAtributos(ListaReproducao listaReproducao)
{
    std::cout << "Nome: " << listaReproducao.nome << std::endl;
    std::cout << "Ano de criacao: " << listaReproducao.anoCriacao << std::endl;
    std::cout << "Duracao: " << listaReproducao.duracao << std::endl;
    std::cout << "Audio: " << std::endl;
    if (listaReproducao.musicas.size() > 0){
        for (const auto& musica : listaReproducao.musicas) {
            std::cout << "Nome da Musica: " << musica.nome  << std::endl;
        }
    }else {
        std::cout << "A lista de reproducao nao possui musicas" << std::endl;
    }
}

void listarAtributos(Album album)
{
    std::cout << "Nome: " << album.nome << std::endl;
    std::cout << "Ano de lancamento: " << album.anoCriacao << std::endl;
    std::cout << "Duracao: " << album.duracao << std::endl;
    std::cout << "Audio: " << std::endl;
    if (album.musicas.size() > 0){
        for (const auto& musica : album.musicas) {
            std::cout << "Nome da Musica: " << musica.nome  << std::endl;
        }
    }else {
        std::cout << "A lista de reproducao nao possui musicas" << std::endl;
    }
}

void listarAtributos(Musica musica)
{
    std::cout << "Nome: " << musica.nome << std::endl;
    std::cout << "Duração: " << musica.duracao << std::endl;
    std::cout << "Data de Lançamento: " << musica.dataDeLancamento << std::endl;
    std::cout << "Letra: " << musica.letra << std::endl;
    std::cout << "Género: " << musica.genero << std::endl;
    std::cout << "Caminho: " << musica.caminho << std::endl;
    std::cout << "Artista: " << musica.nomeArtista << std::endl;
    std::cout << "Álbum: " << musica.nomeAlbum << std::endl;
}

void listarAtributos(Editora editora)
{

    std::cout << "Nome da Editora: " << editora.getNome() << std::endl;
    std::cout << "Lista de Artistas:" << std::endl;
    if (editora.artistas.size() > 0) {
        for (const auto& artista : editora.artistas) {
            std::cout << artista.nome << std::endl;
        }
    } else {
        std::cout << "  Nenhum artista associado a editora" << std::endl;
    }
}

