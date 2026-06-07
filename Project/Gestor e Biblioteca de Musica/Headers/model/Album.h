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
        Album(std::string nom, int dur, int ano, std::string nomeArtst);
        Album(std::string nom, int dur, int ano, std::list<Musica>& mus, std::string nomeArtst);
        ~Album();

};

#endif //ALBUM_H
