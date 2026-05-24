#include "Musica.h"
#include <string>
#include <SFML/Audio.hpp>

using namespace std;


std::string Musica::verLetra(){

    std::cout << letra << std::endl;
    return letra;

};


void reproduzir(){

    sf::SoundBuffer buffer;
    buffer.loadFromFile("./././repo/nome.wav");

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    // espera o som terminar
    while (sound.getStatus() == sf::Sound::Playing) {}

};
