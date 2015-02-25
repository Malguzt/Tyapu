#include "daemon.h"
#include <map>
#include <QDebug>
#include <QtNetwork>
#include <QDataStream>

Daemon::Daemon()
    : tcpServer(new QTcpServer()), networkSession(0)
{
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    int port = 50000;
    if(!tcpServer->listen(QHostAddress::Any, port)){
        qDebug() << "The server can't lidyrn in port " << port << endl;
    }

    mappingMethods();
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
    play();
}

void Daemon::r_add()
{
    qDebug()  << "Add\n";
}

void Daemon::onReadyRead(QTcpSocket *client)
{
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_5_3);

    QByteArray json;
    in >> json;

    qDebug() << json << endl;
    QJsonDocument options = QJsonDocument::fromJson(json);


    (this->*methodsMap[options.array().at(0).toString()])();
}

void Daemon::mappingMethods()
{
    methodsMap.insert(std::make_pair(QString("ply"), &Daemon::r_play));
    methodsMap.insert(std::make_pair(QString("add"), &Daemon::r_add));
}
