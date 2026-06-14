#include "Partilha.h"
#include "Utils.h"
#include "ListaReproducao.h"
#include "Utilizador.h"
#include "UtilizadorContainer.h"
#include "../repo/Repositorio.h"
#include <ctime>


Partilha::Partilha() {}

void Partilha::partilharMusica(Utilizador* destinatario, std::string mensagem) {

    destinatario->musicasPartilhadas.push_back(mensagem);

}

void Partilha::partilharLista(Utilizador* destinatario, ListaReproducao* original, ListaReproducaoContainer& listas){

    time_t t = time(0);
    tm* now = localtime(&t);
    int ano = now->tm_year + 1900;

    int minuto = now->tm_min;
    int hora = now->tm_hour;
    int segundo = now->tm_sec;

    ListaReproducao nova = ListaReproducao(original->getNome()+"_"+std::to_string(hora)+":"+std::to_string(minuto)+":"+std::to_string(segundo), ano, destinatario->getNome()); // >>> CORRECAO (logica): o ultimo campo do timestamp repetia 'hora'; passa a usar 'segundo' (que estava calculado mas nao era usado)
    for (auto& m : original->getMusicas()) {
        nova.adicionarMusica(m);
    }
    listas.adicionarLista(nova);
    Repositorio::guardarLista(nova);

}