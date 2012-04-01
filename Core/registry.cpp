/**
 * \file registry.cpp
 */

#include "registry.h"

namespace TGSE
{
  Registry& Registry::get()
  {
    static Registry registry;
    return registry;
  }
}
