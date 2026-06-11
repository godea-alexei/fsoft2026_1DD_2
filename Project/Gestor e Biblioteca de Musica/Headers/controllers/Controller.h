#include "View.h"
#include "ContaView.h"
#include "Utils.h"
#include "UtilizadorContainer.h"
#include <iostream>
#include <string>
#include <list>

#include "AlbumContainer.h"
#include "Artistacontainer.h"
#include "EditoraContainer.h"
#include "ListaReproducaoContainer.h"
#include "repo/Repositorio.h"


class Controller{

	private:
		View view;
		ContaView contaView;
		Utils utils;
		UtilizadorContainer utilizadorContainer;
		EditoraContainer editoraContainer;
		ArtistaContainer artistaContainer;
		ListaReproducaoContainer listaReproducaoContainer;
		Repositorio repositorio;



		Utilizador* utilizadorAtual = nullptr;

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

		void runRelacionarArtista();

	public:
		Controller();
		void run();
};


