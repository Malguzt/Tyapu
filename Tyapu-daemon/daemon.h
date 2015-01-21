#ifndef DAEMON_H
#define DAEMON_H
#include <QObject>

class QTcpServer;
class QNetworkSession;

class Daemon : public QObject
{
public:
    Daemon();
    void start();
private slots:
    void sessionOpened();
private:
    QTcpServer *tcpServer;
    QNetworkSession *networkSession;
};

#endif // DAEMON_H
