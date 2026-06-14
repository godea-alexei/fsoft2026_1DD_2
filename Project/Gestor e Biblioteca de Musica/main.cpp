#include <iostream>
#include "Controller.h"
#include "../../Headers/repo/Repositorio.h"

int main() {

    std::cout << "Program initialized. \n" << std::endl;

    Controller controller;
    Repositorio repo;

    repo.carregarMusicas(controller.musicaContainer);
    repo.carregarAlbums(controller.albumContainer, controller.musicaContainer);
    repo.carregarArtistas(controller.artistaContainer, controller.albumContainer);
    repo.carregarEditoras(controller.editoraContainer, controller.artistaContainer);
    repo.carregarListas(controller.listaReproducaoContainer, controller.musicaContainer);
    repo.carregarUtilizadores(controller.utilizadorContainer);

    controller.runConta();

    std::cout << "Program exited." << std::endl;

    return 0;

}
