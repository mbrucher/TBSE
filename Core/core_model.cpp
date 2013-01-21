/**
 * \file core_model.cpp
 */

#include "core_model.h"

namespace TBSE
{
  namespace Core
  {
    CoreModel* CoreModel::createModel(const std::string& model)
    {
      return new CoreModel;
    }
  }
}
