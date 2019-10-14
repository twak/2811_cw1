//
// Created by twak on 14/10/2019.
//

#include "ResponsiveWindow.h"
#include "ResponsiveLayout.h"
#include <iostream>

ResponsiveWindow::ResponsiveWindow() {
    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);

    setLayout(new ResponsiveLayout());
    createWidgets();
}

void ResponsiveWindow::createWidgets() {
    layout()->addWidget(new ResponsiveLabel(HEADER));
    layout()->addWidget(new ResponsiveLabel(SEARCH_BUTTON));
}

int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    cout << "Qt version: " << QT_VERSION_STR << endl;

    // Qt Application
    QApplication app(argc, argv);

    // create a window. See ResponsiveWindow.cpp!
    ResponsiveWindow window;
    window.show();

    // wait for the app to terminate
    return app.exec();
}