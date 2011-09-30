#ifndef MINGLUC_GLU_MANAGER_H
#define MINGLUC_GLU_MANAGER_H

#include <string>

using std::string;

namespace mingluc {

class GluManager {
 public:
  void add(string name, void *object, string rule_string);
  void setDependencies();
  void init();
};

}

#endif
