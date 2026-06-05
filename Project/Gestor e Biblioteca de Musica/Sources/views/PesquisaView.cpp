
#include "PesquisaView.h"
#include <iostream>

using namespace std;

void PesquisaView::show() {
    int option;

    do {
        showOptions();
        option = askSearchType();

        if (option != 0) {
            string term = askSearchTerm();

            cout << "A pesquisar por: " << term << endl;

            // Mais tarde:
            // chamar SearchController aqui
        }

    } while (option != 0);
}

void PesquisaView::showOptions() {
    cout << "\n===== Pesquisa =====\n";
    cout << "1. Pesquisar música\n";
    cout << "2. Pesquisar artista\n";
    cout << "3. Pesquisar álbum\n";
    cout << "4. Pesquisar tudo\n";
    cout << "0. Voltar\n";
}

int PesquisaView::askSearchType() {
    int option;
    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();

    return option;
}

string PesquisaView::askSearchTerm() {
    string term;
    cout << "Pesquisar: ";
    getline(cin, term);

    return term;
}
