#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_ELEMENTOJAEXISTE_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_ELEMENTOJAEXISTE_H
#include <exception>

class ElementoJaExiste : public std::exception {

    public:
        const char* what() const noexcept override;

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_ELEMENTOJAEXISTE_H