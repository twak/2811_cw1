//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVELABEL_H
#define RESPONSIVELABEL_H


#include <QtGui/QLabel>
#include <QString>
#include <map>

using namespace std;

const QString HEADER = "header",
    SEARCH_BUTTON = "search";

const map<QString, QString> colours = {
        std::make_pair (HEADER, "#ddffff"),
        std::make_pair ( SEARCH_BUTTON, "#ffddff")
    };

class ResponsiveLabel : public QLabel {
public:
    ResponsiveLabel(QString name) ;
    ResponsiveLabel(QString name, QString colour) ;
};


#endif // RESPONSIVELABEL_H
