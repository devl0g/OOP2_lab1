#include "mainwindow.hpp"
#include "../popups/textEnter.hpp"
#include "../../utils/logger.hpp"
#include <qwidget.h>
#include <QtWidgets/QMenu>
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) noexcept
  : QMainWindow(parent)
{
  setWindowTitle(tr("Lab No.1"));

  implementMenuBar();
}

void MainWindow::implementMenuBar() noexcept {
  auto workMenuSection = menuBar()->addMenu(tr("&Робота"));

  auto work1Action = workMenuSection->addAction(tr("&Робота1"));
  auto work2Action = workMenuSection->addAction(tr("&Робота2"));
  auto exitAction = workMenuSection->addAction(tr("&Вийти"));

  QObject::connect(work1Action, SIGNAL(triggered(bool)), this, SLOT(openTextEnterDialog()));
  QObject::connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));
}

void MainWindow::openTextEnterDialog() {
  TextEnterPopup popup(this);
  Logger::info("popup opening");
  popup.exec(); // Blocks execution, so TextEnterPopup doesn't disallocate too early
}

void MainWindow::exit() {
  Logger::info("exited");
  QApplication::exit(0);
}
