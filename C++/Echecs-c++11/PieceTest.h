#ifndef PIECETEST_H
#define PIECETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class PieceTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(PieceTest);
  CPPUNIT_TEST(TestColor);
  CPPUNIT_TEST(TestRoque);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}
  void TestColor(void);
  void TestRoque(void);
};

#endif
