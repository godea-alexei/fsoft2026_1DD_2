#ifndef LISTADEREPRODUCAO_H
#define LISTADEREPRODUCAO_H
#include <string>
#include <list>
#include <Musica.h>
#include <vector>


class ListaReproducao {
protected:
    std::string nome;
    int dataCriacao;
    vector<Musica> musicas;

public:

    ListaReproducao();

    ListaReproducao(std::string nome , int dataCriacao);

    std::string getNome() const;

    int getDataCriacao() const;

    int getDuracao() const;

    void adicionarMusica(const Musica& musica);

    bool removerMusica(const string& titulo);

    const std::vector<Musica>& getMusicas() const;

    ~ListaReproducao();

};

#endif //LISTADEREPRODUCAO_H
