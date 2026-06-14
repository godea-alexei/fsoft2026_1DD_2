#include "Utils.h"
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>



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

void Utils::printMessage(std::string& msg) {
    std::cout << msg << std::endl;
}