#include "DeColorLayout.h"

#include <bitset>

DeColorLayout::DeColorLayout() : QGridLayout() {
    // Setup colorLineEditLabel
    colorLineEditLabel.setText("請輸入LED顏色:");
    colorLineEditLabel.setSizePolicy(QSizePolicy::Maximum,
                                     QSizePolicy::Maximum);
    colorLineEditLabel.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");

    // Setup colorLineEdit
    colorInputValidator.setRange(0, 63);
    colorLineEdit.setValidator(&colorInputValidator);
    colorLineEdit.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 20px;");
    connect(&colorLineEdit, &QLineEdit::textEdited, this,
            &DeColorLayout::processConversion);
    connect(&colorLineEdit, &QLineEdit::returnPressed, this,
            &DeColorLayout::processConversion);

    // Setup conversion result "Entry"
    en.setText("進站");
    en.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    en.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 16px;");
    // Setup conversion result "Exit"
    ex.setText("出站");
    ex.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    ex.setStyleSheet(
        "color: #95BFDB;"
        "font-size: 16px;");

    // Setup conversion result labels
    setDefaultResult();
    enRed.setText("◉");
    enGreen.setText("◉");
    enYellow.setText("◉");
    exRed.setText("◉");
    exGreen.setText("◉");
    exYellow.setText("◉");

    this->addWidget(&colorLineEditLabel, 0, 0, 1, -1);
    this->addWidget(&colorLineEdit, 1, 0, 1, -1);
    this->addWidget(&en, 2, 0, 1, 3);
    this->addWidget(&ex, 2, 3, 1, 3);
    this->addWidget(&enRed, 3, 0);
    this->addWidget(&enGreen, 3, 1);
    this->addWidget(&enYellow, 3, 2);
    this->addWidget(&exRed, 3, 3);
    this->addWidget(&exGreen, 3, 4);
    this->addWidget(&exYellow, 3, 5);
}

DeColorLayout::~DeColorLayout() {}

bool DeColorLayout::processConversion() {
    // Get color
    bool convertible;
    unsigned char color = colorLineEdit.text().toUShort(&convertible);
    if (!convertible) {
        setDefaultResult();
        return false;
    }

    // Decode color
    //      5       4       3       2       1       0
    // 進站(黃) 進站(綠) 進站(紅) 出站(黃) 出站(綠) 出站(紅)
    std::bitset<8> colorBits(color);
    setResult(colorBits[3], colorBits[4], colorBits[5], colorBits[0],
              colorBits[1], colorBits[2]);
    return true;
}

void DeColorLayout::setDefaultResult() {
    enRed.setStyleSheet(
        "color: #8B0000;"
        "font-size: 26px;");
    enGreen.setStyleSheet(
        "color: #014D18;"
        "font-size: 26px;");
    enYellow.setStyleSheet(
        "color: #8B8000;"
        "font-size: 26px;");
    exRed.setStyleSheet(
        "color: #8B0000;"
        "font-size: 26px;");
    exGreen.setStyleSheet(
        "color: #014D18;"
        "font-size: 26px;");
    exYellow.setStyleSheet(
        "color: #8B8000;"
        "font-size: 26px;");
}

void DeColorLayout::setResult(const bool &enRedOn, const bool &enGreenOn,
                              const bool &enYellowOn, const bool &exRedOn,
                              const bool &exGreenOn, const bool &exYellowOn) {
    enRed.setStyleSheet(enRedOn ? "color: #FF3131;"
                                  "font-size: 26px;"
                                : "color: #8B0000;"
                                  "font-size: 26px;");
    enGreen.setStyleSheet(enGreenOn ? "color: #39FF14;"
                                      "font-size: 26px;"
                                    : "color: #014D18;"
                                      "font-size: 26px;");
    enYellow.setStyleSheet(enYellowOn ? "color: #FFF01F;"
                                        "font-size: 26px;"
                                      : "color: #8B8000;"
                                        "font-size: 26px;");
    exRed.setStyleSheet(exRedOn ? "color: #FF3131;"
                                  "font-size: 26px;"
                                : "color: #8B0000;"
                                  "font-size: 26px;");
    exGreen.setStyleSheet(exGreenOn ? "color: #39FF14;"
                                      "font-size: 26px;"
                                    : "color: #014D18;"
                                      "font-size: 26px;");
    exYellow.setStyleSheet(exYellowOn ? "color: #FFF01F;"
                                        "font-size: 26px;"
                                      : "color: #8B8000;"
                                        "font-size: 26px;");
}