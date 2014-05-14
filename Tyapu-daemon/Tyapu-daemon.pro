#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T15:36:43
#
#-------------------------------------------------

QT       += core
QT       +=multimedia

QT       -= gui

TARGET = Tyapu-daemon
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    core.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Tyapu-interface/release/ -lTyapu-interface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Tyapu-interface/debug/ -lTyapu-interface
else:unix: LIBS += -L$$OUT_PWD/../Tyapu-interface/ -lTyapu-interface

INCLUDEPATH += $$PWD/../Tyapu-interface
DEPENDPATH += $$PWD/../Tyapu-interface

HEADERS += \
    core.h
