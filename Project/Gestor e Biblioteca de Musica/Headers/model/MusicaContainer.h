#ifndef MUSICACONTAINER_H
#define MUSICACONTAINER_H
#include <list>
#include <string>
#include <Musica.h>
#include <vector>

class MusicaContainer {
private:
    std::vector<Musica> musicas;

public:
    MusicaContainer();
    void adicionarMusica(const Musica& musica);
    bool removerMusica(const std::string& nome);
    bool existeMusica(const std::string& nome);
    Musica* procurarMusica(const std::string& nome);
    const std::vector<Musica>& getMusicas() const;







};


#endif //MUSICACONTAINER_H