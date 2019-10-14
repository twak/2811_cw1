//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVELABEL_H
#define RESPONSIVELABEL_H


#include <QtGui/QLabel>
#include <QString>
#include <map>

using namespace std;

const QString
        kHeader = "header",
        kSearchResult = "result",
        kSearchButton = "search";

const map<QString, QString> kColours = {
        std::make_pair (kHeader, "#ddffff" ),
        std::make_pair (kSearchResult, "#ffffdd" ),
        std::make_pair (kSearchButton, "#ffddff" )
    };

class ResponsiveLabel : public QLabel {
public:
    ResponsiveLabel(QString name) ;
    ResponsiveLabel(QString name, QString colour) ;
};


#endif // RESPONSIVELABEL_H
