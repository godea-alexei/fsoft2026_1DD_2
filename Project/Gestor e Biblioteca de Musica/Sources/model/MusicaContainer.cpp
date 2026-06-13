#include "MusicaContainer.h"
#include <string>
#include <ctime>

using namespace std;

MusicaContainer::MusicaContainer() {

}

void MusicaContainer::adicionarMusica(const Musica &musica) {
    musicas.push_back(musica);
}

Musica *MusicaContainer::procurarMusica(const std::string &nome) {
    for (Musica& m : musicas) {
        if (m.getNome() == nome) {
            return &m;
        }
    }
    return nullptr;
}

bool MusicaContainer::existeMusica(const std::string &nome) {
    for (const auto& musica : musicas) {
        if (musica.getNome() == nome) {
            return true;
        }
    }
    return false;
}

bool MusicaContainer::removerMusica(const std::string &nome) {
    for (auto it = musicas.begin(); it != musicas.end(); it++) {
        if (it->getNome() == nome) {
            musicas.erase(it);
            return true;
        }
    }
    return false;
}

const vector<Musica> &MusicaContainer::getMusicas() const {
    return musicas;
}



/*



int adicionarMusica(std::string nome, int duracao, int dataDeLancamento, std::string letra){

    Musica musica = Musica(nome, duracao, dataDeLancamento);
    if(musica.namo.empty() || musica.duracao == 0 || p.dataDeLancamento == 0){

        return 0;
        //add to persistence

    }else{
       std::cout << "Não pode haver compos vazios." << std::endl;
       return 1;
    }

};

//listaMusica  adicionar paaaaaa
int removerMusica(std::string nome){

    for(int i = 0; i < listaMusica.size(); i++){
        if(listaMusica[i].getNome() == nome){
            listaMusica.remove(listaMusica[i]);
            //remover da persistencia
            return 1;
        }
    }

    std::cout << "Musica nao encontrada." << std::endl;
    return 0;

};


//listaMusica  adicionar paaaaaa
Musica procurarMusica(std::string nome){

    for(int i = 0; i < listaMusica.size(); i++){
        if(listaMusica[i].getNome() == nome){
              return listaMusica[i];
        }
    }
    //throw exception

};



std::list<Musica> getAll(){

    return listaMusica;

};




*/