#include <gtest/gtest.h>
#include "Echiquier.h"
#include "Joueur.h"

class EchiquierTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        e.affiche();
    }

    // void TearDown() override {}

    Echiquier e;
};

TEST_F(EchiquierTest, placerPieces)
{
    JoueurBlanc jb;
    JoueurNoir jn;
    jb.placerPieces(e);
    jn.placerPieces(e);
    Coordinate c(4, 1);
    EXPECT_EQ(e.getPiece(c)->getChar(), 'Q');
    e.affiche();
}
