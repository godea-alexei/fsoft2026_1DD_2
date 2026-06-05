#ifndef MUSICAVIEW_H
#define MUSICAVIEW_H
#include <string>
#include <list>
#include "Musica.h"
#include "Utils.h"

class MusicaView {

    public:
        Musica obterMusica(std::string nome);
        std::list<Musica> listarMusicas();
        std::string detalhesMusica(std::string nome);

};

#endif //MUSICAVIEW_H