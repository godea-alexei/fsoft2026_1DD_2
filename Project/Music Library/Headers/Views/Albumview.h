#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <string>
#include <list>
#include "Album.h"
#include "Musica.h"
using namespace std;

class AlbumView {

public:
    AlbumView();
    ~AlbumView();

    Album obterAlbum();

    Album listarAlbums(list<Album>& albums);

    Musica abrirAlbum(list<Musica>& musicas);
};

#endif