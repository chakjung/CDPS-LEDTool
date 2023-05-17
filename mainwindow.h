#pragma once

#include <QMainWindow>

#include <QWidget>
#include <QHBoxLayout>

#include "DeTimefeqLayout/DeTimefeqLayout.h"
#include "EnTimefeqLayout/EnTimefeqLayout.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

   private:
    // Root Widget
    QWidget rootWidget;
    // Root layout
    QHBoxLayout rootLayout;

    // Layout for decoding time frequency combo
    DeTimefeqLayout deTimefeqLayout;
    // Layout for encoding time frequency combo
    EnTimefeqLayout enTimefeqLayout;
};