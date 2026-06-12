#include "MusicaContainer.h"
#include "Musica.h"
#include "../Headers/repo/Repositorio.h"
#include <string>
#include <ctime>
#include <iostream>
#include <list>
using namespace std;

std::vector<Musica> MusicaContainer::musicas;

void MusicaContainer::adicionarMusica(){

    string nome;
    int dur;
    int ano;
    string letra;
    string genero;
    string caminho;
    string artst;
    string album;

    cout << " Por favor insira: "  << endl;
    cout << "Nome: ";
    getline(std::cin, nome);;
    cout << "\n Duracao em minutos: ";
    cin >> dur;
    cout << "\n Ano de lancamento: ";
    cin >> ano;
    cout << "\n Letra: ";
    getline(std::cin, letra);
    cout << "\n Genero Musical: ";
    getline(std::cin, genero);
    cout << "\n Caminho absoluto do ficheiro audio: ";
    getline(std::cin, caminho);
    cout << "\n Nome do artista: ";
    getline(std::cin, artst);
    cout << "\n Nome do album: ";
    getline(std::cin, album);

    if(dur == 0 || ano == 0){
        cout << "\n exceção dados fora dos limites ";
    }

    Musica m = Musica(nome, dur, ano, letra, genero, caminho, artst, album);

    Repositorio::guardarMusica(m);

};



int MusicaContainer::removerMusica(){
/*
    string nome;
    cout << " Por favor insira: "  << endl;
    cout << "Nome da musica a remover: ";
    getline(std::cin, nome);

    for(int i = 0; i < musicas.size(); i++){
        if(musicas[i].obterNome() == nome){
            Repositorio::eliminarMusica(nome, *this);
            return 1;
        }
    }
    std::cout << "EXCEÇÃO Musica nao encontrada." << std::endl;
    return 0;
*/
    return 0;
};



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


void MusicaContainer::reproduzirMusica(){

    string n;
    cout << " Por favor insira: "  << endl;
    cout << "Nome da musica a reproduzir: " << endl;
    getline(std::cin, n);

    for (int i = 0; i < musicas.size(); i++) {
        if (musicas[i].nome == n) {
            musicas[i].reproduzir();
        }
    }

};



