/**
 * \file MainWindow.cpp
 */

#include <QKeyEvent>

#include "ui_MainWindow.h"

#include "MainWindow.h"

namespace TGSE
{
  namespace Qt
  {
    MainWindow::MainWindow()
      :mainDockVisible(true)
    {
      ui = new Ui_TGSEMainWindow;
      ui->setupUi(this);
    }

    void MainWindow::keyPressEvent(QKeyEvent* event)
    {
      if(::Qt::Key_Escape == event->key())
      {
        mainDockVisible = !mainDockVisible;
        event->accept();
        emit displayMainDock(mainDockVisible);
      }
    }
  }
}

