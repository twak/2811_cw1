//
// Created by twak on 14/10/2019.
//

#ifndef LAB1_RESPONSIVEWINDOW_H
#define LAB1_RESPONSIVEWINDOW_H

#include <QWidget>
#include "ResponsiveLayout.h"
#include "ResponsiveLabel.h"

using namespace std;

class ResponsiveWindow: public QWidget
{
public:
    ResponsiveWindow();

protected:
    void createWidgets();
};


#endif //LAB1_RESPONSIVEWINDOW_H
