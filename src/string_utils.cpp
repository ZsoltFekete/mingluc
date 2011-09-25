#include "string_utils.h"

namespace mingluc {

string StringUtils::trim(const string &s) {
  uint firstNonWhiteSpaceIndex = getFirstNonWhiteSpaceIndex(s);
  if (-1 == firstNonWhiteSpaceIndex) {
    return "";
  }
  uint lastNonWhiteSpaceIndex = getLastNonWhiteSpaceIndex(s);
  return s.substr(firstNonWhiteSpaceIndex,
      lastNonWhiteSpaceIndex - firstNonWhiteSpaceIndex + 1);
}

uint StringUtils::getFirstNonWhiteSpaceIndex(const string &s) {
  for (uint i = 0; i < s.size(); ++i) {
    if (!isWhiteSpace(s[i])){
      return i;
    }
  }
  return -1;
}

uint StringUtils::getLastNonWhiteSpaceIndex(const string &s) {
  for (int i = s.size() - 1; i >= 0; --i) {
    if (!isWhiteSpace(s[i])){
      return i;
    }
  }
  return -1;
}

bool StringUtils::isWhiteSpace(char c) {
  return (' ' == c || '\t' == c || '\n' == c);
}

}
