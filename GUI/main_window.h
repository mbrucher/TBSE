/**
 * \file main_window.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_TBSEMainWindow;
class QGraphicsScene;

namespace TBSE
{
  namespace Qt
  {
    class MainWindow: public QMainWindow
    {
      Q_OBJECT
      Ui_TBSEMainWindow* ui;
      bool mainDockVisible;

    public:
      MainWindow();

    signals:
      void displayMainDock(bool);

    public slots:
      void newGame();
      void loadGame();
      void saveGame();
      void hallOfFame();
      void options();

    protected:
      void keyPressEvent(QKeyEvent* event);
      void closeEvent(QCloseEvent *event);
      void readSettings();

      void connectMainDock();
      QString getGUIKind();
      void createMainView();
    };
  }
}

#endif

