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

    // --- 2. CREATE THE NEW OBJECT ---
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
    for (Album album : a.albums){

        json jasonAlbum = json::array();
        jasonAlbum["nomeAlbum"] = album.nome;
        jsonArrayAlbuns.push_back(jasonAlbum);

    }
    j["albuns"] = jsonArrayAlbuns;

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
    for (Musica *m : a.musicas){
        json jsonMusica = json::array();
        jsonMusica["nome"]             = m->getNome();
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

void Repositorio::guardarUtilizador(Utilizador u)
{
    string caminho = diretorioJSON + "Utilizadores.json";

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
    for (Musica* m : l.musicas){
        json jsonMusica = json::array();
        jsonMusica["nome"]             = m->getNome();
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

    if(outFile.is_open())
    {
        outFile << jsonArray.dump(4);
        outFile.close();
    }
    else
    {
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

    if(outFile.is_open())
    {
        outFile << jsonArray.dump(4);
        outFile.close();
    }

    cout << "Elemento eliminado com sucesso";

}

void Repositorio::eliminarAlbum(string n) {

    string caminho = diretorioJSON + "Albuns.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (int i = 0; i < jsonArray.size(); i++) {
        if (jsonArray[i].contains("nomeAlbum") && jsonArray[i]["nomeAlbum"] == n) { // >>> CORRECAO: chave era "nome"; o album e guardado com a chave "nomeAlbum", por isso a remocao nunca correspondia
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
        if (jsonArray[i].contains("nomeAlbum") && jsonArray[i]["nomeAlbum"] == n) { // >>> CORRECAO: chave era "nome"; a lista e guardada com a chave "nomeAlbum", por isso a remocao nunca correspondia
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



void Repositorio::carregarMusicas(MusicaContainer mC) {

    string caminho = diretorioJSON + "Musicas.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        Musica m = Musica(j["nome"], j["duracao"], j["dataDeLancamento"],
            j["letra"], j["genero"], j["caminho"], j["nomeArtista"]);

        mC.musicas.push_back(m);

    }

}

void Repositorio::carregarEditoras(EditoraContainer eC, ArtistaContainer aC) {

    string caminho = diretorioJSON + "Editoras.json";

    json jsonArray = lerFicheiroJSON(caminho);

    for(const auto& j : jsonArray)
    {
        string nomeEditora = j["nome"];

        Editora editora(nomeEditora);

        Editora e = Editora(j["nome"]);

        for (json j2 : j["artistas"]) {
            for (auto& artista : aC.artistas) {
                if (artista.getNome() == j2["nome"]) {
                    e.artistas.push_back(&artista);
                }
            }
        }

        eC.editoras.push_back(e);

    }

}

void Repositorio::carregarArtistas(ArtistaContainer aC, AlbumContainer alC) {

    string caminho = diretorioJSON + "Artistas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        Artista a = Artista(j["nome"], j["anoNascimento"]);

        for (json j2 : j["albuns"]) {
            for (auto& album : alC.albuns) {
                if (album.getNome() == j2["nome"]) {
                    a.albums.push_back(album);
                }
            }
        }

        aC.artistas.push_back(a);

    }

}

void Repositorio::carregarAlbums(AlbumContainer aC, MusicaContainer mC) {

    json jsonArray = lerFicheiroJSON(diretorioJSON + "Albums.json");

    for (json j : jsonArray) {
        Album a = Album(j["nomeAlbum"], j["anoCriacao"]);

        for (json j2 : j["musicas"]) {
            for (auto& musica : mC.musicas) {
                if (musica.getNome() == j2["nome"]) {
                    a.musicas.push_back(&musica);
                }
            }
        }

        aC.albuns.push_back(a);
    }

}

void Repositorio::carregarUtilizadores(UtilizadorContainer uC){

    json jsonArray = lerFicheiroJSON(diretorioJSON + "Utilizadores.json");

    for(auto& j : jsonArray)
    {
        Utilizador u(
            j["nome"],
            j["anoNascimento"],
            j["palavraPasse"]
        );

       uC.utilizadores.push_back(u);
    }

}


void Repositorio::carregarListas(ListaReproducaoContainer lC, MusicaContainer mC) {

    string caminho = diretorioJSON + "Listas.json";
    json jsonArray = lerFicheiroJSON(caminho);

    for (json j : jsonArray) {

        ListaReproducao l = ListaReproducao(j["nomeAlbum"], j["duracao"], j["anoCriacao"]); //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

        for (json j2 : j["musicas"]) {
            for (auto& musica : mC.musicas) {
                if (musica.getNome() == j2["nome"]) {
                    l.musicas.push_back(&musica);
                }
            }
        }

        lC.listas.push_back(l);

    }



}





/*
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



*/