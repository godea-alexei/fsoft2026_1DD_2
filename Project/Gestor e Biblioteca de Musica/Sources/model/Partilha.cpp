#include "Partilha.h"
#include "Utils.h"
#include "ListaReproducao.h"
#include <iostream>
#include <ctime>
#include "Musica.h"
#include "Utilizador.h"
#include "UtilizadorContainer.h"
#include "MusicaContainer.h"



Partilha::Partilha() {}

void Partilha::partilharMusica(Utilizador* destinatario, std::string mensagem) {

    destinatario->musicasPartilhadas.push_back(mensagem);
}

void Partilha::partilharLista(Utilizador* destinatario, ListaReproducao* original, ListaReproducaoContainer& listas){


    ListaReproducao nova = *original;
    nova.criador = destinatario->getNome();
    listas.adicionarLista(nova);

}