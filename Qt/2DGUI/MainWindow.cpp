/**
 * \file MainWindow.cpp
 */

#include "ui_MainWindow.h"

#include "MainWindow.h"

namespace TGSE
{
  namespace Qt
  {
    MainWindow::MainWindow()
    {
      ui = new Ui_TGSEMainWindow;
      ui->setupUi(this);
    }
  }
}

