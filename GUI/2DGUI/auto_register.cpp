/**
 * \file auto_register.cpp
 */

#include "../../Core/gui_registry.h"
#include "scene_view.h"

QWidget* create_widgets(QWidget* parent)
{
  QGraphicsView* graphicsView = new TBSE::Qt::SceneView(parent);
  graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

  return graphicsView;
}

TBSEEXPORTGUIPLUGIN(2DGUI, create_widgets);
