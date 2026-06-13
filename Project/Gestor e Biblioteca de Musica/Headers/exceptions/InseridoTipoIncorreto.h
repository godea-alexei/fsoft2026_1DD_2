#ifndef GESTOR_E_BIBLIOTECA_DE_MUSICA_INSERIDOTIPOINCORRETO_H
#define GESTOR_E_BIBLIOTECA_DE_MUSICA_INSERIDOTIPOINCORRETO_H
#include <exception>

class InseridoTipoIncorreto : public std::exception {

    public:
        const char* what() const noexcept override;
};


#endif //GESTOR_E_BIBLIOTECA_DE_MUSICA_INSERIDOTIPOINCORRETO_H