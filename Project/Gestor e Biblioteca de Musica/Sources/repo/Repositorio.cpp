#include "../../Headers/repo/Repositorio.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdio>
#include <fstream>
#include "Controller.h"
#include "MusicaContainer.h"
#include <nlohmann/json.hpp>
#include "Artista.h"
using json = nlohmann::json;
using namespace std;



string Repositorio::diretorioJSON = "../Dados/";


Repositorio::Repositorio(){}

json Repositorio::lerFicheiroJSON(string caminho) {

    json jsonArr = json::array();

    // --- 1. READ EXISTING DATA ---
    ifstream inFile(caminho);

    if (inFile.is_open()) {
        string fileContent;
        // Read the entire file into a string
        fileContent.assign((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();

        // Only parse if the file actually has text inside it
        if (!fileContent.empty()) {
            try {
                jsonArr = json::parse(fileContent);
                if (!jsonArr.is_array()) {
                    jsonArr = json::array();
                }
            } catch (const json::parse_error& e) {
                jsonArr = json::array(); // Reset if file was corrupted text
            }
        }
    }

    return jsonArr;

}



void Repositorio::guardarMusica(Musica m) {

    string caminho = diretorioJSON + "Musicas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    // --- 2. CREATE THE NEW SONG OBJECT ---
    json j;
    j["nome"]             = m.nome;
    j["duracao"]          = m.duracao;
    j["dataDeLancamento"] = m.dataDeLancamento;
    j["letra"]            = m.letra;
    j["genero"]           = m.genero;
    j["caminho"]          = m.caminho;
    j["nomeArtista"]      = m.nomeArtista;
    j["nomeAlbum"]        = m.nomeAlbum;

    // --- 3. ADD TO ARRAY ---
    jsonArray.push_back(j);

    // --- 4. SAVE BACK TO FILE ---
    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    //Copiar ficheiro audio
    std::ifstream src(m.caminho, std::ios::binary);
    std::ofstream dst(diretorioJSON + "Audio/" + m.nome + ".mp3", std::ios::binary);
    dst << src.rdbuf();

}

void Repositorio::guardarEditora(Editora e) {

    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    // --- 2. CREATE THE NEW OBJECT ---
    json j;
    j["nome"]= e.nome;

    // --- 3. CREATE AN ARRAY FOR THE ARTISTS ---
    json jsonArrayArtista = json::array();
    for (const auto& artista : e.artistas) {
        json jArtista;
        jArtista["nome"] = artista.nome;
        jsonArrayArtista.push_back(jArtista);
    }

    j["artistas"] = jsonArrayArtista;

    // --- 3. ADD TO ARRAY ---
    jsonArray.push_back(j);

    // --- 4. SAVE BACK TO FILE ---
    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }


}

void Repositorio::guardarArtista(Artista a) {

    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    // --- 2. CREATE THE NEW SONG OBJECT ---
    json j;
    j["nome"]             = a.nome;
    j["anoNascimento"]    = a.anoNascimento;

    json jsonArrayAlbuns = json::array();
    for (Album album : a.albums){

        json jasonAlbum = json::array();
        jasonAlbum["nomeAlbum"] = album.nome;
        //jasonAlbum["duracao"] = album.duracao;
        //jasonAlbum["anoCriacao"] = album.anoCriacao;
        //jasonAlbum["nomeArtista"] = a.nome;
        jsonArrayAlbuns.push_back(jasonAlbum);

    }
    j["albuns"] = jsonArrayAlbuns;

    // --- 3. ADD TO ARRAY ---
    jsonArray.push_back(j);

    // --- 4. SAVE BACK TO FILE ---
    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }


}

