#-------------------------------------------------
#
# Project created by QtCreator 2014-05-14T10:48:24
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tyapu-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Tyapu-daemon/core.cpp

HEADERS  += mainwindow.h \
    ../Tyapu-daemon/core.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Tyapu-interface/release/ -lTyapu-interface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Tyapu-interface/debug/ -lTyapu-interface
else:unix: LIBS += -L$$OUT_PWD/../Tyapu-interface/ -lTyapu-interface

INCLUDEPATH += $$PWD/../Tyapu-interface
DEPENDPATH += $$PWD/../Tyapu-interface
