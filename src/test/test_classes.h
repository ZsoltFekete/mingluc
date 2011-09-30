#ifndef MINGLUC_TEST_CLASSES_H
#define MINGLUC_TEST_CLASSES_H

#include <vector>
#include "mingluc.h"

using std::vector;
using mingluc::GluContainer;
using mingluc::Injectable;

class TestClassB;

class TestClassA : public Injectable {
 private:
  vector<string> *flow_;
 public:
  TestClassA(vector<string> *flow);
  void setDependencies(GluContainer &glu);
  void init();
  TestClassB *objectB_;
};

class TestClassB : public Injectable {
 private:
  vector<string> *flow_;
 public:
  TestClassB(vector<string> *flow);
  void setDependencies(GluContainer &glu);
  void init();
  TestClassA *objectA1_;
  TestClassA *objectA2_;
};

#endif
