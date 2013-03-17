/**
 * \file core_model.h
 */

#ifndef COREMODEL_H
#define COREMODEL_H

#include <string>

#include <QObject>

#include <boost/ptr_container/ptr_vector.hpp>

#include "iplayer.h"
#include "terrain_element.h"
#include "TBSE_Core_config.h"

namespace TBSE
{
  namespace Core
  {
    class CoreModel: public QObject
    {
      Q_OBJECT

      boost::ptr_vector<TerrainElement> terrain;
      boost::ptr_vector<IPlayer> players;
      
      unsigned long width;
      unsigned long height;
    public:
      static TBSE_Core_EXPORT CoreModel* createModel(const std::string& model);
      
      unsigned long getWidth() const;
      unsigned long getHeight() const;
      
      const TerrainElement* getTerrainElement(unsigned long i, unsigned long j) const;
    };
  }
}

#endif
