#ifndef CORE_H
#define CORE_H
#include <QMediaPlayer>
#include "../Tyapu-interface/tyapuinterface.h"

class Core: public Tyapuinterface
{
public:
    Core();
    virtual void addSong(std::string &path);
    virtual void play();
private:
    QMediaPlayer player;
};

#endif // CORE_H
