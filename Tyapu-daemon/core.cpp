#include <QUrl>
#include <QMediaPlaylist>

#include "core.h"

Core::Core()
{
    player.setPlaylist(new QMediaPlaylist);
    player.setVolume(100);
}

void Core::addSong(std::string &path)
{
    player.playlist()->addMedia(QUrl::fromLocalFile(QString(path.c_str())));
}

std::string* Core::playList()
{
    int totalSongs = player.playlist()->mediaCount();
    std::string* songs = new std::string[totalSongs];

    for(int i = 0; i < totalSongs; i++)
    {
        songs[i] = player.playlist()->media(i).resources()[0].url().fileName().toStdString();
    }

    return songs;
}

int Core::playListCount()
{
    return 3;
}

std::string Core::actualSong()
{
    return "Un tema super copado.";
}

int Core::actualSongIndex()
{
    return 3;
}

bool Core::isMuted()
{
    return player.isMuted();
}

int Core::volume()
{
    player.volume();
}

void Core::setVolume(int value)
{
    player.setVolume(value);
}

void Core::pause()
{
    player.pause();
}

void Core::play()
{
    player.play();
}

void Core::mute()
{
    player.setMuted(true);
}

void Core::unmute()
{
    player.setMuted(false);
}

void Core::stop()
{
    player.stop();
}

void Core::next()
{
    player.playlist()->next();
}

void Core::previous()
{
    player.playlist()->previous();
}

void Core::selectSong(int index)
{

}
