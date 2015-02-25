#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "../Tyapu-interface/tyapuinterface.h"

class QTcpSocket;
class QNetworkSession;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_clicked();
    void on_play_clicked();
    void on_playlist_doubleClicked(const QModelIndex &index);
    void on_pause_clicked();
    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    Tyapuinterface* core;
    void addItems(const QList<QString> &items);
    QTcpSocket *tcpSocket;
    quint16 blockSize;
    QNetworkSession *networkSession;
    void sendToDaemon(QString command);
    void sendToDaemon(QVariant options);
};

#endif // MAINWINDOW_H
