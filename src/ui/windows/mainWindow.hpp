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
  ~MainWindow() noexcept;

private:
  QLabel firstLabel {};
  QLabel secondLabel {};

  void initUI() noexcept;
  void implementMenuBar() noexcept;

signals:
private slots:
  void updateFirstLabel(QString text);
  void updateSecondLabel(int value);

  void openTextEnterDialog();
  void openNumberScrollDialog();
  void exit();
};

#endif // INCLUDE_UI_MAINWINDOW_HPP_
