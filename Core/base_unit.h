/**
 * \file base_unit.h
 */

#ifndef BASEUNIT_H
#define BASEUNIT_H

#include <vector>

#include "weapon.h"

namespace TBSE
{
  namespace Core
  {
    class BaseUnit
    {
    protected:
      std::vector<Weapon> weapons;

      int type;
      int attackRange;
      int health;
      int armor;
      int shield;
      int radarRange;

      int fuel;
      int cargoSize;
    };
  }
}

#endif
