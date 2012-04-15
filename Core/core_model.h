/**
 * \file core_model.h
 */

#ifndef COREMODEL_H
#define COREMODEL_H

#include "TBSE_Core_config.h"

namespace TBSE
{
  namespace Core
  {
    class CoreModel
    {
    public:
      static TBSE_Core_EXPORT CoreModel* createModel();
    };
  }
}

#endif
