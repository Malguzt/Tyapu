#include <QUrl>

#include "core.h"

Core::Core()
{
}

void Core::addSong(std::string &path)
{
    player.setMedia(QUrl::fromLocalFile(QString(path.c_str())));
}

void Core::play()
{
    player.play();
}
