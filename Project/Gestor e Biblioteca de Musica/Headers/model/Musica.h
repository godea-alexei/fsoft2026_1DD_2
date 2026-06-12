#ifndef MUSICA_H
#define MUSICA_H
#include <string>
using namespace std;

class Musica{

    public:

        string nome;
        int duracao;
        int dataDeLancamento;
        string letra;
        string genero;
        string caminho;
        string nomeArtista;
        string nomeAlbum;

        string verLetra();
        string obterNome();
        Musica();
        Musica(string nom, int dur, int ano, string let, string gen, string cam, string artst, string nomeAlbm);
        ~Musica();
        void reproduzir();

};

#endif //MUSICA_H