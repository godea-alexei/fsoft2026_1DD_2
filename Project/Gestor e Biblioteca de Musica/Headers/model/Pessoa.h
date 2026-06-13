#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using namespace std;

class Pessoa{
    public:
        string nome;
        int anoNascimento;

        string getNome() const;
        int getIdade () const;
        int getAnoNascimento() const;
        Pessoa();
        Pessoa(std::string nome, int ano);
        ~Pessoa();

};

#endif //PESSOA_H