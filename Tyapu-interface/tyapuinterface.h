#ifndef TYAPUINTERFACE_H
#define TYAPUINTERFACE_H

#include <iostream>
#include <vector>
#include "tyapu-interface_global.h"

class TYAPUINTERFACESHARED_EXPORT Tyapuinterface
{

public:
    Tyapuinterface();
    virtual ~Tyapuinterface(){};
    virtual QList<QString> addSong(QString path) = 0;
    virtual QList<QString> addSong(QList<QString> paths) = 0;
    virtual QList<QString> playList() = 0;
    virtual int playListCount() = 0;
    virtual QString actualSong() = 0;
    virtual int actualSongIndex() = 0;
    virtual bool isMuted() = 0;
    virtual int volume() = 0;
    virtual void setVolume(int value) = 0;
    virtual void pause() = 0;
    virtual void play() = 0;
    virtual void mute() = 0;
    virtual void unmute() = 0;
    virtual void stop() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual void selectSong(int index) = 0;
    QString fileName(int index);
};

#endif // TYAPUINTERFACE_H
