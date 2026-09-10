#include "numberScroll.hpp"
#include "../../utils/logger.hpp"
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QBoxLayout>
#include <string>

NumberScrollPopup::NumberScrollPopup(QWidget* parent) noexcept :
  scrollBar(Qt::Horizontal, this),
  valueLabel(tr("1"), this),
  layout(this),
  QDialog(parent)
{
  initUI();
}

NumberScrollPopup::~NumberScrollPopup() noexcept {
  Logger::info("popup number scroll closed");
}

// UI

void NumberScrollPopup::initUI() noexcept {
  setWindowTitle(tr("Popup"));
  setModal(true);
  setFixedSize(300, 100);

  scrollBar.setFixedHeight(20);
  scrollBar.setMinimum(1);
  scrollBar.setMaximum(100);
  scrollBar.setValue(1);

  auto row = new QHBoxLayout(nullptr);
  row->addWidget(&scrollBar, 1);
  row->addWidget(&valueLabel);

  auto buttonBox = new QDialogButtonBox(
    QDialogButtonBox::StandardButton::Ok | QDialogButtonBox::StandardButton::Cancel, 
    this
  );

  layout.addLayout(row, 1);
  layout.addWidget(buttonBox);
  setLayout(&layout);

  QObject::connect(&scrollBar, &QScrollBar::valueChanged, this, &NumberScrollPopup::scrolled);
  QObject::connect(buttonBox, &QDialogButtonBox::accepted, this, &NumberScrollPopup::submit);
  QObject::connect(buttonBox, &QDialogButtonBox::rejected, this, &NumberScrollPopup::cancel);
}

// Slots

void NumberScrollPopup::scrolled(int value) {
  valueLabel.setText(tr(std::to_string(value).c_str()));
}

void NumberScrollPopup::submit() {
  Logger::debug(std::format("Choosed: {}", scrollBar.value()));
  emit this->numberChoosed(scrollBar.value());
  close();
}

void NumberScrollPopup::cancel() {
  close();
}
