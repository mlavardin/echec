#ifndef JOUEURTEST_H
#define JOUEURTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class JoueurTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(JoueurTest);
  CPPUNIT_TEST(TestColor);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}
  void TestColor(void);
};

#endif
