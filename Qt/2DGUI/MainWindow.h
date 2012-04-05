/**
 * \file MainWindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_MainWindow;

namespace TGSE
{
  namespace Qt
  {

    class MainWindow: public QMainWindow
    {
      Ui_MainWindow* ui;
    public:
      MainWindow();
    };
  }
}

#endif

