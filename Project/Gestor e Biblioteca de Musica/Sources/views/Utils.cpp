#include "Utils.h"
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>


/*
float Utils::getFloat(const std::string& s) {
    try {
        return std::stof(s);
    } catch (...) {
        throw std::invalid_argument("Não foi possível converter para float: " + s);
    }
}

bool Utils::getBool(const std::string& s) {
    std::string lower = s;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "true"  || lower == "1" || lower == "sim") return true;
    if (lower == "false" || lower == "0" || lower == "nao" || lower == "não") return false;
    throw std::invalid_argument("Valor inválido para bool: " + s);
}

// Utilizador válido: mínimo 3 caracteres, apenas letras, dígitos e '_'
bool Utils::validarUser(const std::string& s) {
    if (s.size() < 3) return false;
    for (char c : s)
        if (!std::isalnum(c) && c != '_') return false;
    return true;
}

// Password válida: mínimo 8 caracteres, pelo menos uma letra e um dígito
bool Utils::validarPass(const std::string& s) {
    if (s.size() < 8) return false;
    bool temLetra  = false;
    bool temDigito = false;
    for (char c : s) {
        if (std::isalpha(c)) temLetra  = true;
        if (std::isdigit(c)) temDigito = true;
    }
    return temLetra && temDigito;
}
*/


std::string Utils::getString(const std::string& s) {
    std::string input;
    std::cout<<s<<": ";
    getline (std::cin, input);
    return input;
}


int Utils::getNumber(const std::string& label) {

    int number;
    bool flag = false;
    do{

        std::cout<<label<<": ";
        flag = false;
        std::cin >> number;

        if(std::cin.fail()){
            std::cout << "Nao e um numero, por favor insira um numero" << std::endl;
            std::cin.clear(); //corrects stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag == true);

    std::cin.clear(); //corrects stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return number;

}