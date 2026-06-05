#ifndef MUSICACONTAINER_H
#define MUSICACONTAINER_H
#include <list>
#include <string>
#include <Musica.h>
using namespace std;

class MusicaContainer {

    public:
        int adicionarMusica(std::string nome, int duracao, int dataDeLancamento, std::string letra);
        int removerMusica(std::string nome);
        Musica procurarMusica(std::string nome);
        std::list<Musica> getAll();



};


#endif //MUSICACONTAINER_H