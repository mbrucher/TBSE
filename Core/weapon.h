/**
 * \file weapon.h
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <vector>

namespace TBSE
{
  namespace Core
  {
    class WeaponCapability
    {
    protected:
      int unitType;
      int piercingModifier;
    };

    class Weapon
    {
    protected:
      int ammunition;
      int strength;
      int range;

      std::vector<WeaponCapability> capabilities;
    };
  }
}

#endif
