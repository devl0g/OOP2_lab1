#include "mainWindow.hpp"
#include "../popups/textEnter.hpp"
#include "../popups/numberScroll.hpp"
#include "../../utils/logger.hpp"
#include <QtWidgets/QBoxLayout>
#include <QApplication>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent) noexcept
  : QMainWindow(parent)
{
  setWindowTitle(tr("Lab No.1"));
  implementMenuBar();

  auto *centralContainer = new QWidget(this);
  setCentralWidget(centralContainer);

  firstLabel.setText(tr(""));
  firstLabel.setAlignment(Qt::AlignCenter);

  secondLabel.setText(tr(""));
  secondLabel.setAlignment(Qt::AlignCenter);

  auto layout = new QVBoxLayout(centralContainer);
  layout->setAlignment(Qt::AlignCenter);
  layout->addWidget(&firstLabel);
  layout->addWidget(&secondLabel);
}

MainWindow::~MainWindow() noexcept {
  Logger::info("window closed");
}

void MainWindow::implementMenuBar() noexcept {
  auto workMenuSection = menuBar()->addMenu(tr("&Робота"));

  auto work1Action = workMenuSection->addAction(tr("&Робота1"));
  auto work2Action = workMenuSection->addAction(tr("&Робота2"));
  auto exitAction = workMenuSection->addAction(tr("&Вийти"));

  QObject::connect(work1Action, SIGNAL(triggered(bool)), this, SLOT(openTextEnterDialog()));
  QObject::connect(work2Action, SIGNAL(triggered(bool)), this, SLOT(openNumberScrollDialog()));
  QObject::connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));
}

void MainWindow::openTextEnterDialog() {
  TextEnterPopup popup(this);

  QObject::connect(&popup, &TextEnterPopup::textEntered, this, &MainWindow::updateFirstLabel);

  Logger::info("popup text enter opening");
  popup.exec(); // Blocks execution, so TextEnterPopup doesn't disallocate too early
}

void MainWindow::openNumberScrollDialog() {
  NumberScrollPopup popup(this);

  QObject::connect(&popup, &NumberScrollPopup::numberChoosed, this, &MainWindow::updateSecondLabel);

  Logger::info("popup number scroll opening");
  popup.exec(); // Blocks execution, so TextEnterPopup doesn't disallocate too early
}

void MainWindow::updateFirstLabel(QString text) {
  this->firstLabel.setText(text);
}

void MainWindow::updateSecondLabel(int value) {
  this->secondLabel.setText(tr(std::to_string(value).c_str()));
}

void MainWindow::exit() {
  Logger::info("exited");
  QApplication::exit(0);
}
