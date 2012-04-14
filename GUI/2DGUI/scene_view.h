/**
 * \file scene_view.h
 */

#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <vector>

#include <QGraphicsView>

namespace TBSE
{
  namespace Qt
  {
    class SceneModel;

    /**
     * This class is responsible for displaying one player status
     */
    class SceneView: public QGraphicsView
    {
      Q_OBJECT
    public:
      SceneView(QWidget* parent);

    private:
      std::vector<SceneModel*> models;

    public slots:
      void setNumberPlayers(unsigned int numberOfPlayers);
      void setCurrentPlayer(unsigned int currentPlayer);
    };
  }
}

#endif
