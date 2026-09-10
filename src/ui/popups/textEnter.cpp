#include "textEnter.hpp"
#include "../../utils/logger.hpp"
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLineEdit>

TextEnterPopup::TextEnterPopup(QWidget* parent) noexcept
  : QDialog(parent)
{
  setWindowTitle(tr("Popup"));
  setModal(true);
  setFixedSize(300, 100);

  auto lineEdit = new QLineEdit(this);

  auto buttonBox = new QDialogButtonBox(
    QDialogButtonBox::StandardButton::Ok | QDialogButtonBox::StandardButton::Discard, 
    this
  );

  layout.addWidget(lineEdit);
  layout.addWidget(buttonBox);
  setLayout(&layout);
}

TextEnterPopup::~TextEnterPopup() noexcept {
  Logger::info("popup closed");
}
