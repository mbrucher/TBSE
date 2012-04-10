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
    public:
      SceneModel(QObject* parent);
    };
  }
}

#endif
