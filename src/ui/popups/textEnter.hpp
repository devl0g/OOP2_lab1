#ifndef INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_
#define INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_

#include <QtWidgets/QDialog>
#include <QtWidgets/QBoxLayout>
#include <qobject.h>

class TextEnterPopup : public QDialog {
  Q_OBJECT

public:
  explicit TextEnterPopup(QWidget* parent = nullptr) noexcept;
  ~TextEnterPopup() noexcept;

private:
  QVBoxLayout layout;

signals:
  void textEntered(QString string);

private slots:
};

#endif // INCLUDE_UI_POPUPS_TEXT_ENTER_HPP_
