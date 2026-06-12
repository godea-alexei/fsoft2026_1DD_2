#ifndef MUSICACONTAINER_H
#define MUSICACONTAINER_H
#include <vector>
#include <Musica.h>
using namespace std;

class MusicaContainer {

    public:

        static std::vector<Musica> musicas;

        static void adicionarMusica();
        static int removerMusica();
        static Musica procurarMusica();
        static void getAll();
        static void reproduzirMusica();

};

#endif //MUSICACONTAINER_H