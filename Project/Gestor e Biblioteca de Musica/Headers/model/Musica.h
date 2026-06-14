#ifndef MUSICA_H
#define MUSICA_H
#include <string>



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


        Musica();
        Musica(std::string nom, int dur, int ano, std::string let, std::string gen, std::string cam, std::string artst);
        ~Musica();

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