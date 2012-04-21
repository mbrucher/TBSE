/**
 * \file iplayer.h
 */

#ifndef IPLAYER_H
#define IPLAYER_H

#include <boost/ptr_container/ptr_list.hpp>

#include "building.h"
#include "unit.h"

namespace TBSE
{
  namespace Core
  {
    /**
     * The base interface class for a player
     * This class must be subclassed to implement a player (AI, human, network...)
     */
    class IPlayer
    {
      boost::ptr_list<Building> building;
      boost::ptr_list<Unit> units;
    };
  }
}

#endif
