#ifndef MINGLUC_GLU_CONTAINER_H
#define MINGLUC_GLU_CONTAINER_H

#include <string>

using std::string;

namespace mingluc {

class GluContainer {
 public:
  virtual void* get(string id) = 0;
};

}

#endif
