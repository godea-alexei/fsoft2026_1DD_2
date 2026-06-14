#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_PARTILHA_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_PARTILHA_H
#include "Utilizador.h"
#include "ListaReproducaoContainer.h"



class Partilha {

    public:

        Partilha();

        static void partilharMusica(Utilizador* destinatario, std::string mensagem);

        static void partilharLista(Utilizador* destinatario, ListaReproducao* original, ListaReproducaoContainer& listas);

};



#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_PARTILHA_H



