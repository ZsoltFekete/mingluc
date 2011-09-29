#include "mingluc.h"
#include "test/test_classes.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

//using mingluc::StringUtils;

namespace {

class GluManagerTest : public ::testing::Test {
 protected:

  GluManagerTest() {}

  virtual ~GluManagerTest() {}

  // virtual void SetUp() { }
  // virtual void TearDown() { }
};


TEST_F(GluManagerTest, test) {
  TestClassA *objectA = new TestClassA();
  TestClassB *objectB = new TestClassB();
  string s = "alma";
  EXPECT_EQ("alma", s);
}



}

