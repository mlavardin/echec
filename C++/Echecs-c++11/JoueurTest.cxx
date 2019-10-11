#include <cppunit/extensions/HelperMacros.h>
#include "Joueur.h"
#include "JoueurTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(JoueurTest);

void JoueurTest::TestColor(void)
{
  cout << endl;
  JoueurNoir jn;
  CPPUNIT_ASSERT_ASSERTION_FAIL(CPPUNIT_ASSERT(jn.isWhite()));
}
