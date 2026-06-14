#include <iostream>
#include "Controller.h"
#include "../../Headers/repo/Repositorio.h"

int main() {

    std::cout << "Program initialized. \n" << std::endl;

    Controller controller;

    controller.runConta();

    std::cout << "Program exited." << std::endl;

    return 0;

}
