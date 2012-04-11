/**
 * \file scene_model.cpp
 */

#include <iostream>

#include "scene_model.h"

namespace TBSE
{
  namespace Qt
  {
    SceneModel::SceneModel(QObject* parent)
      :QGraphicsScene(parent)
    {
      setBackgroundBrush(::Qt::black);
    }
  }
}
