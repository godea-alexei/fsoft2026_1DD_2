#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_ELEMENTONAOEXISTE_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_ELEMENTONAOEXISTE_H
#include <exception>

class ElementoNaoExiste : public std::exception {

    public:
        const char* what() const noexcept override;

};

#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_ELEMENTONAOEXISTE_H