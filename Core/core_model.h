/**
 * \file core_model.h
 */

#ifndef COREMODEL_H
#define COREMODEL_H

#include <string>

#include <QObject>

#include <boost/ptr_container/ptr_vector.hpp>

#include "core_model.h"
//#include "core_view.h"
#include "iplayer.h"
#include "terrain_element.h"
#include "TBSE_Core_config.h"

struct TBSEMap;

namespace TBSE
{
  namespace Core
  {
    class CoreModel: public QObject
    {
      Q_OBJECT

      boost::ptr_vector<TerrainElement> terrain;
      boost::ptr_vector<IPlayer> players;
      //boost::ptr_vector<CoreView> views;
      TBSEMap* map;
      
      CoreModel(TBSEMap* map);
    public:
      static TBSE_Core_EXPORT CoreModel* createModel(const std::string& model);
      
      long width() const;
      long height() const;
      
      const TerrainElement* getTerrainElement(unsigned long i, unsigned long j) const;
    };
  }
}

#endif
