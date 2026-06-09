#ifndef CONTAVIEW_H
#define CONTAVIEW_H

#include <string>


class ContaView {
public:
    ContaView();

    std::string getNome();
    int getAnoNascimento();
    std::string getPalavraPasse();
    std::string getPalavraPasseConfirmation();

    void sucessoRegisto();
    void sucessoLogin();
    void falhaRegisto();
    void falhaLogin();
};


#endif //CONTAVIEW_H
