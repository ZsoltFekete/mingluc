#ifndef MINGLUC_TEST_CLASSES_H
#define MINGLUC_TEST_CLASSES_H

#include "mingluc.h"

using mingluc::GluContainer;
using mingluc::Injectable;

class TestClassA : public Injectable {
 public:
  void setDependencies(GluContainer &glu){}
  void init() {}
};

class TestClassB : public Injectable {
 public:
  void setDependencies(GluContainer &glu){}
  void init() {}
};

#endif
