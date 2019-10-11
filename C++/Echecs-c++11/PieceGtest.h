#include <gtest/gtest.h>
#include "Piece.h"

class PieceTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    ptr = new Roi(Color::colorWhite);
  }

  void TearDown() override
  {
    delete ptr;
  }

  Piece *ptr;
};

TEST_F(PieceTest, IsWhite)
{
  EXPECT_EQ(ptr->isWhite(), true);
}

TEST_F(PieceTest, Roque)
{
  Roi *rptr = dynamic_cast<Roi *>(ptr);
  EXPECT_NE(rptr, nullptr);
  // rptr->roque();
}