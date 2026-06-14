#ifndef LISTADEREPRODUCAO_H
#define LISTADEREPRODUCAO_H
#include <string>
#include <Musica.h>
#include <vector>
using namespace  std;


class ListaReproducao {
  
  public:
  
    std::string nome;
    int dataCriacao;
    std::string criador;
    vector<Musica*> musicas;
    int duracao;
    //int anoCriacao;
  
    ListaReproducao();

    ListaReproducao(std::string nome , int dataCriacao, std::string criador);

    std::string getNome() const;

    int getDataCriacao() const;

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
