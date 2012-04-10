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
      QGraphicsRectItem *rect = addRect(QRectF(0, 0, 100, 100));
    }
  }
}
