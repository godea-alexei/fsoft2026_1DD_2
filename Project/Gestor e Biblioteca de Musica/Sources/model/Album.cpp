#include <list>
#include <string>
#include <Album.h>


Album::Album() : ListaReproducao(), artista("") {}


Album::Album(std::string nome, int duracao, int ano, std::string nomeArtista)
    : ListaReproducao(nome, duracao), artista(nomeArtista) {}


Album::Album(std::string nome, int duracao, int ano, std::list<Musica>& mus, std::string nomeArtista)
    : ListaReproducao(nome, duracao), artista(nomeArtista) {}

Album::~Album() {}