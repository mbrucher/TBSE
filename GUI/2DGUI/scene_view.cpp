/**
 * \file scene_view.cpp
 */

#include <iostream>

#include <qglobal.h>

#include "scene_model.h"
#include "scene_view.h"

static void __for_qt_namespace_issues()
{
  Q_INIT_RESOURCE(resources_2dgui);
}

namespace TBSE
{
  namespace Qt
  {
    SceneView::SceneView(QWidget* parent)
      :QGraphicsView(parent)
    {
      __for_qt_namespace_issues();
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
