#include <iostream>
#include "Controller.h"

int main() {
    std::cout << "Program initialized. \n" << std::endl;
    Controller controller;
    controller.run();
    controller.guardarDados();
    std::cout << "Program exited." << std::endl;
    return 0;
}