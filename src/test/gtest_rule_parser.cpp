#include "rule_parser.h"

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <exception>

using std::string;
using std::map;
using std::exception;

using mingluc::RuleParser;
using mingluc::MinglucException;

namespace {

class RuleParserTest : public ::testing::Test {
 protected:

  RuleParserTest() {}

  virtual ~RuleParserTest() {}

  // virtual void SetUp() { }
  // virtual void TearDown() { }
};

TEST_F(RuleParserTest, testNonwhiteSpace) {
  ASSERT_EQ(1, 1);
}

TEST_F(RuleParserTest, testEmpty) {
  string ruleString = "";
  RuleParser ruleParser(ruleString);
  ruleParser.run();
  map<string, string> rules = ruleParser.getRules();
  ASSERT_EQ(0, rules.size());
}

TEST_F(RuleParserTest, testOneRule1) {
  string ruleString = "aaa<-bb";
  RuleParser ruleParser(ruleString);
  ruleParser.run();
  map<string, string> rules = ruleParser.getRules();
  ASSERT_EQ(1, rules.size());
  ASSERT_EQ("bb", rules["aaa"]);
}

TEST_F(RuleParserTest, testOneRule2) {
  string ruleString = " aaa  <- bb ";
  RuleParser ruleParser(ruleString);
  ruleParser.run();
  map<string, string> rules = ruleParser.getRules();
  ASSERT_EQ(1, rules.size());
  ASSERT_EQ("bb", rules["aaa"]);
}

TEST_F(RuleParserTest, testTwoRules) {
  string ruleString = " aaa  <- bb , qqq <- xx";
  RuleParser ruleParser(ruleString);
  ruleParser.run();
  map<string, string> rules = ruleParser.getRules();
  ASSERT_EQ(2, rules.size());
  ASSERT_EQ("bb", rules["aaa"]);
  ASSERT_EQ("xx", rules["qqq"]);
}

TEST_F(RuleParserTest, testThreeRules) {
  string ruleString = " aaa  <- bb , qqq <- xx,zz<- v";
  RuleParser ruleParser(ruleString);
  ruleParser.run();
  map<string, string> rules = ruleParser.getRules();
  ASSERT_EQ(3, rules.size());
  ASSERT_EQ("bb", rules["aaa"]);
  ASSERT_EQ("xx", rules["qqq"]);
  ASSERT_EQ("v", rules["zz"]);
}

TEST_F(RuleParserTest, testBadRule1) {
  string ruleString = " aaa  <- bb qqq <- xx,zz<- v";
  RuleParser ruleParser(ruleString);
  try {
    ruleParser.run();
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s\n", e.what());
  }
}

TEST_F(RuleParserTest, testBadRule2) {
  string ruleString = " aaa  < - bb";
  RuleParser ruleParser(ruleString);
  try {
    ruleParser.run();
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s\n", e.what());
  }
}

TEST_F(RuleParserTest, testMultipleRules) {
  string ruleString = " aaa  <- bb, aaa <- qwe";
  RuleParser ruleParser(ruleString);
  try {
    ruleParser.run();
    FAIL();
  } catch (MinglucException &e) {
    fprintf(stderr, "%s\n", e.what());
  }
}

TEST_F(RuleParserTest, testSimplifiedRules) {
  string ruleString = " aaa  <- bb , qqq <- xx, @zz, @cc";
  RuleParser ruleParser(ruleString);
  ruleParser.run();
  map<string, string> rules = ruleParser.getRules();
  ASSERT_EQ(4, rules.size());
  ASSERT_EQ("bb", rules["aaa"]);
  ASSERT_EQ("xx", rules["qqq"]);
  ASSERT_EQ("zz", rules["zz"]);
  ASSERT_EQ("cc", rules["cc"]);
}

TEST_F(RuleParserTest, testBadRule3) {
  string ruleString = "@ aaa  <- bb";
  RuleParser ruleParser(ruleString);
  try {
    ruleParser.run();
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s\n", e.what());
  }
}

TEST_F(RuleParserTest, testBadRule4) {
  string ruleString = "aaa";
  RuleParser ruleParser(ruleString);
  try {
    ruleParser.run();
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s\n", e.what());
  }
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


