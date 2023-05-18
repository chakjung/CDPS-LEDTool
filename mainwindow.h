#pragma once

#include <QMainWindow>

#include <QWidget>
#include <QGridLayout>

#include "DeTimefeqLayout/DeTimefeqLayout.h"
#include "EnTimefeqLayout/EnTimefeqLayout.h"

#include "DeColorLayout/DeColorLayout.h"
#include "EnColorLayout/EnColorLayout.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

   private:
    // Root Widget
    QWidget rootWidget;
    // Root layout
    QGridLayout rootLayout;

    // Layout for decoding time frequency combo
    DeTimefeqLayout deTimefeqLayout;
    // Layout for encoding time frequency combo
    EnTimefeqLayout enTimefeqLayout;

    // Layout for decoding color
    DeColorLayout deColorLayout;
    // Layout for encoding color
    EnColorLayout enColorLayout;
};