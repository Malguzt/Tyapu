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
    typedef void (Daemon::*MethodDef)(void);
public:
    Daemon();
    bool isRuning();
    QTcpServer *tcpServer;
    virtual ~Daemon(){}
private slots:
    void newConnection();
    void r_play();
    void r_add();
private:
    void onReadyRead(QTcpSocket * client);
    QNetworkSession *networkSession;
    std::map<QString, MethodDef> methodsMap;
    void mappingMethods();
};

#endif // DAEMON_H
