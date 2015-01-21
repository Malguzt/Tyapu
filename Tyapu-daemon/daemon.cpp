#include "daemon.h"
#include <QDebug>
#include <QtNetwork>

Daemon::Daemon()
    : tcpServer(0), networkSession(0)
{
    QNetworkConfigurationManager manager;

    if(manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("TyapuDaemon"));
        settings.beginGroup(QLatin1String("TyapuNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();
    } else {
        sessionOpened();
    }
}

void Daemon::sessionOpened()
{
    if(networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;

        if(config.type() == QNetworkConfiguration::UserChoice)
        {
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        } else {
            id = config.identifier();
        }

        QSettings settings(QSettings::UserScope, QLatin1String("TyapuDaemon"));
        settings.beginGroup(QLatin1String("TyapuNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen())
    {
        qDebug() << "Unable to start the server: " << tcpServer->errorString();

        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();

    for(int i = 0; i < ipAddress.size(); ++i)
    {
        if(ipAddressList.at(i) != QHostAddress::LocalHost && ipAddressList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressList.at(i).toString();

            break;
        }
    }

    if(ipAddress.isEmpty())
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    qDebug() << "The server is running on\n\nIP: " << ipAddress << endl << "port: " << tcpServer->serverPort() << endl;
}

void Daemon::start()
{
}
