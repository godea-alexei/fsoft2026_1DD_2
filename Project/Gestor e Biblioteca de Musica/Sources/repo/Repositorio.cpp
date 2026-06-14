#include "../../Headers/repo/Repositorio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include "Controller.h"
#include "MusicaContainer.h"
#include <nlohmann/json.hpp>
#include "Artista.h"
using json = nlohmann::json;



string Repositorio::diretorioJSON = "../Dados/";

Repositorio::Repositorio(){}

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

    //criar objeto json
    json j;
    j["nome"]             = m.getNome();
    j["duracao"]          = m.getDuracao();
    j["anoDeLancamento"] = m.getAnoDeLancamento();
    j["letra"]            = m.getLetra();
    j["genero"]           = m.getGenero();
    j["caminho"]          = m.getCaminho();
    j["nomeArtista"]      = m.getNomeArtista();

    // meter no array
    jsonArray.push_back(j);

    //guardar
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
    j["nome"]             = a.nome;
    j["anoNascimento"]    = a.anoNascimento;

    json jsonArrayAlbuns = json::array();
    for (const Album* album : a.getAlbuns()){
        if (album != nullptr) {
            jsonArrayAlbuns.push_back(album->getNome());
        }
    }
    j["albums"] = jsonArrayAlbuns;

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
    j["anoLancamento"] = a.getAnoLancamento();

    json jsonArrayMusicas = json::array();
    for (Musica *m : a.musicas){
        jsonArrayMusicas.push_back(m->getNome());
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
    string caminho = diretorioJSON + "Utilizadores.json";

    json jsonArray = lerFicheiroJSON(caminho);

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
    j["nomeLista"] = l.getNome();
    j["criador"]   = l.getCriador();
    j["duracao"] = l.getDuracao();
    j["anoCriacao"] = l.getDataCriacao();

    json jsonArrayMusicas = json::array();
    for (Musica* m : l.musicas){
        jsonArrayMusicas.push_back(m->getNome());
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

void Repositorio::eliminarEditora(string n) {

    string caminho = diretorioJSON + "Editoras.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
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

void Repositorio::eliminarArtista(string n) {

    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i]["nome"] == n) {
            jsonArray.erase(i);
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
        if (jsonArray[i].contains("nomeAlbum") && jsonArray[i]["nomeAlbum"] == n) {
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
        if (jsonArray[i].contains("nomeLista") && jsonArray[i]["nomeLista"] == n) {

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



vector<Musica> Repositorio::carregarMusicas() {

    vector<Musica> musicas;

    string caminho = diretorioJSON + "Musicas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (auto& j : jsonArray) {
        Musica m(
        j["nome"],
        j["duracao"],
        j["anoDeLancamento"],
        j["letra"],
        j["genero"],
        j["caminho"],
        j["nomeArtista"]);

        musicas.push_back(m);

    }
    return musicas;
}

vector<Editora> Repositorio::carregarEditoras(ArtistaContainer& artistas)
{
    vector<Editora> editoras;

    string caminho = diretorioJSON + "Editoras.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for(auto& j : jsonArray)
    {
        Editora e(
            j["nome"]
        );

        for (auto& nomeArtista : j["artistas"]) {
            Artista* a = artistas.procurarArtista(nomeArtista);
            if(a != nullptr) {
                e.adicionarArtista(a);
            }
        }

        editoras.push_back(e);
    }

    return editoras;
}


vector<Utilizador> Repositorio::carregarUtilizadores()
{
    vector<Utilizador> utilizadores;

    string caminho = diretorioJSON + "Utilizadores.json";

    json jsonArray = lerFicheiroJSON(caminho);

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


vector<Artista> Repositorio::carregarArtistas(AlbumContainer& albuns)
{
    vector<Artista> artistas;

    string caminho = diretorioJSON + "Artistas.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for(auto& j : jsonArray)
    {
        Artista a(
            j["nome"],
            j["anoNascimento"]
        );

        for (auto& nomeAlbum : j["albums"]) {
            Album* album = albuns.procurarAlbum(nomeAlbum);
            if(album != nullptr) {
                a.adicionarAlbum(album);
            }
        }

        artistas.push_back(a);
    }

    return artistas;
}

std::vector<ListaReproducao> Repositorio::carregarListas(MusicaContainer& musicas) {
    vector<ListaReproducao> listas;

    string caminho = diretorioJSON + "Listas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (auto& j : jsonArray) {
        ListaReproducao lista(
            j["nomeLista"],
            j.value("anoCriacao", 0),
            j["criador"]);

        for (auto& nomeMusica : j["Musicas"]) {
            Musica* musica = musicas.procurarMusica(nomeMusica);

            if (musica != nullptr) {
                lista.adicionarMusica(musica);
            }
        }
        listas.push_back(lista);
    };

    return listas;
}

std::vector<Album> Repositorio::carregarAlbuns(MusicaContainer& musicas) {
    vector<Album> albums;

    string caminho = diretorioJSON + "Albuns.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for (auto& j : jsonArray) {
        Album a(
            j["nomeAlbum"],
            j["anoLancamento"]
        );

        for (auto& nomeMusica : j["Musicas"]) {
            Musica* musica = musicas.procurarMusica(nomeMusica);

            if (musica != nullptr) {
                a.adicionarMusica(musica);
            }
        }
        albums.push_back(a);
    }
    return albums;
}