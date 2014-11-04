#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <QString>
#include <QStringList>
#include "../Tyapu-interface/tyapuinterface.h"

class ConsoleUI
{
public:
    ConsoleUI();
    ~ConsoleUI();
    void printWelcome();
    void printConsole();
    void printHelp();
    void printEasterEgg();
    void runCommand(std::string& command);
private:
    Tyapuinterface* core;
    void list();
    void add(QString path);
    void play();
    QList<QString> readFolder(QString folder);
    void next();
    void previous();
    void pause();
    void stop();
    void mute();
    void unmute();
    void setVolume(int newValue);
};

#endif // CONSOLEUI_H
