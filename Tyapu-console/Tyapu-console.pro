#-------------------------------------------------
#
# Project created by QtCreator 2014-05-08T16:31:11
#
#-------------------------------------------------

QT       += core
QT       +=multimedia

QT       -= gui

TARGET = Tyapu-console
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    consoleui.cpp \
    ../Tyapu-daemon/core.cpp

HEADERS += \
    consoleui.h \
    ../Tyapu-daemon/core.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Tyapu-interface/release/ -lTyapu-interface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Tyapu-interface/debug/ -lTyapu-interface
else:unix: LIBS += -L$$OUT_PWD/../Tyapu-interface/ -lTyapu-interface

INCLUDEPATH += $$PWD/../Tyapu-interface /usr/include/boost/
DEPENDPATH += $$PWD/../Tyapu-interface

