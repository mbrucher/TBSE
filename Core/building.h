/**
 * \file building.h
 */

#ifndef BUILDING_H
#define BUILDING_H

#include "base_building.h"

namespace TBSE
{
  namespace Core
  {
    class Building
    {
    protected:
      BaseBuilding* base;

      BaseBuilding state;
    };
  }
}

#endif
