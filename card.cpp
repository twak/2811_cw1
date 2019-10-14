//
// Created by twak on 07/10/2019.
//
#define quote(x) #x

#include "card.h"
#include <QList>
#include <QLayout>
#include <iostream>
using namespace std;

int CardLayout::count() const
{
    // QList::size() returns the number of QLayoutItems in the list
    return list.size();
}

QLayoutItem *CardLayout::itemAt(int idx) const
{
    // QList::value() performs index checking, and returns 0 if we are
    // outside the valid range
    return list.value(idx);
}

QLayoutItem *CardLayout::takeAt(int idx)
{
    // QList::take does not do index checking
    return idx >= 0 && idx < list.size() ? list.takeAt(idx) : 0;
}

void CardLayout::addItem(QLayoutItem *item)
{
    list.append(item);
}

CardLayout::~CardLayout()
{
    cout << "destroyed layout " << endl;
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

void CardLayout::setGeometry(const QRect &r)
{
    QLayout::setGeometry(r);

    if (list.size() == 0)
        return;


    int w = r.width() - (list.count() - 1) * spacing();
    int h = r.height() - (list.count() - 1) * spacing();
    int i = 0;
    while (i < list.size()) {
        QLayoutItem *o = list.at(i);

        std::cout<<typeid(o).name()<<"  "<< quote(o) <<"\n";

        QRect geom(r.x() + i *5* spacing(), r.y() + i * spacing(), w, h);
        o->setGeometry(geom);
        ++i;
    }
}

QSize CardLayout::sizeHint() const
{
    QSize s(0,0);
    int n = list.count();
    if (n > 0)
        s = QSize(100,70); //start with a nice default size
    int i = 0;
    while (i < n) {
        QLayoutItem *o = list.at(i);
        s = s.expandedTo(o->sizeHint());
        ++i;
    }
    return s + n*QSize(spacing(), spacing());
}

QSize CardLayout::minimumSize() const
{
    QSize s(0,0);
    int n = list.count();
    int i = 0;
    while (i < n) {
        QLayoutItem *o = list.at(i);
        s = s.expandedTo(o->minimumSize());
        ++i;
    }
    return s + n*QSize(spacing(), spacing());
}