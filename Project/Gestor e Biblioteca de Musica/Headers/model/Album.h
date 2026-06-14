#ifndef ALBUM_H
#define ALBUM_H
#include <list>
#include <string>
#include "ListaReproducao.h"

using namespace std;


class Album : public ListaReproducao {
private:
    int anoLancamento;

public:
    Album();
    Album(std::string nome, int anoLancamento);

    int getAnoLancamento() const;
};

#endif //ALBUM_H