#include "string_utils.h"

namespace mingluc {

string StringUtils::trim(const string &s) {
  int firstNonWhiteSpaceIndex = getFirstNonWhiteSpaceIndex(s);
  if (-1 == firstNonWhiteSpaceIndex) {
    return "";
  }
  int lastNonWhiteSpaceIndex = getLastNonWhiteSpaceIndex(s);
  return s.substr(firstNonWhiteSpaceIndex,
      lastNonWhiteSpaceIndex - firstNonWhiteSpaceIndex + 1);
}

int StringUtils::getFirstNonWhiteSpaceIndex(const string &s) {
  for (uint i = 0; i < s.size(); ++i) {
    if (!isWhiteSpace(s[i])){
      return i;
    }
  }
  return -1;
}

int StringUtils::getLastNonWhiteSpaceIndex(const string &s) {
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

vector<string> StringUtils::split(const string &s, const string &separator) {
  vector<string> v;
  if ("" == s) {
    v.push_back("");
    return v;
  }
  int sep_length = separator.size();
  size_t prevIndex = -sep_length;
  size_t nextIndex = 0;
  while(string::npos != nextIndex){
    nextIndex = s.find(separator, prevIndex + sep_length);
    if(string::npos == nextIndex){
      v.push_back(s.substr(prevIndex + sep_length,
            s.size() - prevIndex - sep_length));
    } else {
      v.push_back(s.substr(prevIndex + sep_length,
            nextIndex - prevIndex - sep_length));
    }
    prevIndex = nextIndex;
  }
  return v;
}


}
