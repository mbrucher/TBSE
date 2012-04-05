/**
 * \file main.cpp
 */

#include <QApplication>
#include <QFile>

#include "MainWindow.h"

#include "main.h"

static void __for_qt_namespace_issues()
{
  Q_INIT_RESOURCE(resources);
}

namespace TGSE
{
  namespace Qt
  {
    int main(int& argc, char** argv)
    {
      QApplication app(argc, argv);
      app.setOrganizationName("MB");
      app.setApplicationName("TGSE");

      __for_qt_namespace_issues();

      QFile file(":/TGSE/resources/coffee.qss");
      file.open(QFile::ReadOnly);
      QString styleSheet = QLatin1String(file.readAll());
      app.setStyleSheet(styleSheet);

      MainWindow mainWin;
      mainWin.showMaximized();
      return app.exec();
    }
  }
}
