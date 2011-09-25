#include "string_utils.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

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

TEST_F(StringUtilTest, testLeftRightSpacesTabsEndlines) {
  string s = " \t \n al  ma\n \t\t\n\n \n \t   \n";
  EXPECT_EQ("al  ma", StringUtils::trim(s));
}

TEST_F(StringUtilTest, testSplit) {
  string s = ",,123,qwe,,asd,,yxc,";
  vector<string> v = StringUtils::split(s, ",");
  EXPECT_EQ(9, v.size());
  EXPECT_EQ("", v[0]);
  EXPECT_EQ("", v[1]);
  EXPECT_EQ("123", v[2]);
  EXPECT_EQ("qwe", v[3]);
  EXPECT_EQ("", v[4]);
  EXPECT_EQ("asd", v[5]);
  EXPECT_EQ("", v[6]);
  EXPECT_EQ("yxc", v[7]);
  EXPECT_EQ("", v[8]);
}

TEST_F(StringUtilTest, testSplitTwoChars) {
  string s = ",=,=123,=qw=e,=,=as.d,=,=yx=.c,=";
  vector<string> v = StringUtils::split(s, ",=");
  EXPECT_EQ(9, v.size());
  EXPECT_EQ("", v[0]);
  EXPECT_EQ("", v[1]);
  EXPECT_EQ("123", v[2]);
  EXPECT_EQ("qw=e", v[3]);
  EXPECT_EQ("", v[4]);
  EXPECT_EQ("as.d", v[5]);
  EXPECT_EQ("", v[6]);
  EXPECT_EQ("yx=.c", v[7]);
  EXPECT_EQ("", v[8]);
}

TEST_F(StringUtilTest, testSplitEmpty) {
  string s = "";
  vector<string> v = StringUtils::split(s, ",");
  EXPECT_EQ(1, v.size());
  EXPECT_EQ("", v[0]);
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


