#include "View.h"
#include "ContaView.h"
#include "Utils.h"
#include "UtilizadorContainer.h"
#include <iostream>
#include <string>
#include <list>

#include "EditoraContainer.h"


class Controller{

	private:
		View view;
		ContaView contaView;
		Utils utils;
		UtilizadorContainer utilizadorContainer;
		EditoraContainer editoraContainer;

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

	public:
		Controller();
		void run();
};


