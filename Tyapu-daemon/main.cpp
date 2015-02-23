#include <QCoreApplication>
#include "daemon.h"
#include <QTcpServer>

int main()
{
//    QCoreApplication a(argc, argv);

//    return a.exec();

    Daemon d;
    while(d.isRuning()){
        d.tcpServer->waitForNewConnection(1500);
    }

    return 1;
}
