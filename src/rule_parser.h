#ifndef MINGLUC_RULE_PARSER_H
#define MINGLUC_RULE_PARSER_H

#include <string>
#include <map>
#include <exception>

using std::string;
using std::map;
using std::exception;

namespace mingluc {

class MultipleRulesException : public exception {

};

class RuleParser {
 private:
  string rule_string_;
 public:
  RuleParser(string rule_string);
  void run();
  map<string, string> getRules();
};

}

#endif
