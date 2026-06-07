#include "../../Headers/repo/Repositorio.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdio>
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;



string Repositorio::diretorioJSON = "../Dados/";



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

    string caminho = diretorioJSON + "Editoras.json";
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

    //Copiar fichieor audio

}

void Repositorio::guardarEditora(Editora e) {

    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    // --- 2. CREATE THE NEW SONG OBJECT ---
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

    json jsonArrayArtistas = json::array();
    for (Album album : a.albums){

        json jasonAlbum = json::array();
        jasonAlbum["nomeAlbum"] = album.nome;
        jasonAlbum["duracao"] = album.duracao;
        jasonAlbum["anoCriacao"] = album.anoCriacao;
        jasonAlbum["nomeArtista"] = a.nome;
        jsonArrayArtistas.push_back(jasonAlbum);

    }
    j["Albuns"] = jsonArrayArtistas;


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

    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    // --- 2. CREATE THE NEW SONG OBJECT ---
    json j;
    j["nomeAlbum"] = a.nome;
    j["duracao"] = a.duracao;
    j["anoCriacao"] = a.anoCriacao;
    j["nomeArtista"] = a.artista;

    json jsonArrayMusicas = json::array();
    for (Musica m : a.musicas){

        json jasonMusica = json::array();
        jasonMusica["nome"]             = m.nome;
        jasonMusica["duracao"]          = m.duracao;
        jasonMusica["dataDeLancamento"] = m.dataDeLancamento;
        jasonMusica["letra"]            = m.letra;
        jasonMusica["genero"]           = m.genero;
        jasonMusica["caminho"]          = m.caminho;
        jasonMusica["nomeArtista"]      = m.nomeArtista;
        jasonMusica["nomeAlbum"]        = m.nomeAlbum;
        jsonArrayMusicas.push_back(jasonMusica);

    }
    j["Musicas"] = jsonArrayMusicas;


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
void Repositorio::guardarUtilizador(Utilizador u) {



}
void Repositorio::guardarLista(ListaReproducao l) {

    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    // --- 2. CREATE THE NEW SONG OBJECT ---
    json j;
    j["nomeAlbum"] = l.nome;
    j["duracao"] = l.duracao;
    j["anoCriacao"] = l.anoCriacao;

    json jsonArrayMusicas = json::array();
    for (Musica m : l.musicas){

        json jasonMusica = json::array();
        jasonMusica["nome"]             = m.nome;
        jasonMusica["duracao"]          = m.duracao;
        jasonMusica["dataDeLancamento"] = m.dataDeLancamento;
        jasonMusica["letra"]            = m.letra;
        jasonMusica["genero"]           = m.genero;
        jasonMusica["caminho"]          = m.caminho;
        jasonMusica["nomeArtista"]      = m.nomeArtista;
        jasonMusica["nomeAlbum"]        = m.nomeAlbum;
        jsonArrayMusicas.push_back(jasonMusica);

    }
    j["Musicas"] = jsonArrayMusicas;


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
