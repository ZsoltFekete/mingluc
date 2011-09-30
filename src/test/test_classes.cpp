#include "test/test_classes.h"

TestClassA::TestClassA(vector<string> *flow) {
  flow_ = flow;
}

void TestClassA::setDependencies(GluContainer &glu){
  flow_->push_back("a_set_dep");
  objectB_ = static_cast<TestClassB*>(glu.get("B"));
}

void TestClassA::init() {
 flow_->push_back("a_init");
}

TestClassB::TestClassB(vector<string> *flow) {
  flow_ = flow;
}

void TestClassB::setDependencies(GluContainer &glu){
  flow_->push_back("b_set_dep");
  objectA1_ = static_cast<TestClassA*>(glu.get("A1"));
  objectA2_ = static_cast<TestClassA*>(glu.get("A2"));
}

void TestClassB::init() {
 flow_->push_back("b_init");
}

