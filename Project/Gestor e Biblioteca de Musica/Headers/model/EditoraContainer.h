#ifndef EDITORACONTAINER_H
#define EDITORACONTAINER_H

#include <vector>
#include "Editora.h"

class EditoraContainer {
private:
    std::vector<Editora> editoras;

public:
    void adicionarEditora(const Editora& editora);

    bool existeEditora(const string& nome) const;

    bool removerEditora(const string& nome);

    const vector<Editora>& getEditoras() const;

    Editora* procurar(const std::string& nome);
};

#endif //EDITORACONTAINER_H