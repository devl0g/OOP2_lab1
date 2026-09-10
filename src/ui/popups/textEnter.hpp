#ifndef INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_
#define INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_

#include <QtWidgets/QDialog>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLineEdit>

class TextEnterPopup : public QDialog {
  Q_OBJECT

public:
  explicit TextEnterPopup(QWidget* parent = nullptr) noexcept;
  ~TextEnterPopup() noexcept;

private:
  void initUI() noexcept;

  QVBoxLayout layout {};
  QLineEdit lineEdit {};

signals:
  void textEntered(QString string);

private slots:
  void submit();
  void cancel();
};

#endif // INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_
