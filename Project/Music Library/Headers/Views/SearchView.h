//
// Created by faixe on 19/05/2026.
//

#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H
#include <string>

class SearchView {
public:
    void show();

private:
    void showOptions();
    std::string askSearchTerm();
    int askSearchType();
};


#endif
#endif //PESQUISAVIEW_H
