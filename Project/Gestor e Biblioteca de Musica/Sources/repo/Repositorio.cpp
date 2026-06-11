#include "../../Headers/repo/Repositorio.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdio>
#include <fstream>

#include "MusicaContainer.h"
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
        jasonAlbum["nomeAlbum"] = album.getNome();
        jasonAlbum["duracao"] = album.getDuracao();
        jasonAlbum["anoCriacao"] = album.getDataCriacao();
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

    string caminho = diretorioJSON + "Albums.json";
    json jsonArray = lerFicheiroJSON(caminho);

    json j;
    j["nomeAlbum"] = a.getNome();
    j["duracao"] = a.getDuracao();
    j["anoCriacao"] = a.getDataCriacao();
    j["nomeArtista"] = a.artista;

    json jsonArrayMusicas = json::array();
    for (Musica m : a.getMusicas()){

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


    jsonArray.push_back(j);

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

}

void Repositorio::guardarUtilizador(Utilizador u)
{
    string caminho =
        diretorioJSON + "Utilizadores.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    json j;

    j["nome"] = u.getNome();
    j["anoNascimento"] = u.getAnoNascimento();
    j["palavraPasse"] = u.getPalavraPasse();

    jsonArray.push_back(j);

    ofstream outFile(caminho);

    if(outFile.is_open())
    {
        outFile << jsonArray.dump(4);
        outFile.close();
    }
    else
    {
        cout << "Erro escrita.\n";
    }
}

void Repositorio::guardarLista(ListaReproducao l) {

    string caminho = diretorioJSON + "Listas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    json j;
    j["nomeAlbum"] = l.getNome();
    j["duracao"] = l.getDuracao();
    j["anoCriacao"] = l.getDataCriacao();

    json jsonArrayMusicas = json::array();
    for (Musica m : l.getMusicas()){

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

    jsonArray.push_back(j);

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

}



void Repositorio::eliminarMusica(string n) {

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

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarEditora(string n) {

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

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarArtista(string n) {

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

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarAlbum(string n) {

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

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarUtilizador(
    string nome)
{
    string caminho =
        diretorioJSON + "Utilizadores.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    for(auto it = jsonArray.begin();
        it != jsonArray.end();)
    {
        if((*it)["nome"] == nome)
        {
            it = jsonArray.erase(it);
        }
        else
        {
            ++it;
        }
    }

    ofstream outFile(caminho);

    if(outFile.is_open())
    {
        outFile << jsonArray.dump(4);
        outFile.close();
    }
}

void Repositorio::eliminarLista(string n) {

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

    cout << "Elemento eliminado com sucesso";

}



void Repositorio::carregarMusicas() {

    /*
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

        MusicaContainer musicas.push_back(m);

    }
    */
}

void Repositorio::carregarEditoras() {

}
    /*
    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        Editora e;
        e.nome = j["nome"];
        for (json j2 : j["artistas"]) {

            Artista a2;
            a2.nome = j2["nome"];
            a2.anoNascimento = j2["anoNascimento"];
            for ()
            a2.albums = j2["albums"];

        }

        //EditoraContainer editoras.push_back(e);

    }
    */

vector<Utilizador> Repositorio::carregarUtilizadores()
{
    vector<Utilizador> utilizadores;

    string caminho =
        diretorioJSON + "Utilizadores.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    for(auto& j : jsonArray)
    {
        Utilizador u(
            j["nome"],
            j["anoNascimento"],
            j["palavraPasse"]
        );

        utilizadores.push_back(u);
    }

    return utilizadores;
}


void Repositorio::carregarArtistas(){}
void Repositorio::carregarAlbums(){}
void Repositorio::carregarListas() {

}
void Repositorio::carregarAlbuns(){}