#ifndef DAEMON_H
#define DAEMON_H
#include <QObject>
#include "core.h"

class QTcpServer;
class QTcpSocket;
class QNetworkSession;

class Daemon : public QObject, public Core
{
    Q_OBJECT
public:
    Daemon();
    bool isRuning();
    QTcpServer *tcpServer;
    virtual ~Daemon(){}
private slots:
    void newConnection();
    void r_play();
private:
    void onReadyRead(QTcpSocket * client);
    QNetworkSession *networkSession;
};

#endif // DAEMON_H
