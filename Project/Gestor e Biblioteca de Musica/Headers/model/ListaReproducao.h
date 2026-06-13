#ifndef LISTADEREPRODUCAO_H
#define LISTADEREPRODUCAO_H
#include <string>
#include <list>
#include <Musica.h>
#include <vector>
#include <Utilizador.h>
using namespace  std;


class ListaReproducao {
  
  public:
  
    std::string nome;
    std::string criador;
    vector<Musica*> musicas;
    int duracao;
    //int anoCriacao;
  
    ListaReproducao();

    ListaReproducao(std::string nome , std::string criador);

    std::string getNome() const;

    int getDuracao() const;

    void adicionarMusica(Musica* musica);

    Musica* procurarMusica(const std::string& titulo);

    bool existeMusica(const std::string& titulo) const;

    bool removerMusica(const string& titulo);

    const std::vector<Musica*>& getMusicas() const;

    ~ListaReproducao();

    std::string getCriador() const;

};

#endif //LISTADEREPRODUCAO_H
