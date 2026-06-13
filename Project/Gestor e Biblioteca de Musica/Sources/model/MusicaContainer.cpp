#include "MusicaContainer.h"
#include "Musica.h"
#include "../Headers/repo/Repositorio.h"
#include <string>
#include <ctime>
#include <iostream>
#include <list>
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

    Musica m = Musica(nome, dur, ano, letra, genero, caminho, artst, album);

    Repositorio::guardarMusica(m);

};



bool MusicaContainer::removerMusica(const std::string &nome) {
    for (auto it = musicas.begin(); it != musicas.end(); it++) {
        if (it->getNome() == nome) {
            musicas.erase(it);
            return true;
        }
    }
    return false;
}



Musica MusicaContainer::procurarMusica(){

    string nome;
    cout << " Por favor insira: "  << endl;
    cout << "Nome da musica: ";
    getline(std::cin, nome);;

    for(int i = 0; i < musicas.size(); i++){
        if(musicas[i].obterNome() == nome){
              return musicas[i];
        }
    }
    std::cout << "EXCEÇÃO Musica nao encontrada." << std::endl;

    return Musica(); //RETIRAR
};



void MusicaContainer::getAll(){

    for (int i = 0; i < musicas.size(); i++) {

        cout << "Nome: " << musicas[i].nome << endl;
        cout << "\n Duracao em minutos: " << musicas[i].duracao << endl;
        cout << "\n Ano de lancamento: " << musicas[i].dataDeLancamento << endl;
        cout << "\n Letra: " << musicas[i].letra << endl;
        cout << "\n Genero Musical: " << musicas[i].genero << endl;
        cout << "\n Nome do artista: " << musicas[i].nomeArtista << endl;
        cout << "\n Nome do album: " << musicas[i].nomeAlbum << endl;

    }

};



