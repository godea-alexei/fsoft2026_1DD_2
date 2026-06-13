#ifndef MUSICA_H
#define MUSICA_H
#include <string>
using namespace std;

class Musica{
  
  private:
  
      std::string nome;
      int duracao;
      int anoDeLancamento;
      std::string letra;
      std::string genero;
      std::string caminho;
      std::string nomeArtista;

    public:

        string nomeAlbum;

        //string verLetra();
        //string obterNome();
  
        Musica();
        Musica(string nom, int dur, int ano, string let, string gen, string cam, string artst, string nomeAlbm);
        ~Musica();

        std::string verLetra();
        void reproduzir() const;

        int getAnoDeLancamento() const;
        int getDuracao() const;
        std::string getNome() const;
        std::string getLetra() const;
        std::string getGenero() const;
        std::string getCaminho() const;
        std::string getNomeArtista() const;




};

#endif //MUSICA_H