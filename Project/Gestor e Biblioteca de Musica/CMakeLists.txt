cmake_minimum_required(VERSION 3.31.6)
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
        Headers/views/ContaView.h
        Headers/views/Utils.h
        Headers/views/View.h
        Headers/views/BaseView.h
        Sources/controllers/Controller.cpp
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
        Sources/views/ContaView.cpp
        Sources/views/Utils.cpp
        Sources/views/View.cpp
        Sources/views/BaseView.cpp
        main.cpp
        Sources/views/BaseView.cpp
        Headers/views/BaseView.h
        Sources/repo/Repositorio.cpp
        Headers/repo/Repositorio.h
        Sources/exceptions/ElementoJaExiste.cpp
        Headers/exceptions/ElementoJaExiste.h
        Sources/exceptions/ElementoNaoExiste.cpp
        Headers/exceptions/ElementoNaoExiste.h
        Sources/exceptions/ForaDosLimites.cpp
        Headers/exceptions/ForaDosLimites.h
        Sources/exceptions/InseridoTipoIncorreto.cpp
        Headers/exceptions/InseridoTipoIncorreto.h)

target_link_libraries(Gestor_e_Biblioteca_de_Musica winmm)



include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)
target_link_libraries(Gestor_e_Biblioteca_de_Musica nlohmann_json::nlohmann_json)
