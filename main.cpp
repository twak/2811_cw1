#include <algorithm>
#include <vector>
#include <iostream>
#include <QApplication>
#include <QDebug>

using namespace std;


#include <QWidget>
#include "card.h"

// Put forward references to widget classes here

class MyWindow: public QWidget
{
public:
    MyWindow();

private:
    void createWidgets();
    void arrangeWidgets();

    // Specify widgets here, using pointers
};

MyWindow::MyWindow()
{
    createWidgets();
    arrangeWidgets();
    setWindowTitle("My Window");
    setLayout(new CardLayout() );
    setMinimumSize(320, 200);

    layout()->addWidget(new QLabel("foo"));
    layout()->addWidget(new QLabel("foo2"));
    layout()->addWidget(new QLabel("foo3"));
}

void MyWindow::createWidgets()
{
    // Create widgets on the heap using new
}

void MyWindow::arrangeWidgets()
{
    // Create layout for widgets here
    // Remember to call setLayout!
}

int main(int argc, char* argv[]) {
    qDebug() << QT_VERSION_STR;

    QApplication app(argc, argv);

    MyWindow window;
    window.show();

    return app.exec();
}

