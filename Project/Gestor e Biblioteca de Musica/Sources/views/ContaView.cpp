#include <iostream>

#include "ContaView.h"
#include "Utils.h"

using namespace std;

ContaView::ContaView() {
}

string ContaView::getNome() {
    return Utils::getString("Nome");
}

int ContaView::getAnoNascimento() {
    return Utils::getNumber("Ano Nascimento");
}


string ContaView::getPalavraPasse() {
    return Utils::getString("Palavra-passe");
}

string ContaView::getPalavraPasseConfirmation() {
    return Utils::getString("Confirme a palavra-passe");
}

void ContaView::sucessoRegisto() {
    cout << "\nConta Criada com sucesso!\n";
}

void ContaView::sucessoLogin() {
    cout << "\nSessao iniciada com sucesso!\n";
}

void ContaView::falhaRegisto() {
    cout << "Credenciais erradas. Tente fazer um novo registo.\n";
}

void ContaView::falhaLogin() {
    cout << "Credenciais erradas. Tente iniciar sessão novamente.\n";
}
