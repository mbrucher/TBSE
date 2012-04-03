/**
 * \file main.cpp
 */

#include <QApplication>
#include <QMainWindow>

#include "main.h"

namespace TGSE
{
  namespace Qt
  {
    int main(int& argc, char** argv)
    {
      QApplication app(argc, argv);
      app.setOrganizationName("MB");
      app.setApplicationName("TGSE");
      QMainWindow mainWin;
      mainWin.showMaximized();
      return app.exec();
    }
  }
}
