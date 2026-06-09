#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa{
    public:
        std::string nome;
        int anoNascimento;

        std::string getNome() const;
        int getIdade () const;
        Pessoa();
        Pessoa(std::string nome, int ano);
        ~Pessoa();

};

#endif //PESSOA_H