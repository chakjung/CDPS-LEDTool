#pragma once

#include <QGridLayout>

#include <QLabel>
#include <QPushButton>

class EnColorLayout : public QGridLayout {
   public:
    EnColorLayout();
    ~EnColorLayout();

   private:
    // Label for Color input
    QLabel colorInputLabel;
    // Label for Color input: "Entry"
    QLabel en;
    // Label for Color input: "Exit"
    QLabel ex;
    // Color input buttons
    QPushButton enRed;
    QPushButton enGreen;
    QPushButton enYellow;
    QPushButton exRed;
    QPushButton exGreen;
    QPushButton exYellow;

    // Color input buttons toggled
    void enRedToggled();
    void enGreenToggled();
    void enYellowToggled();
    void exRedToggled();
    void exGreenToggled();
    void exYellowToggled();

    // Label to display conversion result
    QLabel conversionResultLabel;

    // Process conversion
    bool processConversion();

    // Set conversionResultLabel to default text
    void setDefaultResultText();
    // Set conversionResultLabel to result text
    void setResultText(const unsigned char& color);
};