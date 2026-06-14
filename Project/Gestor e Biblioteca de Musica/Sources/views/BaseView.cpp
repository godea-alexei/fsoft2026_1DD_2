#include "../../Headers/views/BaseView.h"
#include "Artista.h"
#include "ListaReproducao.h"
#include "Album.h"
#include "Musica.h"
#include "Editora.h"
#include "iostream"
#include "vector"



void BaseView::listarObjeto(Artista artista)
{
    std::cout << "Artista: " << artista.nome << std::endl;
}

void BaseView::listarObjeto(ListaReproducao listaReproducao)
{
    std::cout << "Lista de Reproducao: " << listaReproducao.getNome() << std::endl;
}

void BaseView::listarObjeto(Album album)
{
    std::cout << "Album: " << album.getNome() << std::endl;
}
void BaseView::listarObjeto(Musica musica)
{
    std::cout << "Musica: " << musica.getNome() << std::endl;
}

void BaseView::listarObjeto(Editora editora)
{
    std::cout << "Editora: " << editora.nome << std::endl;
}







void BaseView::listarAtributos(Artista artista)
{
    std::cout << "Nome: " << artista.nome << std::endl;
    std::cout << "Idade: " << artista.getIdade() << std::endl;
    std::cout << "Albums: " << std::endl;
    if (artista.albums.size() > 0){
        for (const auto& album : artista.albums) {
            std::cout << "Nome do album: " << album.getNome()  << std::endl;
        }
    }else {
        std::cout << "O artista nao possui albums" << std::endl;
    }
}

void BaseView::listarAtributos(ListaReproducao listaReproducao)
{
    std::cout << "Nome: " << listaReproducao.getNome() << std::endl;
    std::cout << "Ano de criacao: " << listaReproducao.getDataCriacao() << std::endl;
    std::cout << "Duracao: " << listaReproducao.getDuracao() << std::endl;
    std::cout << "Audio: " << std::endl;
    if (listaReproducao.getMusicas().size() > 0){
        for (const auto& musica : listaReproducao.getMusicas()) {
            std::cout << "Nome da Musica: " << musica->getNome()  << std::endl;
        }
    }else {
        std::cout << "A lista de reproducao nao possui musicas" << std::endl;
    }
}

void BaseView::listarAtributos(Album album)
{
    std::cout << "Nome: " << album.getNome() << std::endl;
    std::cout << "Ano de lancamento: " << album.getDataCriacao() << std::endl;
    std::cout << "Duracao: " << album.getDuracao() << std::endl;
    std::cout << "Audio: " << std::endl;
    if (album.getMusicas().size() > 0){
        for (const auto& musica : album.getMusicas()) {
            std::cout << "Nome da Musica: " << musica->getNome()  << std::endl;
        }
    }else {
        std::cout << "Album nao possui musicas" << std::endl;
    }
}

void BaseView::listarAtributos(Musica musica)
{
    std::cout << "Nome: " << musica.getNome() << std::endl;
    std::cout << "Duração: " << musica.getDuracao() << std::endl;
    std::cout << "Ano de Lançamento: " << musica.getAnoDeLancamento() << std::endl;
    std::cout << "Letra: " << musica.getLetra() << std::endl;
    std::cout << "Género: " << musica.getGenero() << std::endl;
    std::cout << "Caminho: " << musica.getCaminho() << std::endl;
    std::cout << "Artista: " << musica.getNomeArtista() << std::endl;
}

void BaseView::listarAtributos(Editora editora)
{

    std::cout << "Nome da Editora: " << editora.getNome() << std::endl;
    std::cout << "Lista de Artistas:" << std::endl;
    if (editora.artistas.size() > 0) {
        for (const auto& artista : editora.artistas) {
            std::cout << artista->getNome() << std::endl;
        }
    } else {
        std::cout << "  Nenhum artista associado a editora" << std::endl;
    }
}