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
    player.playlist()->addMedia(QUrl::fromLocalFile(QString(path.c_str())));
}

void Core::addSong(vector<string> paths)
{
    QList<QMediaContent> songs;
    int max = paths.size();
    for(int i = 0; i < max; i++)
    {
        cout << "Se agrega: " << paths[i] << endl;
        songs.append(QMediaContent(QUrl::fromLocalFile(QString(paths[i].c_str()))));
    }
}

string* Core::playList()
{
    int totalSongs = player.playlist()->mediaCount();
    string* songs = new string[totalSongs];

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

string Core::actualSong()
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
