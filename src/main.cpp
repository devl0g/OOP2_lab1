#include "utils/logger.hpp"
#include "ui/mainwindow.hpp"
#include <QApplication>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  MainWindow window;
  window.show();

  Logger::info("window initiation");
  return app.exec();
}
