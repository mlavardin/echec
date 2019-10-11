#ifndef ECHIQUIERTEST_H
#define ECHIQUIERTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class EchiquierTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(EchiquierTest);
  CPPUNIT_TEST(TestPlacer);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}
  void TestPlacer(void);
};

#endif
