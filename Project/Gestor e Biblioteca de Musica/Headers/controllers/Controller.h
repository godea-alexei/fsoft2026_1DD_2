
#include "View.h"
//#include "AlbumView.h"
//#include "ArtistaView.h"
#include "ContaView.h"
//#include "ListaReproducaoView.h"
//#include "MusicaView.h"
//#include "PesquisaView.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <list>


class Controller{

	private:
		View view;
		ContaView contaView;
		/*AlbumView albumView;
		ArtistaView artistaView;

		ListaReproducaoView listadereproducao;
		MusicaView musicaView;
		PesquisaView pesquisaView;
		*/
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


