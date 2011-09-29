#ifndef MINGLUC_INJECTABLE_H
#define MINGLUC_INJECTABLE_H

#include "glu_container.h"

namespace mingluc {

class Injectable {
 public:
  virtual void setDependencies(GluContainer &glu) = 0;
  virtual void init() = 0;
};

}

#endif

