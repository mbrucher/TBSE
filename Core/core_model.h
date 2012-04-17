/**
 * \file core_model.h
 */

#ifndef COREMODEL_H
#define COREMODEL_H

#include <boost/ptr_container/ptr_vector.hpp>

#include "iplayer.h"
#include "terrain_element.h"
#include "TBSE_Core_config.h"

namespace TBSE
{
  namespace Core
  {
    class CoreModel
    {
      boost::ptr_vector<TerrainElement> terrain;
      boost::ptr_vector<IPlayer> players;
    public:
      static TBSE_Core_EXPORT CoreModel* createModel();
    };
  }
}

#endif
