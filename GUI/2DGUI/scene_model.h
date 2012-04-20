/**
 * \file scene_model.h
 */

#ifndef SCENEMODEL_H
#define SCENEMODEL_H

#include <QGraphicsScene>

namespace TBSE
{
  namespace GUI
  {
    /**
     * This class is responsible for storing GUI information for a player
     */
    class SceneModel: public QGraphicsScene
    {
      Q_OBJECT
    public:
      SceneModel(QObject* parent);

    protected:
      void populate_stub();
    };
  }
}

#endif
