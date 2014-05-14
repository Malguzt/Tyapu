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
    std::cout << "paly                         Ejecutar tema actual.\n";
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
        std::cin >> path;
        add(path);
    }

    if(command == "play")
    {
        play();
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
