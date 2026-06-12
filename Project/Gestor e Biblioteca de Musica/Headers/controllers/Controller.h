#include "View.h"
#include "ContaView.h"
#include "Utils.h"
#include "UtilizadorContainer.h"
#include <iostream>
#include <string>
#include <list>
#include "MusicaContainer.h"
#include "ListaReproducaoContainer.h"
#include "Artistacontainer.h"
#include "EditoraContainer.h"
#include "AlbumContainer.h"

#include "AlbumContainer.h"
#include "Artistacontainer.h"
#include "EditoraContainer.h"
#include "ListaReproducaoContainer.h"
#include "MusicaContainer.h"
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
		AlbumContainer albumContainer;
		MusicaContainer musicaContainer;
		Repositorio repositorio;




		Utilizador* utilizadorAtual = nullptr;

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

		UtilizadorContainer utilizadorContainer;
		EditoraContainer editoraContainer;
		MusicaContainer musicaContainer;
		ListaReproducaoContainer listaReproducaoConteiner;
		AlbumContainer albumContainer;
		ArtistaContainer artistaContainer;

		Controller();
		void run();
};


