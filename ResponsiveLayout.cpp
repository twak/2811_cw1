//
// Created by twak on 07/10/2019.
//
#define quote(x) #x

#include "ResponsiveLayout.h"
#include "ResponsiveLabel.h"
#include <QList>
#include <QLayout>
#include <iostream>
using namespace std;

void ResponsiveLayout::setGeometry(const QRect &r) {

    QLayout::setGeometry(r);

    // for all the Widgets added in responsiveWindow.cpp
    for (int i = 0; i < list.size(); i++) {

        QLayoutItem *o = list.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = dynamic_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            // headers go at the top
            else if (label -> text() == HEADER )
                label -> setGeometry(0,0,r.width(), 40);
            // only show a search button on small resolutions?!
            else if (label -> text() == SEARCH_BUTTON && r.width() < 500)
                label -> setGeometry(r.width() - 60,40,60, 40);
            // otherwise: disappear label by moving out of bounds
            else
                label -> setGeometry (-1,-1,0,0);
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

// following methods provide a trivial implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list.size() ? list.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}
QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
