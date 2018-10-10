#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T22:07:20
#
#-------------------------------------------------


QT          += core gui
QT          += webkitwidgets
QT          += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GPS_MAP
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS += \
    widget.ui

RC_FILE = ic.qrc
