#ifndef VIEW_H
#define VIEW_H

class View{

   public:
        View(){};
        int menuEscolhaPesquisa();
        int menuPesquisa();
        int menuMusica();
        int menuPartilha();
        int menuConta();
        int menuPrincipal();
        int menuAlbum();
        int menuArtista();
        int menuEditora();
        int menuLista();

        int artistaEmEditora();
        int albumEmArtista();
        int musicaEmAlbum();
        int musicaEmLista();


};
















#endif //VIEW_H
