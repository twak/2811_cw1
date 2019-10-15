//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <QLayout>
#include <iostream>

using namespace std;

void ResponsiveLayout::setGeometry(const QRect &r) {

    QLayout::setGeometry(r);

    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = dynamic_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            // headers go at the top
            else if (label -> text() == kNavMenu )
                label -> setGeometry(0,0,r.width(), 40);
            // only show a search button on small resolution, at the right of the window
            else if (label -> text() == kSearchButton && r.width() < 500)
                label -> setGeometry(r.width() - 60,40,60, 40);
            // fixme: focus group did not like this behaviour for the search results.
            else if (label -> text() == kSearchResult )
                label -> setGeometry(rand() %(r.width()-60),rand() %(r.height()-100)+40, 60, 60);
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

// following methods provide a trivial list_-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
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
