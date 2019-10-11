#include <gtest/gtest.h>
#include "Joueur.h"

class JoueurTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
  }

  // void TearDown() override {}

  JoueurBlanc jb;
};

TEST_F(JoueurTest, IsWhite)
{
  EXPECT_EQ(jb.isWhite(), true);
}