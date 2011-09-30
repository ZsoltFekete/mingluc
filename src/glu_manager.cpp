#include "glu_manager.h"
#include "rule_parser.h"

#include <sys/types.h>

using mingluc::GluManager;
using mingluc::RuleParser;
using mingluc::ObjectDescriptor;
using mingluc::GluContainerImpl;

ObjectDescriptor::ObjectDescriptor(string _name, Injectable *_object,
    map<string, string> _rules) {
  name = _name;
  object = _object;
  rules = _rules;
}

GluContainerImpl::GluContainerImpl(map<string, string> rules,
    map<string, void*> objects, string my_id) {
  rules_ = rules;
  objects_ = objects;
  my_id_ = my_id;
}

void *GluContainerImpl::get(string name) {
  string id;
  if (rules_.end() != rules_.find(name)) {
    id = rules_[name];
    used_rules_.insert(name);
  } else {
    string msg ="ERROR in GluContainer get call for"
        " object with id \"" + my_id_ + "\":there is no rule for name \"" +
        name + "\"";
    throw MinglucException(msg);
  }

  if (objects_.end() != objects_.find(id)) {
    return objects_[id];
  } else {
    string msg = "ERROR in GluContainer get call for"
        " object with id \"" + my_id_ +
        "\": no instances with id \"(" + id + "\"";
    throw MinglucException(msg);
  }
}

void GluManager::add(string name, Injectable *object, string rule_string) {
  ObjectDescriptor objectDescriptor(name, object, parserRules(rule_string));
  objects_.push_back(objectDescriptor);
  name_to_object_[name] = object;
}

map<string, string> GluManager::parserRules(string rule_string) {
  RuleParser ruleParser(rule_string);
  ruleParser.run();
  return ruleParser.getRules();
}

void GluManager::setDependencies() {
  for (uint i = 0; i < objects_.size(); ++i) {
    ObjectDescriptor &objectDescriptor = objects_[i];
    GluContainerImpl gluContainer(objectDescriptor.rules, name_to_object_,
        objectDescriptor.name);
    objectDescriptor.object->setDependencies(gluContainer);
  }
}

void GluManager::init() {
  for (uint i = 0; i < objects_.size(); ++i) {
    ObjectDescriptor &objectDescriptor = objects_[i];
    objectDescriptor.object->init();
  }

}

