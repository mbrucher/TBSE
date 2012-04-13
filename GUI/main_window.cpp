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
      connect_main_dock();
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

    void MainWindow::new_game()
    {
    }

    void MainWindow::load_game()
    {
    }

    void MainWindow::save_game()
    {
    }

    void MainWindow::hall_of_fame()
    {
    }

    void MainWindow::options()
    {
    }

    void MainWindow::connect_main_dock()
    {
      QObject::connect(ui->newButton, SIGNAL(clicked()), this, SLOT(new_game()));
      QObject::connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(load_game()));
      QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save_game()));
      QObject::connect(ui->hofButton, SIGNAL(clicked()), this, SLOT(hall_of_fame()));
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
  }
}

