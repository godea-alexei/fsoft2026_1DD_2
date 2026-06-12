#include "ElementoNaoExiste.h"
#include <exception>
#include <iostream>

const char* ElementoNaoExiste::what() const noexcept{
    return "Erro: o elemento procurado nao existe.";
}