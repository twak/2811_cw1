//
// Created by twak on 07/10/2019.
//

#ifndef RESPONSIVELAYOUT_H
#define RESPONSIVELAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>

class ResponsiveLayout : public QLayout
{
public:
    ResponsiveLayout(): QLayout() {}
    ~ResponsiveLayout();

    void setGeometry(const QRect &rect);

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);

private:
    QList<QLayoutItem*> list;
};
#endif // RESPONSIVELAYOUT_H
