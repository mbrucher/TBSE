/**
 * \file scene_model.cpp
 */

#include <iostream>

#include "hexagon_item.h"
#include "scene_model.h"

namespace TBSE
{
  namespace GUI
  {
    /**
     * Loads a pixmap if it exists, returns the default 32x32 hex pixmap if failed
     */
    QPixmap loadPixmap(const QString& filename);
    /**
     * Creates a new HexagonItem based on a pixmap filename
     */
    HexagonItem* createItem(const QString& filename);

    SceneModel::SceneModel(QObject* parent)
      :QGraphicsScene(parent)
    {
      setBackgroundBrush(::Qt::black);
      populate_stub(); // TODO Need to access the core model elements
    }

    void SceneModel::populate_stub()
    {
      for(int i = 0; i < 10; ++i)
      {
        for(int j = 0; j < 10; ++j)
        {
          QGraphicsItem* item = createItem("");
          item->setPos((i / 2) * 48 + (i % 2) * 24, j * 32 + (i % 2) * 16);
          addItem(item);
        }
      }
    }

    QPixmap loadPixmap(const QString& filename)
    {
      static const QPixmap defaultHexPixmap(":/TBSE/2DGUI/resources/hex_template.png");
      QPixmap pixmap(filename);
      if(!pixmap)
      {
        return defaultHexPixmap;
      }
      return pixmap;
    }

    HexagonItem* createItem(const QString& filename)
    {
      return new HexagonItem(loadPixmap(filename));
    }
  }
}
