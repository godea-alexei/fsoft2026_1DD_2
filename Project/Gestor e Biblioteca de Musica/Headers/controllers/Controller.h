#include "View.h"
#include "ContaView.h"
#include "Utils.h"
#include "UtilizadorContainer.h"
#include <iostream>
#include <string>
#include <vector>
#include "MusicaContainer.h"
#include "ListaReproducaoContainer.h"
#include "Artistacontainer.h"
#include "EditoraContainer.h"
#include "AlbumContainer.h"
#include "AlbumContainer.h"
#include "Artistacontainer.h"
#include "BaseView.h"
#include "EditoraContainer.h"
#include "ListaReproducaoContainer.h"
#include "MusicaContainer.h"
#include "repo/Repositorio.h"



class Controller{

	public:

		View view;
		ContaView contaView;
		Utils utils;
		BaseView baseView;
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

		UtilizadorContainer utilizadorContainer;
		EditoraContainer editoraContainer;
		MusicaContainer musicaContainer;
		ListaReproducaoContainer listaReproducaoContainer; // >>> CORRECAO: nome do membro estava 'listaReproducaoConteiner' (erro de escrita); o Controller.cpp ja usava 'listaReproducaoContainer'
		AlbumContainer albumContainer;
		ArtistaContainer artistaContainer;
		Repositorio repositorio;

		Controller();
		~Controller();

		void run();

};


