#ifndef TYAPUINTERFACE_H
#define TYAPUINTERFACE_H

#include <iostream>
#include <vector>
#include "tyapu-interface_global.h"

class TYAPUINTERFACESHARED_EXPORT Tyapuinterface
{

public:
    Tyapuinterface();
    virtual void addSong(std::string &path) = 0;
    virtual void addSong(std::vector<std::string> paths) = 0;
    virtual std::string* playList() = 0;
    virtual int playListCount() = 0;
    virtual std::string actualSong() = 0;
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
