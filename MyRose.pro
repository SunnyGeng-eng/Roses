#-------------------------------------------------
#
# Project created by QtCreator 2016-07-18T13:35:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyRose
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    rose.cpp \
    systemtrayicon.cpp

HEADERS  += widget.h \
    rose.h \
    systemtrayicon.h

RESOURCES += \
    images.qrc

DISTFILES += \
    myicon.rc

RC_FILE += \
    myicon.rc
