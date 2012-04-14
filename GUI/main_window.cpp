/**
 * \file main_window.cpp
 */

#include <QKeyEvent>
#include <QMessageBox>
#include <QSettings>

#include "ui_main_window.h"
#include "../Core/gui_registry.h"

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

    void MainWindow::createMainView()
    {
      QObject* child;
      Q_FOREACH(child, ui->centralwidget->findChildren<QWidget*>("mainView"))
      {
        delete child;
      }
      GUIRegistry::RegistryFunction fun;
      try
      {
        fun = GUIRegistry::get().getFunction(getGUIKind().toStdString());
      }
      catch(const std::runtime_error& error)
      {
        QMessageBox::warning(this, "TBSE", "no appropriate GUI plugin found");
        exit(1);
      }
      ui->gridLayout->addWidget((*fun)(ui->centralwidget), 0, 0, 1, 1);
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
      createMainView();
    }

    void MainWindow::loadGame()
    {
      createMainView();
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
      return settings.value("GUIPlugin", "2DGUI").toString();
    }
  }
}

