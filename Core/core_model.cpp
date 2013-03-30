/**
 * \file core_model.cpp
 */

#include "core_model.h"

#include <QtXml/QDomDocument>

#include <Generated/Core/base_map.h>

namespace TBSE
{
  namespace Core
  {
    CoreModel* CoreModel::createModel(const std::string& model)
    {
      QDomDocument doc(QString::fromStdString(model));
      TBSEMap *map = new TBSEMap;
      QDomElement root = doc.documentElement();
      map->unserialize(&root);
      return new CoreModel(map);; // TODO Need to use the XSD generated file
    }
    
    CoreModel::CoreModel(TBSEMap* map)
      :map(map)
    {
      
    }
    
    long CoreModel::height() const
    {
      return map->getMap().size();
    }
    
    long CoreModel::width() const
    {
      return map->getMap()[0].size();
    }

    const TerrainElement* CoreModel::getTerrainElement(unsigned long i, unsigned long j) const
    {
      return &terrain[i + j * width()];
    }

  }
}
