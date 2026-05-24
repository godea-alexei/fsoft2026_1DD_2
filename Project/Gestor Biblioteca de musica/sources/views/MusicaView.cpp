
#include "MusicaView.h"
#include <iostream>

Musica ViewMusicas::obterMusica(std::string nome) {
    nome = Util::getString(nome); // remove espaços

    if (!Util::validarUser(nome)) {
        throw std::invalid_argument("Nome inválido: " + nome);
    }

    // procura na lista e retorna a música
    for (Musica m : listarMusicas()) {
        if (m.getNome() == nome)
            return m;
    }

    throw std::runtime_error("Música não encontrada: " + nome);
}

std::list<Musica> ViewMusicas::listarMusicas() {
    // retorna a lista de músicas
    std::list<Musica> musicas;

    // aqui adicionarias as músicas da tua fonte de dados
    // ex: base de dados, ficheiro, etc.

    return musicas;
}

std::string ViewMusicas::detalhesMusica(std::string nome) {
    nome = Util::getString(nome); // remove espaços

    if (!Util::validarUser(nome)) {
        throw std::invalid_argument("Nome inválido: " + nome);
    }

    Musica m = obterMusica(nome);

    return "Nome: " + m.getNome() + "\n"
         + "Artista: " + m.getArtista() + "\n"
         + "Duração: " + Util::getString(std::to_string(m.getDuracao())) + "s\n";
}