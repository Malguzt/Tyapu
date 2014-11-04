#include "consoleui.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "../Tyapu-daemon/core.h"

using namespace std;
using namespace boost::algorithm;

ConsoleUI::ConsoleUI()
{
    core = new Core();
}

void ConsoleUI::printWelcome()
{
    cout << "Bienvenido a Tyapu, el mejor reproductor de música del NO mercado.\n";
    cout << "Escribe 'ayuda' para ver las opciones.\n";
}

void ConsoleUI::printConsole()
{
    cout << ">";
}

void ConsoleUI::printHelp()
{
    cout << "agregar <ruta>               Agrega de manera recursiva los archivos de una ruta.\n";
    cout << "ejecutar                     Ejecutar el tema actual.\n";
    cout << "pausa                        Pausar ejecución.\n";
    cout << "parar                        Parar ejecución.\n";
    cout << "siguiente                    Pasar de tema.\n";
    cout << "anterior                     Volver al tema anterior.\n";
    cout << "listar                       Ver la lista de temas.\n";
    cout << "silenciar                    Poner en silencio la ejecucón.\n";
    cout << "noSilenciar                  Vuelve a poner tu molesta música.\n";
    cout << "volumen <0-100>              Valor entre 0 y 100 para el volumen.\n";

}

void ConsoleUI::list()
{
    string* songs = core->playList();

    for(int i = 0; i < core->playListCount(); i++)
    {
        cout << songs[i] << endl;
    }
}

void ConsoleUI::printEasterEgg()
{
    cout << "Acá tenes tu huevo\n";
    sleep(2);
    cout << "******** @-@-@*********\n";
    cout << "****** @————–—–@*******\n";
    cout << "**** @————————––—@*****\n";
    cout << "*** @——- Felices——@****\n";
    cout << "** @——– Pascuas——–—@***\n";
    cout << "** @——(\\(\\——————–——@***\n";
    cout << "** @——(^.^)—–—————–@***\n";
    cout << "** @—*(..(“)(“).———@***\n";
    cout << "*** @—————————–———@****\n";
    cout << "***** @———————–—@******\n";
    cout << "******* @-@-@-@********\n";
}

void ConsoleUI::runCommand(string& command)
{
    if(command == "ayuda")
    {
        printHelp();
    }

    if(command == "huevoDePascuas")
    {
        printEasterEgg();
    }

    if(command == "agregar")
    {
        string path;
        getline(cin, path);
        add(path);
    }

    if(command == "volumen")
    {
        string value;
        getline(cin, value);
        setVolume(atoi(value.c_str()));
    }

    if(command == "ejecutar")
    {
        play();
    }

    if(command == "listar")
    {
        list();
    }

    if(command == "siguiente")
    {
        next();
    }

    if(command == "anterior")
    {
        previous();
    }

    if(command == "parar")
    {
        stop();
    }

    if(command == "pausa")
    {
        pause();
    }

    if(command == "silenciar")
    {
        mute();
    }

    if(command == "noSilenciar")
    {
        unmute();
    }
}

void ConsoleUI::add(string& path)
{
    vector<string> songsPahts;
    trim(path);
    songsPahts = readFolder(path);

     core->addSong(songsPahts);
     cout << "Se agregaron las pistas ubicadas en: " << path << "\n";
}

void ConsoleUI::play()
{
    core->play();
}

vector<string> ConsoleUI::readFolder(string folder)
{
    vector<string> songs;

    for(boost::filesystem::recursive_directory_iterator end, dir(folder); dir != end; ++dir)
    {
        if(dir->path().extension() == ".mp3" || dir->path().extension() == ".MP3"){
            songs.push_back(dir->path().string());
        }
    }

    return songs;

}

void ConsoleUI::next()
{
    core->next();
}

void ConsoleUI::previous()
{
    core->previous();
}

void ConsoleUI::pause()
{
    core->pause();
}

void ConsoleUI::stop()
{
    core->stop();
}

void ConsoleUI::mute()
{
    core->mute();
}

void ConsoleUI::unmute()
{
    core->unmute();
}

void ConsoleUI::setVolume(int newValue)
{
    core->setVolume(newValue);
}
