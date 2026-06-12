#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
#include <list>
#include "Pessoa.h"
#include "Album.h"
using namespace std;


class Artista : public Pessoa {
private:
    std::vector<Album*> albuns;
public:

    list<Album> albums;

    Artista();
    Artista(std::string nome, int ano);
    Artista(std::string nome, int ano, list<Album> &alb);
    ~Artista();

    std::string getNome() const;
    int getAno();

    void adicionarAlbum(Album* album);
    bool removerAlbum(const std::string& nome);
    bool existeAlbum(const std::string& nome) const;
    Album* procurarAlbum(const std::string& nome);
    const std::vector<Album*>& getAlbuns() const;

};
 
#endif
