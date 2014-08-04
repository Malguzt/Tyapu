#ifndef CORE_H
#define CORE_H
#include <QMediaPlayer>
#include "../Tyapu-interface/tyapuinterface.h"

class Core: public Tyapuinterface
{
public:
    Core();
    virtual void addSong(std::string &path);
    virtual void addSong(std::vector<std::string> paths);
    virtual std::string *playList();
    virtual int playListCount();
    virtual std::string actualSong();
    virtual int actualSongIndex();
    virtual bool isMuted();
    virtual int volume();
    virtual void setVolume(int value);
    virtual void pause();
    virtual void play();
    virtual void mute();
    virtual void unmute();
    virtual void stop();
    virtual void next();
    virtual void previous();
    virtual void selectSong(int index);
private:
    QMediaPlayer player;
};

#endif // CORE_H
