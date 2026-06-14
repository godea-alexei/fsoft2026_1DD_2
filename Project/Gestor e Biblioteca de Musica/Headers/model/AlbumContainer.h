#ifndef ALBUMCONTAINER_H
#define ALBUMCONTAINER_H
#include "Album.h"
#include <vector>

class AlbumContainer {
private:
        std::vector<Album> albuns;

public:
        void adicionarAlbum(const Album& album);

        bool removerAlbum(const string& nome);

        bool existeAlbum(const string& nome) const;

        Album* procurarAlbum(const string& nome);

        const std::vector<Album>& getAlbuns() const;
};

#endif //ALBUMCONTAINER_H