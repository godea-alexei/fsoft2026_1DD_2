#ifndef EDITORACONTAINER_H
#define EDITORACONTAINER_H

#include <string>
#include <list>
#include "Editora.h"
using namespace std;

class EditoraContainer {

private:
    list<Editora*> editoras;

public:
    EditoraContainer();
    ~EditoraContainer();

    void adicionarEditora();
    void removerEditora();
    Editora* procurarEditora(string nome);
    list<Editora*>& getAll();
};

#endif
