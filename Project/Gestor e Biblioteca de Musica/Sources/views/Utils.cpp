#include "Utils.h"
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
using namespace std;

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
    string input;
    cout<<s<<": ";
    getline (cin, input);
    return input;
}


int Utils::getNumber(const std::string& label) {
    int number;
    bool flag = false;
    do{
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if(cin.fail()){
            cout << "Nao e um numero, por favor insira um numero" << endl;
            cin.clear(); //corrects stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag == true);
    cin.clear(); //corrects stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}