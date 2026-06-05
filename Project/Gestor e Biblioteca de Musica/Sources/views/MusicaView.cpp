#include "MusicaView.h"
#include <iostream>

/*
Musica MusicaView::obterMusica(std::string nome) {
    nome = Utils::getString(nome); // remove espaços

    if (!Utils::validarUser(nome)) {
        throw std::invalid_argument("Nome inválido: " + nome);
    }

    // procura na lista e retorna a música
    for (Musica m : listarMusicas()) {
        if (m.nome == nome)
            return m;
    }

    throw std::runtime_error("Música não encontrada: " + nome);
}

std::list<Musica> MusicaView::listarMusicas() {
    // retorna a lista de músicas
    std::list<Musica> musicas;

    // aqui adicionarias as músicas da tua fonte de dados
    // ex: base de dados, ficheiro, etc.

    return musicas;
}

std::string MusicaView::detalhesMusica(std::string nome) {
    nome = Utils::getString(nome); // remove espaços

    if (!Utils::validarUser(nome)) {
        throw std::invalid_argument("Nome inválido: " + nome);
    }

    Musica m = obterMusica(nome);

    return "Nome: " + m.nome + "\n"
         //+ "Artista: " + m.getArtista() + "\n"
         + "Duração: " + std::to_string(m.duracao) + "s\n";
}
*/