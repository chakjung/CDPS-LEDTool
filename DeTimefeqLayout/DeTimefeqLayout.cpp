#include "DeTimefeqLayout.h"

DeTimefeqLayout::DeTimefeqLayout() : QVBoxLayout() {
    // Set margins
    this->setContentsMargins(30, 30, 30, 30);

    // Setup timeFeqLineEditLabel
    timeFeqLineEditLabel.setText("請輸入LED頻率循環時間:");
    timeFeqLineEditLabel.setSizePolicy(QSizePolicy::Maximum,
                                       QSizePolicy::Maximum);
    timeFeqLineEditLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");

    // Setup timeFeqLineEdit
    timeFeqInputValidator.setBottom(0);
    timeFeqLineEdit.setValidator(&timeFeqInputValidator);
    timeFeqLineEdit.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");
    connect(&timeFeqLineEdit, &QLineEdit::textEdited, this,
            &DeTimefeqLayout::processConversion);
    connect(&timeFeqLineEdit, &QLineEdit::returnPressed, this,
            &DeTimefeqLayout::processConversion);

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
            &DeTimefeqLayout::processConversion);

    this->addWidget(&timeFeqLineEditLabel);
    this->addWidget(&timeFeqLineEdit);
    this->addWidget(&conversionResultLabel);
    this->addWidget(&convertButton);
}

DeTimefeqLayout::~DeTimefeqLayout() {}

bool DeTimefeqLayout::processConversion() {
    // Get time feq combo
    bool convertible;
    unsigned int timeFeqCombo = timeFeqLineEdit.text().toUInt(&convertible);
    if (!convertible) {
        setDefaultResultText();
        return false;
    }

    // Decode time feq combo
    unsigned short totalTime = timeFeqCombo >> 16;
    double totalTimeSEC = totalTime / 1000.0;  // total time (sec)
    unsigned short frequency = timeFeqCombo & 0xFFFF;

    // Calculate cycle detail
    int cycleCount = 0;
    int onTime = 0;
    int offTime = 0;
    if (frequency != 0) {
        cycleCount = totalTime / 1000 * frequency;
        onTime = 600000 / frequency;
        offTime = 400000 / frequency;
    }

    // Set conversionResultLabel to result text
    setResultText(totalTimeSEC, frequency, cycleCount, onTime, offTime);

    // Set timeFeqLineEdit in focus for next input
    timeFeqLineEdit.setFocus();
    return true;
}

void DeTimefeqLayout::setDefaultResultText() {
    QString resultText(
        "總時間: 秒\n"
        "    頻率: 赫茲\n"
        "\n"
        "循環次數: 次\n"
        "             亮: 微秒\n"
        "             暗: 微秒");
    conversionResultLabel.setText(resultText);
}

void DeTimefeqLayout::setResultText(const double &totalTime,
                                    const unsigned short &frequency,
                                    const int &cycleCount, const int &onTime,
                                    const int &offTime) {
    QString resultText(
        "總時間: %1秒\n"
        "    頻率: %2赫茲\n"
        "\n"
        "循環次數: %3次\n"
        "             亮: %4微秒\n"
        "             暗: %5微秒");
    resultText = resultText.arg(totalTime)
                     .arg(frequency)
                     .arg(cycleCount)
                     .arg(onTime)
                     .arg(offTime);
    conversionResultLabel.setText(resultText);
}