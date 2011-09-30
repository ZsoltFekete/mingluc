#include "mingluc.h"
#include "test/test_classes.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

using mingluc::GluManager;
using mingluc::MinglucException;

namespace {

class GluManagerTest : public ::testing::Test {
 protected:

  GluManagerTest() {}

  virtual ~GluManagerTest() {}

  // virtual void SetUp() { }
  // virtual void TearDown() { }
};


TEST_F(GluManagerTest, test) {
  vector<string> flow;
  TestClassA *a1 = new TestClassA(&flow);
  TestClassA *a2 = new TestClassA(&flow);
  TestClassB *b = new TestClassB(&flow);
 
  GluManager mingluc;
  mingluc.add("a1", a1, "B <- b");
  mingluc.add("a2", a2, "B<- b");
  mingluc.add("b", b, "A1 <- a1, A2 <- a2");
  mingluc.setDependencies();
  mingluc.init();

  ASSERT_EQ(6, flow.size());
  ASSERT_EQ("a_set_dep", flow[0]);
  ASSERT_EQ("a_set_dep", flow[1]);
  ASSERT_EQ("b_set_dep", flow[2]);
  ASSERT_EQ("a_init", flow[3]);
  ASSERT_EQ("a_init", flow[4]);
  ASSERT_EQ("b_init", flow[5]);
  ASSERT_EQ(a1, b->objectA1_);
  ASSERT_EQ(a2, b->objectA2_);
  ASSERT_EQ(b, a1->objectB_);
  ASSERT_EQ(b, a2->objectB_);

  delete a1;
  delete a2;
  delete b;
}


TEST_F(GluManagerTest, testIncompleteRule) {
  vector<string> flow;
  TestClassA *a1 = new TestClassA(&flow);
  TestClassA *a2 = new TestClassA(&flow);
  TestClassB *b = new TestClassB(&flow);
 
  GluManager mingluc;
  mingluc.add("a1", a1, "B <- b");
  mingluc.add("a2", a2, "B<- b");
  mingluc.add("b", b, "A1 <- a1");
  try {
    mingluc.setDependencies();
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s", e.what());
  }
  delete a1;
  delete a2;
  delete b;
}

TEST_F(GluManagerTest, testTooManyRule) {
  vector<string> flow;
  TestClassA *a1 = new TestClassA(&flow);
  TestClassA *a2 = new TestClassA(&flow);
  TestClassB *b = new TestClassB(&flow);
 
  GluManager mingluc;
  mingluc.add("a1", a1, "B <- b");
  mingluc.add("a2", a2, "B<- b");
  mingluc.add("b", b, "A1 <- a1, A2<- a2, A3 <-a1");
  try {
    mingluc.setDependencies();
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s", e.what());
  }
  delete a1;
  delete a2;
  delete b;
}

TEST_F(GluManagerTest, testMultipleRules) {
  vector<string> flow;
  TestClassA *a1 = new TestClassA(&flow);
  TestClassA *a2 = new TestClassA(&flow);
  TestClassB *b = new TestClassB(&flow);
 
  GluManager mingluc;
  mingluc.add("a1", a1, "B <- b");
  mingluc.add("a2", a2, "B<- b");
  try {
    mingluc.add("b", b, "A1 <- a1, A2<- a2, A1 <-a1");
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s", e.what());
  }
  delete a1;
  delete a2;
  delete b;
}

TEST_F(GluManagerTest, testMultipleRegistrations) {
  vector<string> flow;
  TestClassA *a1 = new TestClassA(&flow);
 
  GluManager mingluc;
  mingluc.add("a1", a1, "B <- b");
  try {
    mingluc.add("a1", a1, "B <- b");
    FAIL();
  } catch (MinglucException e) {
    fprintf(stderr, "%s", e.what());
  }
  delete a1;
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


