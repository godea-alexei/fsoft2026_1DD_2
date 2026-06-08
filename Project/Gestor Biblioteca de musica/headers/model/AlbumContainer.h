#ifndef ALBUMCONTAINER_H
#define ALBUMCONTAINER_H

#include <string>
#include <list>
#include "Album.h"
using namespace std;

class AlbumContainer {

private:
    list<Album*> albuns;

public:
    AlbumContainer();
    ~AlbumContainer();

    void adicionarAlbum();
    void removerAlbum();
    Album* procurarAlbum(string nome);
    list<Album*>& getAll();
};

#endif
