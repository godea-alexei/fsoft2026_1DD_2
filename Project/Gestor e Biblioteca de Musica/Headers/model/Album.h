#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "ListaReproducao.h"

class Album : public ListaReproducao {

    private:
        int anoLancamento;

    public:

            Album();
            Album(std::string nome, int anoLancamento);
            int getAnoLancamento() const;

};

#endif //ALBUM_H
