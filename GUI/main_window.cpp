/**
 * \file main_window.cpp
 */

#include <QKeyEvent>
#include <QSettings>

#include "ui_main_window.h"

#include "main_window.h"

namespace TBSE
{
  namespace Qt
  {
    MainWindow::MainWindow()
      :mainDockVisible(true)
    {
      ui = new Ui_TBSEMainWindow;
      ui->setupUi(this);
      connectMainDock();
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

    void MainWindow::newGame()
    {
    }

    void MainWindow::loadGame()
    {
    }

    void MainWindow::saveGame()
    {
    }

    void MainWindow::hallOfFame()
    {
    }

    void MainWindow::options()
    {
    }

    void MainWindow::connectMainDock()
    {
      QObject::connect(ui->newButton, SIGNAL(clicked()), this, SLOT(newGame()));
      QObject::connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadGame()));
      QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveGame()));
      QObject::connect(ui->hofButton, SIGNAL(clicked()), this, SLOT(hallOfFame()));
      QObject::connect(ui->optionsButton, SIGNAL(clicked()), this, SLOT(options()));
    }

    void MainWindow::closeEvent(QCloseEvent *event)
    {
      QSettings settings;
      settings.setValue("geometry", saveGeometry());
      settings.setValue("windowState", saveState());
      QMainWindow::closeEvent(event);
    }

    void MainWindow::readSettings()
    {
      QSettings settings;
      restoreGeometry(settings.value("geometry").toByteArray());
      restoreState(settings.value("windowState").toByteArray());
    }

    QString MainWindow::getGUIKind()
    {
      QSettings settings;
      return settings.value("GUIPlugin").toString();
    }
  }
}

