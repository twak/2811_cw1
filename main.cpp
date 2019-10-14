
#include <iostream>
#include <QApplication>
#include "ResponsiveWindow.h"


int main(int argc, char* argv[]) {

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

