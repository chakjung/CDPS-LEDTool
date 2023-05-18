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
    rootLayout.setRowStretch(0, 80);
    rootLayout.setRowStretch(1, 20);
    rootWidget.setLayout(&rootLayout);

    // Add deTimefeqLayout to rootLayout
    deTimefeqLayout.setContentsMargins(10, 10, 5, 5);
    rootLayout.addLayout(&deTimefeqLayout, 0, 0);
    // Add enTimefeqLayout to rootLayout
    enTimefeqLayout.setContentsMargins(5, 10, 10, 5);
    rootLayout.addLayout(&enTimefeqLayout, 0, 1);

    // Add deColorLayout to rootLayout
    deColorLayout.setContentsMargins(10, 5, 5, 10);
    rootLayout.addLayout(&deColorLayout, 1, 0);
    // Add enColorLayout to rootLayout
    enColorLayout.setContentsMargins(5, 5, 10, 10);
    rootLayout.addLayout(&enColorLayout, 1, 1);
}

MainWindow::~MainWindow() {}