/**
 * \file MainWindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_TGSEMainWindow;

namespace TGSE
{
  namespace Qt
  {
    class MainWindow: public QMainWindow
    {
      Q_OBJECT
      Ui_TGSEMainWindow* ui;
    public:
      MainWindow();

    signals:
      void displayMainDock(bool);
    };
  }
}

#endif

