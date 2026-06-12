#ifndef MUSICACONTAINER_H
#define MUSICACONTAINER_H
#include <vector>
#include <Musica.h>
#include <vector>

class MusicaContainer {
private:
    //std::vector<Musica> musicas;

public:
    
    static std::vector<Musica> musicas;
  
    MusicaContainer();
  
    // void adicionarMusica(const Musica& musica);
    // bool removerMusica(const std::string& nome);
    bool existeMusica(const std::string& nome);
    // Musica* procurarMusica(const std::string& nome);
    // const std::vector<Musica>& getMusicas() const;

    static void adicionarMusica();
    static int removerMusica();
    static Musica procurarMusica();
    static void getAll();
    static void reproduzirMusica();

  
};

#endif //MUSICACONTAINER_H