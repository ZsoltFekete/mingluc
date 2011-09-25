#ifndef MINGLUC_STRING_UTILS_H
#define MINGLUC_STRING_UTILS_H

#include <string>
#include <sys/types.h>

using std::string;

namespace mingluc {

class StringUtils {
 public:
  static string trim(const string &s);

  static uint getFirstNonWhiteSpaceIndex(const string &s);

  static uint getLastNonWhiteSpaceIndex(const string &s);

  static bool isWhiteSpace(char c);
};

}

#endif

