//
// Created by twak on 07/10/2019.
//

#ifndef CARD_H
#define CARD_H

#include <QtGui>
#include <QList>
#include <QLayout>

class CardLayout : public QLayout
{
public:
    CardLayout(QWidget *parent, int dist): QLayout(parent) {}
//    CardLayout(QLayout *parent, int dist): QLayout(parent) {}
    CardLayout(): QLayout() {}
    ~CardLayout();

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);
    void setGeometry(const QRect &rect);

private:
    QList<QLayoutItem*> list;
};
#endif
