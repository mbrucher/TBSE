/**
 * \file core_model.cpp
 */

#include "core_model.h"

namespace TBSE
{
  namespace Core
  {
    CoreModel* CoreModel::createModel(const std::string& model)
    {
      return new CoreModel; // TODO Need to use the XSD generated file
    }
    
    unsigned long CoreModel::getHeight() const
    {
      return height;
    }
    
    unsigned long CoreModel::getWidth() const
    {
      return width;
    }

    const TerrainElement* CoreModel::getTerrainElement(unsigned long i, unsigned long j) const
    {
      return &terrain[i + j * width];
    }

  }
}
