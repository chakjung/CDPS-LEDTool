#include "EnTimefeqLayout.h"

EnTimefeqLayout::EnTimefeqLayout() : QVBoxLayout() {
    // Set margins
    this->setContentsMargins(30, 30, 30, 30);

    // Setup timeLineEditLabel
    timeLineEditLabel.setText("請輸入總時間 (毫秒):");
    timeLineEditLabel.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    timeLineEditLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");

    // Setup timeLineEdit
    timeInputValidator.setRange(0, 65535);
    timeLineEdit.setValidator(&timeInputValidator);
    timeLineEdit.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");
    connect(&timeLineEdit, &QLineEdit::textEdited, this,
            &EnTimefeqLayout::processConversionLive);
    connect(&timeLineEdit, &QLineEdit::returnPressed, this,
            &EnTimefeqLayout::processConversion);

    // Setup feqLineEditLabel
    feqLineEditLabel.setText("請輸入頻率 (赫茲):");
    feqLineEditLabel.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    feqLineEditLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");

    // Setup feqLineEdit
    feqInputValidator.setRange(0, 65535);
    feqLineEdit.setValidator(&feqInputValidator);
    feqLineEdit.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");
    connect(&feqLineEdit, &QLineEdit::textEdited, this,
            &EnTimefeqLayout::processConversionLive);
    connect(&feqLineEdit, &QLineEdit::returnPressed, this,
            &EnTimefeqLayout::processConversion);

    // Setup conversionResultLabel
    setDefaultResultText();
    conversionResultLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");
    conversionResultLabel.setTextInteractionFlags(Qt::TextSelectableByMouse);

    // Setup convertButton
    convertButton.setText("轉換");
    convertButton.setStyleSheet(
        "background-color: #39434a;"
        "color: #95BFDB;"
        "font-size: 20px;");
    connect(&convertButton, &QPushButton::released, this,
            &EnTimefeqLayout::processConversion);

    this->addWidget(&timeLineEditLabel);
    this->addWidget(&timeLineEdit);
    this->addWidget(&feqLineEditLabel);
    this->addWidget(&feqLineEdit);
    this->addWidget(&conversionResultLabel);
    this->addWidget(&convertButton);
}

EnTimefeqLayout::~EnTimefeqLayout() {}

bool EnTimefeqLayout::processConversion() {
    if (processConversionLive()) {
        // Set timeLineEdit in focus for next input
        timeLineEdit.setFocus();

        return true;
    }

    return false;
}

bool EnTimefeqLayout::processConversionLive() {
    // Get total time
    bool convertible;
    unsigned short totalTime = timeLineEdit.text().toUShort(&convertible);
    if (!convertible) {
        setDefaultResultText();
        return false;
    }

    // Get frequency
    unsigned short frequency = feqLineEdit.text().toUShort(&convertible);
    if (!convertible) {
        setDefaultResultText();
        return false;
    }

    // Pack time + frequency into timeFeqCombo
    unsigned int timeFeqCombo = ((unsigned int)totalTime) << 16 | frequency;

    // Set conversionResultLabel to result text
    setResultText(timeFeqCombo);

    return true;
}

void EnTimefeqLayout::setDefaultResultText() {
    conversionResultLabel.setText("LED頻率循環時間:");
}

void EnTimefeqLayout::setResultText(const unsigned int& timeFeqCombo) {
    QString resultText("LED頻率循環時間: %1");
    resultText = resultText.arg(timeFeqCombo);
    conversionResultLabel.setText(resultText);
}