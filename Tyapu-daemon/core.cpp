#include <QUrl>
#include <QMediaPlaylist>
using namespace std;

#include "core.h"

Core::Core()
{
    player.setPlaylist(new QMediaPlaylist);
    player.setVolume(100);
}

void Core::addSong(string &path)
{
    if(player.playlist()->addMedia(QUrl::fromLocalFile(QString(path.c_str()))))
    {
        cout << "Se agrega: " << path << endl;
    }
}

void Core::addSong(vector<string> &paths)
{
    QList<QMediaContent> songs;
    int max = paths.size();
    for(int i = 0; i < max; i++)
    {
        addSong(paths[i]);
    }
}

string* Core::playList()
{
    int totalSongs = playListCount();
    string* songs = new string[totalSongs];

    for(int i = 0; i < totalSongs; i++)
    {
        songs[i] = fileName(i);
    }

    return songs;
}

int Core::playListCount()
{
    return player.playlist()->mediaCount();
}

string Core::fileName(int index)
{
    return player.playlist()->media(index).resources()[0].url().fileName().toStdString();
}

string Core::actualSong()
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