void Repositorio::guardarAlbum(Album a) {

    string caminho = diretorioJSON + "Albums.json";
    json jsonArray = lerFicheiroJSON(caminho);

    json j;
    j["nomeAlbum"] = a.nome;
    j["duracao"] = a.duracao;
    j["anoCriacao"] = a.anoCriacao;
    j["nomeArtista"] = a.artista;

    json jsonArrayMusicas = json::array();
    for (Musica m : a.musicas){
        json jsonMusica = json::array();
        jsonMusica["nome"]             = m.nome;
        //jasonMusica["duracao"]          = m.duracao;
        //jasonMusica["dataDeLancamento"] = m.dataDeLancamento;
        //jasonMusica["letra"]            = m.letra;
        //jasonMusica["genero"]           = m.genero;
        //jasonMusica["caminho"]          = m.caminho;
        //jasonMusica["nomeArtista"]      = m.nomeArtista;
        //jasonMusica["nomeAlbum"]        = m.nomeAlbum;
        jsonArrayMusicas.push_back(jsonMusica);
    }

    j["musicas"] = jsonArrayMusicas;

    jsonArray.push_back(j);

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

}

void Repositorio::guardarUtilizador(Utilizador u) {



}

void Repositorio::guardarLista(ListaReproducao l) {

    string caminho = diretorioJSON + "Listas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    json j;
    j["nomeAlbum"] = l.nome;
    j["duracao"] = l.duracao;
    j["anoCriacao"] = l.anoCriacao;

    json jsonArrayMusicas = json::array();
    for (Musica m : l.musicas){
        json jsonMusica = json::array();
        jsonMusica["nome"]             = m.nome;
        //jasonMusica["duracao"]          = m.duracao;
        //jasonMusica["dataDeLancamento"] = m.dataDeLancamento;
        //jasonMusica["letra"]            = m.letra;
        //jasonMusica["genero"]           = m.genero;
        //jasonMusica["caminho"]          = m.caminho;
        //jasonMusica["nomeArtista"]      = m.nomeArtista;
        //jasonMusica["nomeAlbum"]        = m.nomeAlbum;
        jsonArrayMusicas.push_back(jsonMusica);
    }
    j["musicas"] = jsonArrayMusicas;

    jsonArray.push_back(j);

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

}



void Repositorio::eliminarMusica(string n, MusicaContainer mC) {

    string caminho = diretorioJSON + "Musicas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
        }
    }

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    /*
    std::vector<Musica> m;
    for (int i = 0; i < mC.musicas.size(); i++){
        if (mC.musicas[i].nome != n) {
            m.push_back(mC.musicas[i]);
        }
    }
    mC.musicas = m;
    */

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarEditora(string n, MusicaContainer mC, EditoraContainer eC, ArtistaContainer aC, AlbumContainer alC, ListaReproducaoContainer lC) {

    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
        }
    }

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    for (int i = 0; i < eC.editoras.size(); i++) {
        if (eC.editoras[i].nome == n) {
            for (int j = 0; j < eC.editoras[i].artistas.size(); j++) {
                eliminarArtista(eC.editoras[i].artistas[j].nome, aC, alC, mC);
            }
        }
    }

    /*
    std::vector<Editora> e;
    for (int i = 0; i < eC.editoras.size(); i++){
        if (eC.editoras[i].nome != n) {
            e.push_back(eC.editoras[i]);
        }
    }
    eC.editoras = e;
    */

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarArtista(string n, ArtistaContainer aC, AlbumContainer alC, MusicaContainer mC) {

    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
        }
    }

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    for (int i = 0; i < aC.artistas.size(); i++) {
        if ((*aC.artistas[i]).nome == n) {
            for (int j = 0; j < (*aC.artistas[i]).albums.size(); j++) {
                eliminarAlbum((*aC.artistas[i]).albums[j].nome, alC, mC);
            }
        }
    }

    /*
    std::vector<Artista*> a;
    for (int i = 0; i < aC.artistas.size(); i++){
        if ((*aC.artistas[i]).nome != n) {
            a.push_back(aC.artistas[i]);
        }
    }
    aC.artistas = a; */

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarAlbum(string n, AlbumContainer aC, MusicaContainer mC) {

    string caminho = diretorioJSON + "Albums.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
        }
    }

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    /*
    for (int i = 0; i < aC.albuns.size(); i++) {
        if (aC.albuns[i].nome == n) {
            for (int j = 0; j < aC.albuns[i].musicas.size(); j++) {
                eliminarMusica(aC.albuns[i].musicas[j].nome, mC);
            }
        }
    }
    */

    /*
    std::vector<Album> a;
    for (int i = 0; i < aC.musicas.size(); i++){
        if (aC.albuns[i].nome != n) {
            a.push_back(aC.albuns[i]);
        }
    }
    aC.albuns = a;
    */

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarUtilizador(string n) {

    /*
    string caminho = diretorioJSON + "utilizadores.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
        }
    }

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    cout << "Elemento eliminado com sucesso";
    */
}

