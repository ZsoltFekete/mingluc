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


vector<string> split(string s, char c){
  vector<string> v;
  size_t i=-1;
  size_t j=0;
  while(string::npos!=j){
    j=s.find_first_of(c,i+1);
    if(string::npos==j){
      v.push_back( s.substr(i+1, s.size()-i-1 ) );
    } else {
      v.push_back( s.substr(i+1, j-i-1) );
    }
    i=j;
  }
  return v;
}



vector<string> StringUtils::split(const string &s, char c){
  vector<string> v;
  if ("" == s) {
    v.push_back("");
    return v;
  }
  size_t prevIndex =-1;
  size_t nextIndex = 0;
  while(string::npos != nextIndex){
    nextIndex = s.find_first_of(c, prevIndex + 1);
    if(string::npos == nextIndex){
      v.push_back(s.substr(prevIndex + nextIndex, s.size() - prevIndex - 1));
    } else {
      v.push_back(s.substr(prevIndex + 1, nextIndex - prevIndex - 1));
    }
    prevIndex = nextIndex;
  }
  return v;
}


}
