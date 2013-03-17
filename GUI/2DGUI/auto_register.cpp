/**
 * \file auto_register.cpp
 */

#include "../../Core/gui_registry.h"
#include "scene_view.h"

/// The 2D GUI plugin builder function
QWidget* create_widgets(QWidget* parent)
{
  QGraphicsView* graphicsView = new TBSE::GUI::SceneView(parent);
  graphicsView->setObjectName(QString::fromUtf8("mainView"));

  return graphicsView;
}

/// The loader instance that will register the builder function
TBSEEXPORTGUIPLUGIN(2DGUI, create_widgets);
