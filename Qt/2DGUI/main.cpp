/**
 * \file main.cpp
 */

#include <QApplication>
#include <QFile>
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

      QFile file(":/TGSE/qss/coffee.qss");
      file.open(QFile::ReadOnly);
      QString styleSheet = QLatin1String(file.readAll());
      app.setStyleSheet(styleSheet);

      QMainWindow mainWin;
      mainWin.showMaximized();
      return app.exec();
    }
  }
}
