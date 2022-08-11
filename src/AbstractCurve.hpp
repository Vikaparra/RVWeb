#include "Dimension.hpp"
#include <cmath>

#ifndef RVWEB_ABSTRACTCURVE_H
#define RVWEB_ABSTRACTCURVE_H

class AbstractCurve {
protected:
  int numberOfElements;

public:
  int getNumberOfElements() { return this->numberOfElements; }
};

#endif
