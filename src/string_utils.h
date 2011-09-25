#ifndef MINGLUC_STRING_UTILS_H
#define MINGLUC_STRING_UTILS_H

#include <string>
#include <vector>
#include <sys/types.h>

using std::string;
using std::vector;

namespace mingluc {

class StringUtils {
 public:
  static string trim(const string &s);

  static int getFirstNonWhiteSpaceIndex(const string &s);

  static int getLastNonWhiteSpaceIndex(const string &s);

  static bool isWhiteSpace(char c);

  static vector<string> split(const string &s, char c);
};

}

#endif

