#include <cppunit/extensions/HelperMacros.h>
#include "Piece.h"
#include "PieceTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PieceTest);

void PieceTest::TestColor(void)
{
  cout << endl;
  Roi rb(Color::colorWhite);
  CPPUNIT_ASSERT(rb.isWhite());
}
void PieceTest::TestRoque(void)
{
  cout << endl;
  Roi rb(Color::colorBlack);
  Piece *ptr;
  ptr = (Piece*) &rb;
  //ptr->roque(); interdit
  Roi *rptr = dynamic_cast<Roi *>(ptr);
  CPPUNIT_ASSERT(rptr != nullptr);
  if (rptr != nullptr)
    rptr->roque();
}
