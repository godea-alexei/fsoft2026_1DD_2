#include <gtest/gtest.h>
#include "Musica.h"
#include "MusicaContainer.h"

// ============================================================================
//  Testes da CLASSE Musica  (construtor + getters)
//  Ideia: criar uma Musica conhecida e verificar que cada getter devolve
//  exatamente o que foi posto no construtor.
// ============================================================================
TEST(MusicaTest, ConstrutorGuardaTodosOsAtributos) {
    Musica m("nome_musica1", 354, 1975,
             "letra_musica1",
             "genero_musica1", "/audio/musica1.mp3", "artista_musica1");

    EXPECT_EQ(m.getNome(), "nome_musica1");
    EXPECT_EQ(m.getDuracao(), 354);
    EXPECT_EQ(m.getAnoDeLancamento(), 1975);
    EXPECT_EQ(m.getLetra(), "letra_musica1");
    EXPECT_EQ(m.getGenero(), "genero_musica1");
    EXPECT_EQ(m.getCaminho(), "/audio/musica1.mp3");
    EXPECT_EQ(m.getNomeArtista(), "artista_musica1");
}

// ============================================================================
//  Testes do MusicaContainer  (adicionar / existe / procurar / remover)
//  Como 'musicas' e static (partilhado), limpamos antes de cada teste
//  para que um teste nao influencie o outro.
// ============================================================================
class MusicaContainerTest : public ::testing::Test {
protected:
    MusicaContainer container;

    void SetUp() override {
        MusicaContainer::musicas.clear();   // isola cada teste
    }

    // pequeno helper para nao repetir o construtor de 7 argumentos
    Musica criarMusica(const std::string& nome) {
        return Musica(nome, 200, 2020, "letra", "Pop", "/p.mp3", "Artista");
    }
};

TEST_F(MusicaContainerTest, AdicionarTornaMusicaExistente) {
    container.adicionarMusica(criarMusica("nome_musica1"));

    EXPECT_TRUE(container.existeMusica("nome_musica1"));
    EXPECT_EQ(container.getMusicas().size(), 1u);
}

TEST_F(MusicaContainerTest, ExisteEhFalsoQuandoNaoFoiAdicionada) {
    EXPECT_FALSE(container.existeMusica("nome_musica_inexistente"));
}

TEST_F(MusicaContainerTest, ProcurarDevolveAMusicaCorreta) {
    container.adicionarMusica(criarMusica("nome_musica1"));

    Musica* m = container.procurarMusica("nome_musica1");
    ASSERT_NE(m, nullptr);                 // se for nullptr, nao vale a pena continuar
    EXPECT_EQ(m->getNome(), "nome_musica1");
}

TEST_F(MusicaContainerTest, ProcurarDevolveNullptrSeNaoExiste) {
    EXPECT_EQ(container.procurarMusica("nome_musica_inexistente"), nullptr);
}

TEST_F(MusicaContainerTest, RemoverDevolveTrueEApaga) {
    container.adicionarMusica(criarMusica("nome_musica1"));

    EXPECT_TRUE(container.removerMusica("nome_musica1"));
    EXPECT_FALSE(container.existeMusica("nome_musica1"));
    EXPECT_EQ(container.getMusicas().size(), 0u);
}

TEST_F(MusicaContainerTest, RemoverDevolveFalseSeNaoExiste) {
    EXPECT_FALSE(container.removerMusica("nome_musica_inexistente"));
}

TEST_F(MusicaContainerTest, GetMusicasContaCorretamente) {
    container.adicionarMusica(criarMusica("nome_musica1"));
    container.adicionarMusica(criarMusica("nome_musica2"));
    container.adicionarMusica(criarMusica("nome_musica3"));

    EXPECT_EQ(container.getMusicas().size(), 3u);
}