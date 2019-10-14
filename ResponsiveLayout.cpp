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

int ResponsiveLayout::count() const
{
    // QList::size() returns the number of QLayoutItems in the list
    return list.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const
{
    // QList::value() performs index checking, and returns 0 if we are
    // outside the valid range
    return list.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx)
{
    // QList::take does not do index checking
    return idx >= 0 && idx < list.size() ? list.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item)
{
    list.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize( 400, 400 );
}

ResponsiveLayout::~ResponsiveLayout()
{
    cout << "destroyed layout " << endl;
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

void ResponsiveLayout::setGeometry(const QRect &r) {
    QLayout::setGeometry(r);

    for (int i = 0; i < list.size(); i++) {

        QLayoutItem *o = list.at(i);

        try {
            ResponsiveLabel *label = dynamic_cast<ResponsiveLabel *>(o->widget());

            if (label -> text() == HEADER )
                label -> setGeometry(0,0,r.width(), 40);
            else if (label -> text() == SEARCH_BUTTON && r.width() < 500)
                label -> setGeometry(r.width() - 40,40,60, 40);
            else
                // default: disappear
                label -> setGeometry (-1,-1,0,0);

        }
        catch (bad_cast) {
            cout << "warning, unknown widget class in layout" << endl;
        }

        std::cout<<typeid(o).name()<<"  "<< quote(o) <<"\n";
    }
}
