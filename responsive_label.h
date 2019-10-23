//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVELABEL_H
#define RESPONSIVELABEL_H


#include <QLabel>
#include <QString>
#include <map>

using namespace std;

const QString
        kHomeLink       = "home",
        kBackButton     = "back",
        kShoppingBasket = "basket",
        kSignIn         = "sign-in",
        kNavTabs        = "navigation tabs",
        kFooter         = "fat footer",
        kAdvert         = "advert",
        kSearchButton   = "search",
        kSearchResult   = "result",
        kSearchText     = "search query",
        kSearchForward  = ">",
        kSearchBackward = "<",
        kSearchOptions  = "search options";

const map<QString, QString> kColours = {
        make_pair(kHomeLink,       "#ffaaff"),
        make_pair(kBackButton,     "#ffffaa"),
        make_pair(kShoppingBasket, "#ffaaaa"),
        make_pair(kSignIn,         "#aaffaa"),
        make_pair(kNavTabs,        "#aaaaff"),
        make_pair(kFooter,         "#66ffaa"),
        make_pair(kAdvert,         "#ffaa66"),
        make_pair(kSearchButton,   "#aaffff"),
        make_pair(kSearchResult,   "#66ffff"),
        make_pair(kSearchText,     "#33aaff"),
        make_pair(kSearchForward,  "#aa66ff"),
        make_pair(kSearchBackward, "#aa66ff"),
        make_pair(kSearchOptions,  "#aaff66")
    };

class ResponsiveLabel : public QLabel {
public:
    ResponsiveLabel(QString name) ;
    ResponsiveLabel(QString name, QString colour) ;
};


#endif // RESPONSIVELABEL_H
