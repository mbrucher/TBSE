/**
 * \file main_window.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_TBSEMainWindow;

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
      void new_game();
      void load_game();
      void save_game();
      void hall_of_fame();
      void options();

    protected:
      void keyPressEvent(QKeyEvent* event);

      void connect_main_doc();
    };
  }
}

#endif

