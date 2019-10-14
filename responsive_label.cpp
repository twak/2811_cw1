//
// Created by twak on 14/10/2019.
//

#include <QFrame>
#include "responsive_label.h"

ResponsiveLabel::ResponsiveLabel(QString name) : ResponsiveLabel(name, kColours.at(name)) {
}

ResponsiveLabel::ResponsiveLabel(QString name, QString colour) : QLabel() {
    setText(name);

    setStyleSheet("QLabel { border-width:1px; border-color:black; background-color : "+colour+"; color : black; }");
    setAlignment(Qt::AlignCenter);
}