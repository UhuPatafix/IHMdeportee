QT += widgets
QT += gui
QT += core

CONFIG += qwt

INCLUDEPATH += D:/Qwt/qwt-6.1.3/qwt-6.1.3/include/

SOURCES += \
    main.cpp \
    ihmdeportee.cpp \
    courbe.cpp

HEADERS += \
    ihmdeportee.h \
    courbe.h

FORMS += \
    ihmdeportee.ui \
    courbe.ui
