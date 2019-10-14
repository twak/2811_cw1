//
// Created by twak on 14/10/2019.
//

#include "ResponsiveWindow.h"
#include "ResponsiveLayout.h"

ResponsiveWindow::ResponsiveWindow()
{
    createWidgets();
    setWindowTitle("2811: Coursework 1");
    setLayout( new ResponsiveLayout() );
    setMinimumSize(320, 320);
}

void ResponsiveWindow::createWidgets() {
    layout()->addWidget(new ResponsiveLabel(HEADER) );
    layout()->addWidget(new ResponsiveLabel(SEARCH_BUTTON) );
}