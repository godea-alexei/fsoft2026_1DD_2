#include "View.h"
#include "ContaView.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <list>


class Controller{

	private:
		View view;
		ContaView contaView;
		Utils utils;

		void runConta();
		void runPesquisa();
		void runEscolherPesquisa();
		void runListaReproducao();
		void runMusica();
		void runAlbum();
		void runEditora();
		void runArtista();
		void runPartilhar();

	public:
		Controller();
		void run();
};


