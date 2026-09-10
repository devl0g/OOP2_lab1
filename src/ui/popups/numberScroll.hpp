#ifndef INCLUDE_UI_POPUPS_NUMBER_SCROLL_HPP_
#define INCLUDE_UI_POPUPS_NUMBER_SCROLL_HPP_

#include <QtWidgets/QDialog>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QLabel>

class NumberScrollPopup : public QDialog {
  Q_OBJECT

public:
  explicit NumberScrollPopup(QWidget* parent = nullptr) noexcept;
  ~NumberScrollPopup() noexcept;

private:
  QVBoxLayout layout {};
  QScrollBar scrollBar {};
  QLabel valueLabel {};

signals:
  void numberChoosed(int number);

private slots:
  void scrolled(int value);
  void submit();
  void cancel();
};

#endif // INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_
