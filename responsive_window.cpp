//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>


ResponsiveWindow::ResponsiveWindow() {
    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);

    setLayout(new ResponsiveLayout());
    createWidgets();
}

void ResponsiveWindow::createWidgets() {

    // add all the widgets we need to demonstrate all layouts
    layout()->addWidget(new ResponsiveLabel(kHeader));
    layout()->addWidget(new ResponsiveLabel(kSearchButton));
    // we might have more than one search results
    layout()->addWidget(new ResponsiveLabel(kSearchResult));
    layout()->addWidget(new ResponsiveLabel(kSearchResult));
    // note that later widgets are added on top of earlier widgets
}

int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    cout << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // create a window. See respsonsive_window.cpp!
    if (argc-1)  {
        Screenshot screenshot;
        screenshot.show();
        // wait for the app to terminate
        return app.exec();
    } else {
        ResponsiveWindow window;
        window.show();
        // wait for the app to terminate
        return app.exec();
    }

}

