#ifndef TYAPUINTERFACE_H
#define TYAPUINTERFACE_H

#include "tyapu-interface_global.h"
#include <QMediaPlayer>

class TYAPUINTERFACESHARED_EXPORT Tyapuinterface
{

public:
    Tyapuinterface();
    virtual void addSong(QString &path) = 0;
    virtual QObjectList playList() = 0;
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
};

#endif // TYAPUINTERFACE_H
