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



#endif //PESQUISAVIEW_H
