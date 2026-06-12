#include "ElementoJaExiste.h"
#include <exception>
#include <iostream>

const char* ElementoJaExiste::what() const noexcept {
    return "Erro: o elemento que tentou criar ja existe.";
}

