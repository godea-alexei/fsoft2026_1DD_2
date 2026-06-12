#include <iostream>
#include "Controller.h"
#include "../../Headers/repo/Repositorio.h"

int main() {

    std::cout << "Program initialized. \n" << std::endl;

    Controller controller;

    Repositorio repo;
    //repo.carregarUtilizadores();
    repo.carregarMusicas(controller.musicaContainer);
    repo.carregarAlbums(controller.albumContainer, controller.musicaContainer);
    repo.carregarArtistas(controller.artistaContainer, controller.albumContainer);
    repo.carregarEditoras(controller.editoraContainer, controller.artistaContainer);
    repo.carregarListas(controller.listaReproducaoConteiner, controller.musicaContainer);

    controller.run();

    std::cout << "Program exited." << std::endl;

    return 0;

}
