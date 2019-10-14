//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include <iostream>

responsive_window::responsive_window() {
    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);

    setLayout(new ResponsiveLayout());
    createWidgets();
}

void responsive_window::createWidgets() {

    // add all the widgets we need to demonstrate all layouts
    layout()->addWidget(new ResponsiveLabel(kHeader));
    layout()->addWidget(new ResponsiveLabel(kSearchButton));
    // we might have more than one search results
    layout()->addWidget(new ResponsiveLabel(kSearchResult));
    layout()->addWidget(new ResponsiveLabel(kSearchResult));
    // note that later widgets are added on top of earlier widgets
}

int screenShot(QString fileName) {

    auto active_window = qApp->activeWindow();
    if (active_window) //could be null if your app doesn't have focus
    {
        QPixmap pixmap(active_window->size());
        active_window->render(&pixmap);
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        pixmap.save(&file, "PNG");
//        ui->label->setPixmap(pixmap);
    }
}

QTimer* mTimer;

int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    cout << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // create a window. See respsonsive_window.cpp!
    responsive_window window;
    window.show();

    mTimer = new QTimer(app);
    mTimer->setSingleShot(true);
    window.connect(mTimer, SIGNAL(timeout()), SLOT(screenShot("foo.png")));



    // wait for the app to terminate
    return app.exec();
}

