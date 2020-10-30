QT += core gui widgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        folder_compressor.cpp \
        main.cpp \
        responsive_label.cpp \
        responsive_layout.cpp \
        responsive_window.cpp \
        screenshot.cpp

HEADERS += \
    folder_compressor.h \
    responsive_label.h \
    responsive_layout.h \
    responsive_window.h \
    screenshot.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

