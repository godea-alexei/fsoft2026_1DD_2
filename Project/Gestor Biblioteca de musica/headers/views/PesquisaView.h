//
// Created by faixe on 19/05/2026.
//

#ifndef PESQUISAVIEW_H
#define PESQUISAVIEW_H
#include <string>

class PesquisaView {
public:
    void show();

private:
    void showOptions();
    std::string askSearchTerm();
    int askSearchType();
};


#endif
#endif //PESQUISAVIEW_H
