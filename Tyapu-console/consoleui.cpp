#include "consoleui.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include "../Tyapu-daemon/core.h"

ConsoleUI::ConsoleUI()
{
    core = new Core();
}

void ConsoleUI::printWelcome()
{
    std::cout << "Bienvenido a Tyapu, el mejor reproductor de música del NO mercado.\n";
    std::cout << "Escribe 'ayuda' para ver las opciones.\n";
}

void ConsoleUI::printConsole()
{
    std::cout << ">";
}

void ConsoleUI::printHelp()
{
    std::cout << "agregar <ruta>               Agrega de manera recursiva los archivos de una ruta.\n";
    std::cout << "ejecutar                     Ejecutar el tema actual.\n";
    std::cout << "pausa                        Pausar ejecución.\n";
    std::cout << "parar                        Parar ejecución.\n";
    std::cout << "siguiente                    Pasar de tema.\n";
    std::cout << "anterior                     Volver al tema anterior.\n";
    std::cout << "listar                       Ver la lista de temas.\n";
    std::cout << "silenciar                    Poner en silencio la ejecucón.\n";
    std::cout << "noSilenciar                  Vuelve a poner tu molesta música.\n";
    std::cout << "volumen <0-100>              Valor entre 0 y 100 para el volumen.\n";

}

void ConsoleUI::list()
{
    std::string* songs = core->playList();

    for(int i = 0; i < core->playListCount(); i++)
    {
        std::cout << songs[i] << std::endl;
    }
}

void ConsoleUI::printEasterEgg()
{
    std::cout << "Acá tenes tu huevo\n";
    sleep(2);
    std::cout << "******** @-@-@*********\n";
    std::cout << "****** @————–—–@*******\n";
    std::cout << "**** @————————––—@*****\n";
    std::cout << "*** @——- Felices——@****\n";
    std::cout << "** @——– Pascuas——–—@***\n";
    std::cout << "** @——(\\(\\——————–——@***\n";
    std::cout << "** @——(^.^)—–—————–@***\n";
    std::cout << "** @—*(..(“)(“).———@***\n";
    std::cout << "*** @—————————–———@****\n";
    std::cout << "***** @———————–—@******\n";
    std::cout << "******* @-@-@-@********\n";
}

void ConsoleUI::runCommand(std::string& command)
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
        std::string path;
        std::getline(std::cin, path);
        add(path);
    }

    if(command == "ejecutar")
    {
        play();
    }

    if(command == "listar")
    {
        list();
    }
}

void ConsoleUI::add(std::string& path)
{
    core->addSong(path);
    std::cout << "Se agregaron las pistas ubicadas en: " << path << "\n";
}

void ConsoleUI::play()
{
    core->play();
}
