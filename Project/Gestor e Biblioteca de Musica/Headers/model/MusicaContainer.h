#ifndef MUSICACONTAINER_H
#define MUSICACONTAINER_H
#include <vector>
#include <Musica.h>
#include <string>

class MusicaContainer {


    public:

        static std::vector<Musica> musicas;

        MusicaContainer();

        // >>> CORRECAO: ativadas as declaracoes destes metodos de instancia (estavam comentadas)
        // >>> porque o Controller.cpp usa-os, tal como nos restantes containers (Album, Editora, etc.)
        void adicionarMusica(const Musica& musica);
        bool removerMusica(const std::string& nome);
        bool existeMusica(const std::string& nome);
        Musica* procurarMusica(const std::string& nome);
        const std::vector<Musica>& getMusicas() const;

        //static void adicionarMusica();
        //static int removerMusica();
        //static Musica procurarMusica();
        //static void getAll();
        static void reproduzirMusica(std::string n);

  
};

#endif //MUSICACONTAINER_H