void Repositorio::eliminarLista(string n, ListaReproducaoContainer lC) {

    string caminho = diretorioJSON + "Listas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
        }
    }

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

    /*
    std::vector<ListaReproducao> r;
    for (int i = 0; i < lC.listas.size(); i++){
        if (lC.listas[i].nome != n) {
            r.push_back(lC.listas[i]);
        }
    }
    lC.listas = r;
    */

    cout << "Elemento eliminado com sucesso";

}



void Repositorio::carregarMusicas(MusicaContainer mC) {

    /* */
    string caminho = diretorioJSON + "Musicas.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        Musica m;
        m.nome = j["nome"];
        m.duracao = j["duracao"];
        m.dataDeLancamento = j["dataDeLancamento"];
        m.letra = j["letra"];
        m.genero = j["genero"];
        m.caminho = j["caminho"];
        m.nomeArtista = j["nomeArtista"];
        m.nomeAlbum = j["nomeAlbum"];

        mC.musicas.push_back(m);

        //std::cout << mC.musicas.size() << std::endl;
        //std::cout << mC.musicas.back().nome << std::endl;

    }

}

void Repositorio::carregarEditoras(EditoraContainer eC, ArtistaContainer aC) {

    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        Editora e = Editora(j["nome"]);

        for (json j2 : j["artistas"]) {
            for (Artista* artista : aC.artistas) {
                if ((*artista).nome == j2["nome"]) {
                    e.artistas.push_back(*artista);
                }
            }
        }

        eC.editoras.push_back(e);

    }

}

void Repositorio::carregarArtistas(ArtistaContainer aC, AlbumContainer alC) {
/*
    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {


        Artista a = Artista(j["nome"], j["anoNascimento"]);

        for (json j2 : j["albuns"]) {
            for (Album* album : alC.albums) {
                if ((*album).nome == j2["nome"]) {
                    a.albums.push_back(*album);
                }
            }
        }

        aC.artistas.push_back(&a);

    }
*/
}

void Repositorio::carregarAlbums(AlbumContainer aC, MusicaContainer mC) {

    string caminho = diretorioJSON + "Albums.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        Album a = Album(j["nomeAlbum"], j["duracao"], j["anoCriacao"], j["nomeArtista"]);

        for (json j2 : j["musicas"]) {
            for (Musica musica : mC.musicas) {
                if (musica.nome == j2["nome"]) {
                    a.musicas.push_back(musica);
                }
            }
        }

        //aC.albums.push_back(a);

    }

}

void Repositorio::carregarUtilizadores(){}

void Repositorio::carregarListas(ListaReproducaoContainer lC, MusicaContainer mC) {

    string caminho = diretorioJSON + "Listas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        ListaReproducao a = ListaReproducao(j["nomeAlbum"], j["duracao"], j["anoCriacao"]);

        for (json j2 : j["musicas"]) {
            for (Musica musica : mC.musicas) {
                if (musica.nome == j2["nome"]) {
                    a.musicas.push_back(musica);
                }
            }
        }

        //aC.albums.push_back(a);

    }




}




void Repositorio::carregarTudo(MusicaContainer mC, EditoraContainer eC, ArtistaContainer aC, AlbumContainer alC, ListaReproducaoContainer lC){

    mC.musicas.clear();
    aC.artistas.clear();
    //alC.albuns.clear();
    eC.editoras.clear();
    //lC.listas.clear();

    carregarMusicas(mC);
    carregarAlbums(alC, mC);
    carregarArtistas(aC, alC);
    carregarEditoras(eC, aC);
    carregarListas(lC, mC);

}





