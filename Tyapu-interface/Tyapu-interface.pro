#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T15:34:44
#
#-------------------------------------------------

QT       -= gui

TARGET = Tyapu-interface
TEMPLATE = lib

DEFINES += TYAPUINTERFACE_LIBRARY

SOURCES += tyapuinterface.cpp

HEADERS += tyapuinterface.h\
        tyapu-interface_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
