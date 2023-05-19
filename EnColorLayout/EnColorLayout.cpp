#include "EnColorLayout.h"

EnColorLayout::EnColorLayout() : QGridLayout() {
    // Setup colorInputLabel
    colorInputLabel.setText("請選擇燈號顏色");
    colorInputLabel.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    colorInputLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");

    // Setup label for Color input: "Entry"
    en.setText("進站");
    en.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    en.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 16px;");
    // Setup label for Color input: "Exit"
    ex.setText("出站");
    ex.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    ex.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 16px;");

    // Setup color input buttons
    enRed.setText("◉");
    enGreen.setText("◉");
    enYellow.setText("◉");
    exRed.setText("◉");
    exGreen.setText("◉");
    exYellow.setText("◉");

    enRed.setCheckable(true);
    enGreen.setCheckable(true);
    enYellow.setCheckable(true);
    exRed.setCheckable(true);
    exGreen.setCheckable(true);
    exYellow.setCheckable(true);

    enRedToggled();
    enGreenToggled();
    enYellowToggled();
    exRedToggled();
    exGreenToggled();
    exYellowToggled();

    connect(&enRed, &QPushButton::toggled, this, &EnColorLayout::enRedToggled);
    connect(&enGreen, &QPushButton::toggled, this,
            &EnColorLayout::enGreenToggled);
    connect(&enYellow, &QPushButton::toggled, this,
            &EnColorLayout::enYellowToggled);
    connect(&exRed, &QPushButton::toggled, this, &EnColorLayout::exRedToggled);
    connect(&exGreen, &QPushButton::toggled, this,
            &EnColorLayout::exGreenToggled);
    connect(&exYellow, &QPushButton::toggled, this,
            &EnColorLayout::exYellowToggled);

    // Setup conversionResultLabel
    setDefaultResultText();
    conversionResultLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");
    conversionResultLabel.setTextInteractionFlags(Qt::TextSelectableByMouse);

    this->addWidget(&colorInputLabel, 0, 0, 1, -1);
    this->addWidget(&en, 1, 0, 1, 3);
    this->addWidget(&ex, 1, 3, 1, 3);
    this->addWidget(&enRed, 2, 0);
    this->addWidget(&enGreen, 2, 1);
    this->addWidget(&enYellow, 2, 2);
    this->addWidget(&exRed, 2, 3);
    this->addWidget(&exGreen, 2, 4);
    this->addWidget(&exYellow, 2, 5);
    this->addWidget(&conversionResultLabel, 3, 0, 1, -1);
}

EnColorLayout::~EnColorLayout() {}

void EnColorLayout::enRedToggled() {
    enRed.setStyleSheet(enRed.isChecked() ? "border: none;"
                                            "color: #FF3131;"
                                            "font-size: 26px;"
                                            "text-align: left;"
                                          : "border: none;"
                                            "color: #8B0000;"
                                            "font-size: 26px;"
                                            "text-align: left;");

    processConversion();
}
void EnColorLayout::enGreenToggled() {
    enGreen.setStyleSheet(enGreen.isChecked() ? "border: none;"
                                                "color: #39FF14;"
                                                "font-size: 26px;"
                                                "text-align: left;"
                                              : "border: none;"
                                                "color: #014D18;"
                                                "font-size: 26px;"
                                                "text-align: left;");
    processConversion();
}
void EnColorLayout::enYellowToggled() {
    enYellow.setStyleSheet(enYellow.isChecked() ? "border: none;"
                                                  "color: #FFF01F;"
                                                  "font-size: 26px;"
                                                  "text-align: left;"
                                                : "border: none;"
                                                  "color: #8B8000;"
                                                  "font-size: 26px;"
                                                  "text-align: left;");
    processConversion();
}
void EnColorLayout::exRedToggled() {
    exRed.setStyleSheet(exRed.isChecked() ? "border: none;"
                                            "color: #FF3131;"
                                            "font-size: 26px;"
                                            "text-align: left;"
                                          : "border: none;"
                                            "color: #8B0000;"
                                            "font-size: 26px;"
                                            "text-align: left;");
    processConversion();
}
void EnColorLayout::exGreenToggled() {
    exGreen.setStyleSheet(exGreen.isChecked() ? "border: none;"
                                                "color: #39FF14;"
                                                "font-size: 26px;"
                                                "text-align: left;"
                                              : "border: none;"
                                                "color: #014D18;"
                                                "font-size: 26px;"
                                                "text-align: left;");
    processConversion();
}
void EnColorLayout::exYellowToggled() {
    exYellow.setStyleSheet(exYellow.isChecked() ? "border: none;"
                                                  "color: #FFF01F;"
                                                  "font-size: 26px;"
                                                  "text-align: left;"
                                                : "border: none;"
                                                  "color: #8B8000;"
                                                  "font-size: 26px;"
                                                  "text-align: left;");
    processConversion();
}

bool EnColorLayout::processConversion() {
    // Pack color
    unsigned char color = 0;
    if (enYellow.isChecked()) color |= 1 << 5;
    if (enGreen.isChecked()) color |= 1 << 4;
    if (enRed.isChecked()) color |= 1 << 3;
    if (exYellow.isChecked()) color |= 1 << 2;
    if (exGreen.isChecked()) color |= 1 << 1;
    if (exRed.isChecked()) color |= 1;

    // Set conversionResultLabel to result text
    setResultText(color);

    return true;
}

void EnColorLayout::setDefaultResultText() {
    conversionResultLabel.setText("LED顏色:");
}

void EnColorLayout::setResultText(const unsigned char& color) {
    QString resultText("LED顏色: %1");
    resultText = resultText.arg(color);
    conversionResultLabel.setText(resultText);
}