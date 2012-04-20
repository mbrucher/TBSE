/**
 * \file core_model.cpp
 */

#include "core_model.h"

namespace TBSE
{
  namespace Core
  {
    CoreModel* CoreModel::createModel()
    {
      return new CoreModel;
    }
  }
}
