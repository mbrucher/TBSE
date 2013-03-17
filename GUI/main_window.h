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
  namespace Core
  {
    class CoreModel;
  }
  namespace GUI
  {
    /**
     * The main window class, transmitting information from the outside world to the GUI created by a plugin
     */
    class MainWindow: public QMainWindow
    {
      Q_OBJECT
      Ui_TBSEMainWindow* ui;
      bool mainDockVisible;

    public:
      MainWindow();

    signals:
      void displayMainDock(bool);
      void setNumberPlayers(unsigned int numberOfPlayers);
      void setCurrentPlayer(unsigned int currentPlayer);
      void changePlayer();

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
      void connectMainView(QWidget* mainView);
      void createCoreModel(const std::string& model);
      void connectCoreModel();

      Core::CoreModel* coreModel;
    };
  }
}

#endif
