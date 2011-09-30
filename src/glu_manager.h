#ifndef MINGLUC_GLU_MANAGER_H
#define MINGLUC_GLU_MANAGER_H

#include <string>
#include <vector>
#include <map>
#include <set>

#include "injectable.h"

using std::string;
using std::vector;
using std::map;
using std::set;

namespace mingluc {

struct ObjectDescriptor {
  string name;
  Injectable *object;
  map<string, string> rules;
  ObjectDescriptor(string _name, Injectable *_object,
    map<string, string> _rules);
};

class GluContainerImpl : public GluContainer {
 private:
  map<string, string> rules_;
  map<string, void*> objects_;
  string my_id_;

  set<string> used_rules_;

 public:
  GluContainerImpl(map<string, string> rules, map<string, void*> objects,
    string my_id);

  void *get(string s); 
};

class GluManager {
 private:
  vector<ObjectDescriptor> objects_;
  map<string, void*> name_to_object_;
 public:
  void add(string name, Injectable *object, string rule_string);
  void setDependencies();
  void init();
 private:
  map<string, string> parserRules(string rule_string);
};

}

#endif
