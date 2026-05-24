
#ifndef VIEWMUSICA_H
#define VIEWMUSICA_H

#endif //VIEWMUSICA_H


#pragma once
#include <string>
#include <list>
#include "Musica.h"
#include "Util.h"

class ViewMusicas {

    public:
        Musica obterMusica(std::string nome);
        std::list<Musica> listarMusicas();
        std::string detalhesMusica(std::string nome);

};