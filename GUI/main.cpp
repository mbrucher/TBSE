/**
 * \file main.cpp
 */

#include <QApplication>
#include <QFile>

#include "../TBSE_config.h"
#include "main_window.h"

#include "main.h"

static void __for_qt_namespace_issues()
{
  Q_INIT_RESOURCE(resources);
}

namespace TBSE
{
  namespace GUI
  {
    int main(int& argc, char** argv)
    {
      QApplication app(argc, argv);
      app.setOrganizationName(ORGANISATIONNAME);
      app.setApplicationName(APPLICATIONNAME);

      __for_qt_namespace_issues();

      QFile file(":/TBSE/resources/coffee.qss");
      file.open(QFile::ReadOnly);
      QString styleSheet = QLatin1String(file.readAll());
      app.setStyleSheet(styleSheet);

      MainWindow mainWin;
      mainWin.showFullScreen();
      return app.exec();
    }
  }
}
