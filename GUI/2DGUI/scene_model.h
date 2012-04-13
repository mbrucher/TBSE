/**
 * \file scene_model.h
 */

#ifndef SCENEMODEL_H
#define SCENEMODEL_H

#include <QGraphicsScene>

namespace TBSE
{
  namespace Qt
  {
    class SceneModel: public QGraphicsScene
    {
      Q_OBJECT
    public:
      SceneModel(QObject* parent);
    };
  }
}

#endif
