/**
 * \file terrain_element.cpp
 */

#include "terrain_element.h"

namespace TBSE
{
  namespace Core
  {
    std::auto_ptr<TerrainElement> TerrainElement::createTerrainElement()
    {
      return std::auto_ptr<TerrainElement>(new TerrainElement);
    }

    int TerrainElement::addModifier(std::auto_ptr<TerrainModifier>& modifier)
    {
      modifiers.push_back(modifier);
      return modifiers.size() - 1;
    }

    TerrainModifier& TerrainElement::retrieveModifier(int modifierID)
    {
      return modifiers[modifierID];
    }

    /// Return the terrain type (water, beach...)
    int TerrainElement::getType() const
    {
      return type;
    }
  }
}
