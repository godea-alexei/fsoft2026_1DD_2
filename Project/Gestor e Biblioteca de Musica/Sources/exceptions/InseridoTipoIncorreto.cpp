#include "InseridoTipoIncorreto.h"
#include <exception>
#include <iostream>


const char* InseridoTipoIncorreto::what() const noexcept{
    return  "Erro: o valor introduzido nao e do tipo correto.";
}
