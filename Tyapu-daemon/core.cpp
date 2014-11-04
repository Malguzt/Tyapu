#include <QUrl>
#include <QMediaPlaylist>
#include <QFileInfo>
#include <QDebug>
using namespace std;

#include "core.h"

Core::Core()
{
    player.setPlaylist(new QMediaPlaylist);
    player.setVolume(100);
}

Core::~Core()
{

}

QList<QString> Core::addSong(QString path)
{
    QFileInfo info(path);
    if(info.suffix() == "MP3" || info.suffix() == "mp3" || info.suffix() == "ogg" || info.suffix() == "wave")
    {
        player.playlist()->addMedia(QUrl::fromLocalFile(path));
        qDebug() << "Se agrega: " << path << endl;
    }

    return playList();
}

QList<QString> Core::addSong(QList<QString> paths)
{
    int max = paths.size();
    for(int i = 0; i < max; i++)
    {
        addSong(paths[i]);
    }

    return playList();
}

QList<QString> Core::playList()
{
    int totalSongs = playListCount();
    QList<QString> songs;

    for(int i = 0; i < totalSongs; i++)
    {
        songs.push_back(fileName(i));
    }

    return songs;
}

int Core::playListCount()
{
    return player.playlist()->mediaCount();
}

QString Core::fileName(int index)
{
    return player.playlist()->media(index).resources()[0].url().fileName();
}

QString Core::actualSong()
{
    return fileName(actualSongIndex());
}

int Core::actualSongIndex()
{
    return player.playlist()->currentIndex();
}

bool Core::isMuted()
{
    return player.isMuted();
}

int Core::volume()
{
    return player.volume();
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
    player.setVolume(100);
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
    cout << index << endl;
}
