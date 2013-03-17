/**
 * \file unit.h
 */

#ifndef UNIT_H
#define UNIT_H

#include "base_unit.h"

namespace TBSE
{
  namespace Core
  {
    class Unit
    {
      BaseUnit* base;

      BaseUnit state;

      std::vector<Unit*> cargo;
    };
  }
}

#endif
