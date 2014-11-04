#ifndef CORE_H
#define CORE_H
#include <QMediaPlayer>
#include "../Tyapu-interface/tyapuinterface.h"

class Core: public Tyapuinterface
{
public:
    Core();
    virtual ~Core();
    virtual QList<QString> addSong(QString path);
    virtual QList<QString> addSong(QList<QString> paths);
    virtual QList<QString> playList();
    virtual int playListCount();
    virtual QString actualSong();
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
    QString fileName(int index);
private:
    QMediaPlayer player;
};

#endif // CORE_H
