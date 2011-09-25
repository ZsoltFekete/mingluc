#include "string_utils.h"

#include <gtest/gtest.h>

#include <string>

using std::string;
using mingluc::StringUtils;

namespace {

class StringUtilTest : public ::testing::Test {
 protected:

  StringUtilTest() {}

  virtual ~StringUtilTest() {}

  // virtual void SetUp() { }
  // virtual void TearDown() { }
};

TEST_F(StringUtilTest, testNonwhiteSpace) {
  string s = "alma";
  EXPECT_EQ("alma", StringUtils::trim(s));
}

TEST_F(StringUtilTest, testLeftSpaces) {
  string s = "  alma";
  EXPECT_EQ("alma", StringUtils::trim(s));
}

TEST_F(StringUtilTest, testRightSpaces) {
  string s = "alma     ";
  EXPECT_EQ("alma", StringUtils::trim(s));
}

TEST_F(StringUtilTest, testLeftRightSpaces) {
  string s = "  alma     ";
  EXPECT_EQ("alma", StringUtils::trim(s));
}

TEST_F(StringUtilTest, testAllSpaces) {
  string s = "     ";
  EXPECT_EQ("", StringUtils::trim(s));
}

TEST_F(StringUtilTest, testLeftRightSpacesTAbsEndlines) {
  string s = " \t \n al  ma\n \t\t\n\n \n \t   \n";
  EXPECT_EQ("al  ma", StringUtils::trim(s));
}


}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


