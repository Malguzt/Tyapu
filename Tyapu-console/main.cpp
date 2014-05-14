#include <QString>
#include <iostream>

#include "consoleui.h"

int main(int argc, char *argv[])
{
    std::string command;
    ConsoleUI console;

    console.printWelcome();

    while(command != "salir"){
        console.printConsole();
        std::cin >> command;
        console.runCommand(command);
    }
}
