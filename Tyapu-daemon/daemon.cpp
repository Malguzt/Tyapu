#include "daemon.h"
#include <QDebug>
#include <QtNetwork>
#include <QDataStream>

Daemon::Daemon()
    : tcpServer(new QTcpServer()), networkSession(0)
{
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!tcpServer->listen(QHostAddress::Any, 50000)){
        qDebug() << "No escucho nada";
    }
}

bool Daemon::isRuning()
{
    return true;
}

void Daemon::newConnection()
{
    QTcpSocket * client = tcpServer->nextPendingConnection();

    while(client->state() == QAbstractSocket::ConnectedState)
    {
        client->waitForReadyRead(1500);
        if(client->bytesAvailable() > 0)
        {
            onReadyRead(client);
        }
    }

//    connect(client, SIGNAL(finished()), this, SLOT(onFinishedConnection()));
}

void Daemon::r_play()
{
    qDebug() << "Play a song";
}

void Daemon::onReadyRead(QTcpSocket *client)
{
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_5_3);

    QString cmd;

    in >> cmd;

    if(cmd == "play"){
        r_play();
    }
}
