#ifndef ALBUM_H
#define ALBUM_H
#include <list>
#include <string>
#include "ListaReproducao.h"
using namespace std;


class Album : public ListaReproducao {


    public:

        string artista;

        Album();
        Album(std::string nome, int duracao, int ano, std::string nomeArtista);
        Album(std::string nome, int duracao, int ano, std::list<Musica>& mus, std::string nomeArtista);
        ~Album();

};

#endif //ALBUM_H
