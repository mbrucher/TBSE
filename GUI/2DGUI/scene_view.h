/**
 * \file scene_view.h
 */

#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QGraphicsView>

namespace TBSE
{
  namespace Qt
  {
    class SceneView: public QGraphicsView
    {
      Q_OBJECT
    public:
      SceneView(QWidget* parent);
    };
  }
}

#endif
