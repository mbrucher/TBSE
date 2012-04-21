/**
 * \file terrain_element.h
 */

#ifndef TERRAINELEMENT_H
#define TERRAINELEMENT_H

#include <boost/ptr_container/ptr_vector.hpp>

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
      boost::ptr_vector<TerrainModifier> modifiers;
      int type;

    protected:
      /// Adds a modifier at the end of the list of terrain modifiers
      int addModifier(std::auto_ptr<TerrainModifier>& modifier);
    public:
      /// Return the terrain type (water, beach...)
      int getType() const;
      /// Returns a terrain modifier
      TerrainModifier& retrieveModifier(int modifierID);

      static std::auto_ptr<TerrainElement> createTerrainElement();
    };
  }
}

#endif
