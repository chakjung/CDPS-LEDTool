#pragma once

#include <QVBoxLayout>

#include <QLabel>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>

class EnTimefeqLayout : public QVBoxLayout {
   public:
    EnTimefeqLayout();
    ~EnTimefeqLayout();

   private:
    // Label for Time inputBox
    QLabel timeLineEditLabel;
    // Time inputValidator
    QIntValidator timeInputValidator;
    // Time inputBox
    QLineEdit timeLineEdit;

    // Label for Frequency inputBox
    QLabel feqLineEditLabel;
    // Frequency inputValidator
    QIntValidator feqInputValidator;
    // Frequency inputBox
    QLineEdit feqLineEdit;

    // Label to display conversion result
    QLabel conversionResultLabel;

    // Button to start conversion
    QPushButton convertButton;

    // Process conversion
    bool processConversion();
    // Process conversion during edits
    bool processConversionLive();

    // Set conversionResultLabel to default text
    void setDefaultResultText();
    // Set conversionResultLabel to result text
    void setResultText(const unsigned int& timeFeqCombo);
};