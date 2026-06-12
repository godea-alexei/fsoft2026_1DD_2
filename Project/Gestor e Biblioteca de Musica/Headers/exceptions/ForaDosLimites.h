#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_FORADOSLIMITES_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_FORADOSLIMITES_H
#include <exception>

class ForaDosLimites : public std::exception{

    public:
        const char* what() const noexcept override;

};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_FORADOSLIMITES_H