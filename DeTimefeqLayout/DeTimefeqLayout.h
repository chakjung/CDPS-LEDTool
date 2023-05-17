#pragma once

#include <QVBoxLayout>

#include <QLabel>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>

class DeTimefeqLayout : public QVBoxLayout {
   public:
    DeTimefeqLayout();
    ~DeTimefeqLayout();

   private:
    // Label for TimeFrequency combo inputBox
    QLabel timeFeqLineEditLabel;

    // TimeFrequency combo inputValidator
    QIntValidator timeFeqInputValidator;
    // TimeFrequency combo inputBox
    QLineEdit timeFeqLineEdit;

    // Label to display conversion result
    QLabel conversionResultLabel;

    // Button to start conversion
    QPushButton convertButton;

    // Process conversion
    bool processConversion();

    // Set conversionResultLabel to default text
    void setDefaultResultText();
    // Set conversionResultLabel to result text
    void setResultText(const double &totalTime, const unsigned short &frequency,
                       const int &cycleCount, const int &onTime,
                       const int &offTime);
};