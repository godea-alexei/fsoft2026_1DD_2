#ifndef ALBUMCONTAINER_H
#define ALBUMCONTAINER_H
#include "Album.h"
#include <vector>
#include <string>
#include <iostream>

class AlbumContainer {

        public:

                std::vector<Album> albuns;

                void adicionarAlbum(const Album& album);

                bool removerAlbum(const string& nome);

                bool existeAlbum(const string& nome) const;

                Album* procurarAlbum(const string& nome);

                const std::vector<Album>& getAlbuns() const;
};

#endif //ALBUMCONTAINER_H
