/**
 * \file scene_view.cpp
 */

#include <iostream>

#include <qglobal.h>

#include "scene_model.h"
#include "scene_view.h"

namespace TBSE
{
  namespace Qt
  {
    SceneView::SceneView(QWidget* parent)
      :QGraphicsView(parent)
    {
    }

    void SceneView::setNumberPlayers(unsigned int numberOfPlayers)
    {
      SceneModel* model;
      Q_FOREACH(model, models)
      {
        delete model;
      }
      models.clear();
      for(unsigned int i = 0; i < numberOfPlayers; ++i)
      {
        models.push_back(new SceneModel(this));
      }
    }

    void SceneView::setCurrentPlayer(unsigned int currentPlayer)
    {
      Q_ASSERT(currentPlayer < models.size());
      setScene(models[currentPlayer]);
    }
  }
}
