#ifndef INCLUDE_UI_MAINWINDOW_HPP_
#define INCLUDE_UI_MAINWINDOW_HPP_

#include <QWidget>
#include <QtWidgets/QMenuBar>
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr) noexcept;

private:
  void implementMenuBar() noexcept;

signals:
private slots:
  void exit();
};

#endif // INCLUDE_UI_MAINWINDOW_HPP_
