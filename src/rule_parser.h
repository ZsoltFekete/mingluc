#ifndef MINGLUC_RULE_PARSER_H
#define MINGLUC_RULE_PARSER_H

#include <string>
#include <map>
#include <set>
#include <exception>

using std::string;
using std::map;
using std::set;
using std::exception;

namespace mingluc {

class MinglucException : public exception {
 private:
  string msg_;
 public:
  MinglucException(string msg);
  virtual const char* what() const throw();
  virtual ~MinglucException() throw();
};

class RuleParser {
 private:
  string rule_string_;
  map<string, string> rules_;
  set<string> defined_rule_keys_;

 public:
  RuleParser(string rule_string);
  void run();
  map<string, string> getRules();
 private:
  void processOneRule(string rule);
  void processArrowRule(string rule);
  void processAtRule(string rule);
  void throwIncorrectRuleError(string rule);
};

}

#endif
