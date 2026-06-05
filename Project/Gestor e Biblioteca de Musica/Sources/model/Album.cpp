#include <list>
#include <string>
#include <Album.h>

// Construtor padrão — chama o construtor padrão do pai
Album::Album() : ListaReproducao(), artista("") {}

// Construtor sem músicas
Album::Album(std::string nom, int dur, int ano, std::string nomeArtst)
    : ListaReproducao(nom, dur, ano), artista(nomeArtst) {}

// Construtor com lista de músicas
Album::Album(std::string nom, int dur, int ano, std::list<Musica>& mus, std::string nomeArtst)
    : ListaReproducao(nom, dur, ano, mus), artista(nomeArtst) {}

Album::~Album() {}