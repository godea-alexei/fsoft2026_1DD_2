#include "ForaDosLimites.h"
#include <exception>
#include <iostream>


const char* ForaDosLimites::what() const noexcept{

    return "Erro: o valor introduzido esta fora dos limites permitidos.";

}