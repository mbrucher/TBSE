/**
 * \file terrain_element.h
 */

#ifndef TERRAINELEMENT_H
#define TERRAINELEMENT_H

#include <boost/ptr_container/ptr_list.hpp>

#include "terrain_modifier.h"

namespace TBSE
{
  namespace Core
  {
    /**
     * A base terrain element that contains what an hex contains and what modifiers are present and can be applied to the terrain
     */
    class TerrainElement
    {
      boost::ptr_list<TerrainModifier> modifiers;
      int type;

    public:
      int addModifier(std::unique_ptr<TerrainModifier>& modifier);
      std::unique_ptr<TerrainModifier> removeModifier(int modifierID);
      TerrainModifier* retrieveModifier(int modifierID);
      /// Return the terrain type (water, beach...)
      int getType() const;
    };
  }
}

#endif
