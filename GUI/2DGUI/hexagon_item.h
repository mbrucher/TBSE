/**
 * \file hexagon_item.h
 */

#ifndef HEXAGONITEM_H
#define HEXAGONITEM_H

#include <QGraphicsPixmapItem>

namespace TBSE
{
  namespace GUI
  {
    class HexagonItem: public QGraphicsPixmapItem
    {
    public:
      HexagonItem(const QPixmap& pixmap)
      :QGraphicsPixmapItem(pixmap)
      {
      }
    };
  }
}

#endif
