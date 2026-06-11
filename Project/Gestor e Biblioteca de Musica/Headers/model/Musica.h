#ifndef MUSICA_H
#define MUSICA_H
#include <string>
using namespace std;

class Musica{

    public:

        std::string nome;
        int duracao;
        int dataDeLancamento;
        std::string letra;
        std::string genero;
        std::string caminho;
        string nomeArtista;
        string nomeAlbum;

        std::string verLetra();
        void reproduzir();
        Musica();
        Musica(std::string nom, int dur, int ano, std::string let, std::string gen, std::string cam, string artst, string nomeAlbm);
        ~Musica();

        int getDuracao() const;

        std::string getNome() const;

};

#endif //MUSICA_H