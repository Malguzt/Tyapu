#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <QString>
#include <QStringList>
#include "../Tyapu-interface/tyapuinterface.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void printWelcome();
    void printConsole();
    void printHelp();
    void printEasterEgg();
    void runCommand(std::string& command);
    void add(std::string& path);
    void play();
private:
    Tyapuinterface* core;
};

#endif // CONSOLEUI_H
