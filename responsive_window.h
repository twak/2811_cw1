//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVEWINDOW_H
#define RESPONSIVEWINDOW_H

#include <QWidget>
#include "responsive_layout.h"
#include "responsive_label.h"

using namespace std;

class responsive_window: public QWidget
{
public:
    responsive_window();

protected:
    void createWidgets();
};


#endif //RESPONSIVEWINDOW_H
