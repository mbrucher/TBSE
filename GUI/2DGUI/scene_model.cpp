/**
 * \file scene_model.cpp
 */

#include <iostream>

#include "hexagon_item.h"
#include "scene_model.h"

namespace TBSE
{
  namespace Qt
  {
    SceneModel::SceneModel(QObject* parent)
      :QGraphicsScene(parent)
    {
      setBackgroundBrush(::Qt::black);

      populate_stub();
    }

    void SceneModel::populate_stub()
    {
      addItem(new HexagonItem(QPixmap(":/TBSE/2DGUI/resources/hex_template.png")));
    }
  }
}
