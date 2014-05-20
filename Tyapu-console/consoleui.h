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
private:
    Tyapuinterface* core;
    void list();
    void add(std::string& path);
    void play();
};

#endif // CONSOLEUI_H
