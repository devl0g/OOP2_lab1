#include "textEnter.hpp"
#include "../../utils/logger.hpp"
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLineEdit>

TextEnterPopup::TextEnterPopup(QWidget* parent) noexcept : 
  layout(this),
  lineEdit(this),
  QDialog(parent)
{
  initUI();
}

TextEnterPopup::~TextEnterPopup() noexcept {
  Logger::info("popup text enter closed");
}

// UI

void TextEnterPopup::initUI() noexcept {
  setWindowTitle(tr("Popup"));
  setModal(true);
  setFixedSize(300, 100);

  auto buttonBox = new QDialogButtonBox(
    QDialogButtonBox::StandardButton::Ok | QDialogButtonBox::StandardButton::Cancel, 
    this
  );

  layout.addWidget(&lineEdit);
  layout.addWidget(buttonBox);
  setLayout(&layout);

  QObject::connect(buttonBox, &QDialogButtonBox::accepted, this, &TextEnterPopup::submit);
  QObject::connect(buttonBox, &QDialogButtonBox::rejected, this, &TextEnterPopup::cancel);
}

// Slots

void TextEnterPopup::submit() {
  Logger::debug(std::format("Entered: {}", lineEdit.text().toStdString()));
  emit this->textEntered(lineEdit.text());
  close();
}

void TextEnterPopup::cancel() {
  close();
}
