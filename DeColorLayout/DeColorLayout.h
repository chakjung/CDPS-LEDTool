#pragma once

#include <QGridLayout>

#include <QLabel>
#include <QIntValidator>
#include <QLineEdit>

class DeColorLayout : public QGridLayout {
   public:
    DeColorLayout();
    ~DeColorLayout();

   private:
    // Label for Color inputBox
    QLabel colorLineEditLabel;

    // Color inputValidator
    QIntValidator colorInputValidator;
    // Color inputBox
    QLineEdit colorLineEdit;

    // Label to conversion result "Entry"
    QLabel en;
    // Label to conversion result "Exit"
    QLabel ex;
    // Label to display conversion result
    QLabel enRed;
    QLabel enGreen;
    QLabel enYellow;
    QLabel exRed;
    QLabel exGreen;
    QLabel exYellow;

    // Process conversion
    bool processConversion();

    // Set lights to default
    void setDefaultResult();
    // Set lights to result
    void setResult(const bool &enRedOn, const bool &enGreenOn,
                   const bool &enYellowOn, const bool &exRedOn,
                   const bool &exGreenOn, const bool &exYellowOn);
};