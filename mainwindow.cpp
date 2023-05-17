#include "mainwindow.h"

#include <QGuiApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Set title
    this->setWindowTitle("LED頻率循環時間小工具");

    // Get screen info
    const QRect availableScreenGeometry =
        QGuiApplication::primaryScreen()->availableGeometry();
    const QPoint screenCenterPoint = availableScreenGeometry.center();

    // Set window size & position
    int width = availableScreenGeometry.width() / 2;
    int height = availableScreenGeometry.height() / 2;
    this->setGeometry(screenCenterPoint.x() - width / 2,   // x
                      screenCenterPoint.y() - height / 2,  // y
                      width, height);

    // Set background color
    this->setStyleSheet("background-color: #242F36");

    // Set up rootWidget
    this->setCentralWidget(&rootWidget);
    // Set up rootLayout
    rootWidget.setLayout(&rootLayout);

    // Add deTimefeqLayout to rootLayout
    rootLayout.addLayout(&deTimefeqLayout, 1);
    // Add enTimefeqLayout to rootLayout
    rootLayout.addLayout(&enTimefeqLayout, 1);
}

MainWindow::~MainWindow() {}