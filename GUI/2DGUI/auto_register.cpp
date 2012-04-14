/**
 * \file auto_register.cpp
 */

#include <qgraphicsview.h>

#include "../../Core/gui_registry.h"

QWidget* create_widgets(QWidget* parent)
{
  QGraphicsView* graphicsView = new QGraphicsView(parent);
  graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

  return graphicsView;
}

TBSEEXPORTGUIPLUGIN(2DGUI, create_widgets);
