/**
 * \file base_building.h
 */

#ifndef BASEBUILDING_H
#define BASEBUILDING_H

#include <vector>

#include "weapon.h"

namespace TBSE
{
  namespace Core
  {
    class BaseBuilding
    {
      std::vector<Weapon> weapons;

      int type;
      int health;
      int armor;
      int shield;
      int radarRange;

      int cargoSize;
    };
  }
}

#endif
