/**
 * \file registry.h
 */

#ifndef REGISTRY_H
#define REGISTRY_H

#include "TGSE_Core_config.h"

namespace TGSE
{
  class Registry
  {
  public:
    TGSE_Core_EXPORT static Registry& get();
  };
}

#endif
