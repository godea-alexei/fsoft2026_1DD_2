#include "Utils.h"
#include <stdexcept>
#include <algorithm>
#include <cctype>

float Util::getFloat(const std::string& s) {
    try {
        return std::stof(s);
    } catch (...) {
        throw std::invalid_argument("Não foi possível converter para float: " + s);
    }
}

bool Util::getBool(const std::string& s) {
    std::string lower = s;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "true"  || lower == "1" || lower == "sim") return true;
    if (lower == "false" || lower == "0" || lower == "nao" || lower == "não") return false;
    throw std::invalid_argument("Valor inválido para bool: " + s);
}

// Utilizador válido: mínimo 3 caracteres, apenas letras, dígitos e '_'
bool Util::validarUser(const std::string& s) {
    if (s.size() < 3) return false;
    for (char c : s)
        if (!std::isalnum(c) && c != '_') return false;
    return true;
}

// Password válida: mínimo 8 caracteres, pelo menos uma letra e um dígito
bool Util::validarPass(const std::string& s) {
    if (s.size() < 8) return false;
    bool temLetra  = false;
    bool temDigito = false;
    for (char c : s) {
        if (std::isalpha(c)) temLetra  = true;
        if (std::isdigit(c)) temDigito = true;
    }
    return temLetra && temDigito;
}

// Remove espaços do início e fim (trim)
std::string Util::getString(const std::string& s) {
    size_t inicio = s.find_first_not_of(" \t\n\r");
    if (inicio == std::string::npos) return "";
    size_t fim = s.find_last_not_of(" \t\n\r");
    return s.substr(inicio, fim - inicio + 1);
}

int Util::getNumber(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        throw std::invalid_argument("Não foi possível converter para int: " + s);
    }
}