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

    ifstream inFile(caminho);
    if (inFile.is_open()) {
        string fileContent;

        fileContent.assign((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();

        if (!fileContent.empty()) {
            try {
                jsonArr = json::parse(fileContent);
                if (!jsonArr.is_array()) {
                    jsonArr = json::array();
                }
            } catch (const json::parse_error& e) {
                jsonArr = json::array();
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
    j["nome"]             = m.getNome();
    j["duracao"]          = m.getDuracao();
    j["anoDeLancamento"] = m.getAnoDeLancamento();
    j["letra"]            = m.getLetra();
    j["genero"]           = m.getGenero();
    j["caminho"]          = m.getCaminho();
    j["nomeArtista"]      = m.getNomeArtista();

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
    std::ifstream src(m.getCaminho(), std::ios::binary);
    std::ofstream dst(diretorioJSON + "Audio/" + m.getNome() + ".mp3", std::ios::binary);
    dst << src.rdbuf();

}

void Repositorio::guardarEditora(const Editora& e) {

    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    json j;
    j["nome"]= e.getNome();

    json jsonArrayArtista = json::array();
    for (const auto& artista : e.getArtistas()) {
        if (artista != nullptr) {
            jsonArrayArtista.push_back(artista->getNome());
        }

    }

    j["artistas"] = jsonArrayArtista;

    jsonArray.push_back(j);

    ofstream outFile(caminho);
    if (outFile.is_open()) {
        outFile << jsonArray.dump(4);
        outFile.close();
    } else {
        cout << "Erro escrita.\n";
    }

}

void Repositorio::guardarArtista(const Artista& a)
{
    string caminho =
        diretorioJSON + "Artistas.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    json j;

    j["nome"] = a.getNome();
    j["anoNascimento"] =
        a.getAnoNascimento();

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

void Repositorio::guardarAlbum(Album a) {

    string caminho = diretorioJSON + "Albuns.json";
    json jsonArray = lerFicheiroJSON(caminho);

    json j;
    j["nomeAlbum"] = a.getNome();
    j["duracao"] = a.getDuracao();
    j["anoCriacao"] = a.getAnoLancamento();

    json jsonArrayMusicas = json::array();
    for (Musica* m : a.getMusicas()){

        json jasonMusica = json::array();
        jasonMusica["nome"]             = m->getNome();
        jasonMusica["duracao"]          = m->getDuracao();
        jasonMusica["anoDeLancamento"] = m->getAnoDeLancamento();
        jasonMusica["letra"]            = m->getLetra();
        jasonMusica["genero"]           = m->getGenero();
        jasonMusica["caminho"]          = m->getCaminho();
        jasonMusica["nomeArtista"]      = m->getNomeArtista();
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
    for (Musica* m : l.getMusicas()){

        json jasonMusica = json::array();
        jasonMusica["nome"]             = m->getNome();
        jasonMusica["duracao"]          = m->getDuracao();
        jasonMusica["dataDeLancamento"] = m->getAnoDeLancamento();
        jasonMusica["letra"]            = m->getLetra();
        jasonMusica["genero"]           = m->getNome();
        jasonMusica["caminho"]          = m->getCaminho();
        jasonMusica["nomeArtista"]      = m->getNomeArtista();
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

}

void Repositorio::eliminarEditora(string nome)
{
    string caminho =
        diretorioJSON + "Editoras.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    for(auto it = jsonArray.begin();
        it != jsonArray.end();
        ++it)
    {
        if((*it)["nome"] == nome)
        {
            jsonArray.erase(it);
            break;
        }
    }

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

void Repositorio::eliminarArtista(
    string nome)
{
    string caminho =
        diretorioJSON + "Artistas.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    for(auto it = jsonArray.begin();
        it != jsonArray.end();
        ++it)
    {
        if((*it)["nome"] == nome)
        {
            jsonArray.erase(it);
            break;
        }
    }

    ofstream outFile(caminho);

    if(outFile.is_open())
    {
        outFile << jsonArray.dump(4);
        outFile.close();
    }
}

void Repositorio::eliminarAlbum(string n) {

    string caminho = diretorioJSON + "Albuns.json";
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

void Repositorio::carregarEditoras(
    EditoraContainer& editoraContainer,
    ArtistaContainer& artistaContainer)
{
    string caminho = diretorioJSON + "Editoras.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for(const auto& j : jsonArray)
    {
        string nomeEditora = j["nome"];

        Editora editora(nomeEditora);

        if(j.contains("artistas"))
        {
            for(const auto& nomeArtistaJson : j["artistas"])
            {
                string nomeArtista;

                if(nomeArtistaJson.is_string())
                {
                    nomeArtista = nomeArtistaJson;
                }
                else
                {
                    nomeArtista =
                        nomeArtistaJson["nome"];
                }

                Artista* artista =
                    artistaContainer
                    .procurarArtista(
                        nomeArtista);

                if(artista != nullptr)
                {
                    editora.adicionarArtista(
                        artista);
                }
            }
        }

        editoraContainer.adicionarEditora(
            editora);
    }
}


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


vector<Artista> Repositorio::carregarArtistas()
{
    vector<Artista> artistas;

    string caminho =
        diretorioJSON + "Artistas.json";

    json jsonArray =
        lerFicheiroJSON(caminho);

    for(auto& j : jsonArray)
    {
        Artista a(
            j["nome"],
            j["anoNascimento"]
        );

        artistas.push_back(a);
    }

    return artistas;
}

std::vector<ListaReproducao> Repositorio::carregarListas() {
    vector<ListaReproducao> listas;
    return listas;
}
std::vector<Album> Repositorio::carregarAlbuns() {
    vector<Album> albums;

    string caminho = diretorioJSON + "Albuns.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for (auto& j : jsonArray) {
        Album a(
            j["nome"],
            j["anoLancamento"]
        );

        albums.push_back(a);
    }
    return albums;
}