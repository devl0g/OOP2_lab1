#ifndef INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_
#define INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_

#include <QWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QLabel>
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr) noexcept;

private:
  QLabel firstLabel;
  QLabel secondLabel;

  void implementMenuBar() noexcept;

signals:
private slots:
  void updateFirstLabel(QString text);

  void openTextEnterDialog();
  void exit();
};

#endif // INCLUDE_UI_MAINWINDOW_HPP_
