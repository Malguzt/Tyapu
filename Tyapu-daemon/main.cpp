#include <QCoreApplication>
#include "daemon.h"

int main()
{
//    QCoreApplication a(argc, argv);

//    return a.exec();

    Daemon app;

    app.start();
}
