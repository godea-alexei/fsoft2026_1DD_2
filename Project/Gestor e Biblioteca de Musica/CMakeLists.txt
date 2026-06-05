cmake_minimum_required(VERSION 4.0)
project(Gestor_e_Biblioteca_de_Musica)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Headers)
include_directories(Headers/controllers)
include_directories(Headers/exceptions)
include_directories(Headers/model)
include_directories(Headers/views)
include_directories(Sources)

add_executable(Gestor_e_Biblioteca_de_Musica
        Headers/controllers/Controller.h
        Headers/exceptions/CancelarAdicaoAlbumException.h
        Headers/exceptions/CancelarAdicaoArtistaException.h
        Headers/exceptions/CancelarAdicaoEditoraException.h
        Headers/exceptions/CancelarAdicaoMusicaException.h
        Headers/exceptions/CancelarCriacaoContaException.h
        Headers/exceptions/CancelarCriacaoListaException.h
        Headers/exceptions/CancelarInicioSessaoException.h
        Headers/exceptions/CancelarPartilhaListaException.h
        Headers/exceptions/CancelarPartilhaMusicaException.h
        Headers/exceptions/CancelarPesquisaMusicaException.h
        Headers/exceptions/CancelarRemocaoAlbumException.h
        Headers/exceptions/CancelarRemocaoArtistaException.h
        Headers/exceptions/CancelarRemocaoEditoraException.h
        Headers/exceptions/CancelarRemocaoMusicaException.h
        Headers/model/Album.h
        Headers/model/AlbumContainer.h
        Headers/model/Artista.h
        Headers/model/Artistacontainer.h
        Headers/model/Editora.h
        Headers/model/EditoraContainer.h
        Headers/model/ListaReproducao.h
        Headers/model/ListaReproducaoContainer.h
        Headers/model/Musica.h
        Headers/model/MusicaContainer.h
        Headers/model/Pessoa.h
        Headers/model/Utilizador.h
        Headers/model/UtilizadorContainer.h
        Headers/views/Albumview.h
        Headers/views/ArtistaView.h
        Headers/views/ContaView.h
        Headers/views/ListaReproducaoView.h
        Headers/views/MusicaView.h
        Headers/views/PesquisaView.h
        Headers/views/Utils.h
        Headers/views/View.h
        Headers/views/BaseView.h
        Sources/controllers/Controller.cpp
        Sources/exceptions/CancelarAdicaoAlbumException.cpp
        Sources/exceptions/CancelarCriacaoContaException.cpp
        Sources/exceptions/CancelarInicioSessaoException.cpp
        Sources/exceptions/CancelarPartilhaMusicaException.cpp
        Sources/exceptions/CancelarPesquisaMusicaException.cpp
        Sources/exceptions/CancelarRemocaoAlbumException.cpp
        Sources/model/Album.cpp
        Sources/model/AlbumContainer.cpp
        Sources/model/Artista.cpp
        Sources/model/ArtistaContainer.cpp
        Sources/model/Editora.cpp
        Sources/model/EditoraContainer.cpp
        Sources/model/ListaReproducao.cpp
        Sources/model/ListaReproducaoContainer.cpp
        Sources/model/Musica.cpp
        Sources/model/MusicaContainer.cpp
        Sources/model/Pessoa.cpp
        Sources/model/Utilizador.cpp
        Sources/model/UtilizadorContainer.cpp
        Sources/views/AlbumView.cpp
        Sources/views/ArtistaView.cpp
        Sources/views/ContaView.cpp
        Sources/views/ListaReproducaoView.cpp
        Sources/views/MusicaView.cpp
        Sources/views/PesquisaView.cpp
        Sources/views/Utils.cpp
        Sources/views/View.cpp
        Sources/views/BaseView.cpp
        main.cpp
        Sources/views/BaseView.cpp
        Headers/views/BaseView.h)

target_link_libraries(Gestor_e_Biblioteca_de_Musica winmm)

