#include <list>
#include <string>
#include <Album.h>
using namespace std;

Album::Album(string nome, int anoLancamento) : ListaReproducao(nome, "") {
    this->anoLancamento = anoLancamento;
}

int Album::getAnoLancamento() const {
    return anoLancamento;
}



