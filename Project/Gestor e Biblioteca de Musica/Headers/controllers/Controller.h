#include "View.h"
#include "ContaView.h"
#include "Utils.h"
#include "UtilizadorContainer.h"
#include "MusicaContainer.h"
#include "ListaReproducaoContainer.h"
#include "Artistacontainer.h"
#include "EditoraContainer.h"
#include "AlbumContainer.h"
#include "BaseView.h"
#include "repo/Repositorio.h"



class Controller{
private:

	public:

		View view;
		ContaView contaView;
		Utils utils;
		BaseView baseView;
		Utilizador* utilizadorAtual = nullptr;
		string msg = "";

		void runConta();
		void runPesquisa();
		void runEscolherPesquisa();
		void runListaReproducao();
		void runMusica();
		void runAlbum();
		void runEditora();
		void runArtista();
		void runPartilhar();
		void runRegisto();
		void runLogin();

		UtilizadorContainer utilizadorContainer;
		EditoraContainer editoraContainer;
		MusicaContainer musicaContainer;
		ListaReproducaoContainer listaReproducaoContainer;
		AlbumContainer albumContainer;
		ArtistaContainer artistaContainer;
		Repositorio repositorio;

		Controller();
		~Controller();

		void run();

};


