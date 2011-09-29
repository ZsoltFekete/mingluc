#include "rule_parser.h"
#include "string_utils.h"

using mingluc::RuleParser;
using mingluc::MinglucException;
using mingluc::StringUtils;

MinglucException::MinglucException(string msg) {
  msg_ = msg;
}

const char* MinglucException::what() const throw() {
  return msg_.c_str();
}

MinglucException::~MinglucException() throw() {}

RuleParser::RuleParser(string rule_string) {
  rule_string_ = rule_string;
}

void RuleParser::run() {
  if ("" == StringUtils::trim(rule_string_)) {
    return;
  }
  vector<string> rule_vector = StringUtils::split(rule_string_, ",");
  for (uint i = 0; i < rule_vector.size(); ++i) {
    processOneRule(rule_vector[i]);
  }
}

void RuleParser::processOneRule(string rule) {
  bool containsArrow = StringUtils::contains(rule, "<-");
  bool containsAt = StringUtils::contains(rule, "@");
  if ((!containsArrow && !containsAt) || (containsArrow && containsAt)) {
    throwIncorrectRuleError(rule);
  }
  if (containsAt) {
    processAtRule(rule);
  }
  if (containsArrow) {
    processArrowRule(rule);
  }
}

void RuleParser::processAtRule(string rule) {
  vector<string> one_rule_vector = StringUtils::split(rule, "@");
  if (2 != one_rule_vector.size()) {
    throwIncorrectRuleError(rule);
  }
  string beforeAt = StringUtils::trim(one_rule_vector[0]);
  string afterAt = StringUtils::trim(one_rule_vector[1]);
  if ("" != beforeAt) {
    throwIncorrectRuleError(rule);
  }
  rules_[afterAt] = afterAt;
}

void RuleParser::processArrowRule(string rule) {
  vector<string> one_rule_vector = StringUtils::split(rule, "<-");
  if (2 != one_rule_vector.size()) {
    throwIncorrectRuleError(rule);
  }
  string rule_key = StringUtils::trim(one_rule_vector[0]);
  string rule_value = StringUtils::trim(one_rule_vector[1]);
  rules_[rule_key] = rule_value;
  if (defined_rule_keys_.end() != defined_rule_keys_.find(rule_key)) {
    string msg = "Rule-key \"" + rule_key +"\" is multiple defined.";
    throw MinglucException(msg);
  }
  defined_rule_keys_.insert(rule_key);
}

void RuleParser::throwIncorrectRuleError(string rule) {
  string msg = "ERROR in GluManager.add: incorrect rule: \"" + rule + "\"";
  throw MinglucException(msg);
}

map<string, string> RuleParser::getRules() {
  return rules_;
}

