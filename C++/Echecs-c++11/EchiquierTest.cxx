#include <cppunit/extensions/HelperMacros.h>
#include "Joueur.h"
#include "Echiquier.h"
#include "EchiquierTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EchiquierTest);

void EchiquierTest::TestPlacer(void)
{
  cout << endl;
  JoueurBlanc jb;
  JoueurNoir jn;
  Echiquier e;
  jb.placerPieces(e);
  jn.placerPieces(e);
  Coordinate c(4, 1);
  CPPUNIT_ASSERT(e.getPiece(c)->getChar() == 'Q');
}
