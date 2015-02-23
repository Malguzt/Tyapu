#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include "../Tyapu-daemon/core.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkSession(0)
{
    core = new Core();
    ui->setupUi(this);
    ui->messages->setText("Starting.");

    QString name = QHostInfo::localHostName();

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    tcpSocket = new QTcpSocket(this);

//    connect(tcpSocket, SIGNAL());
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostInfo::localHostName(), 50000);
    tcpSocket->waitForConnected();
    ui->messages->setText(QString::number(tcpSocket->state()));
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);

    out << QString("play");

    tcpSocket->write(block);
    tcpSocket->flush();
    ui->messages->setText(QString::number(tcpSocket->state()));
}

MainWindow::~MainWindow()
{
    delete core;
    delete ui;
}

void MainWindow::on_add_clicked()
{
    addItems(core->addSong(QFileDialog::getOpenFileNames()));
}

void MainWindow::addItems(const QList<QString> &items)
{
    ui->playlist->clear();
    ui->playlist->addItems(items);
}

void MainWindow::on_play_clicked()
{
    core->play();
}

void MainWindow::on_playlist_doubleClicked(const QModelIndex &index)
{
    core->selectSong(index.row());
    core->play();
}

void MainWindow::on_pause_clicked()
{
    core->pause();
}

void MainWindow::on_stop_clicked()
{
    core->stop();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch(socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        ui->messages->setText(tr("The host was not found. Please check the host name and port sttings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        ui->messages->setText(tr("The connection was refused by the peer.\nMake sure the fortune server is running, and check that the host name and port settings are correct."));
        break;
    default:
        ui->messages->setText(tr("The following error occurred: %1").arg(tcpSocket->errorString()));
    }
}

void MainWindow::sessionOpened()
{
    QNetworkConfiguration config = networkSession->configuration();
    QString id;

    if(config.type() == QNetworkConfiguration::UserChoice)
    {
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    } else {
        id = config.identifier();
    }

    QSettings settings(QSettings::UserScope, QLatin1String("Tyapu"));
    settings.beginGroup(QLatin1String("TyapuNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

    ui->messages->setText(tr("Client opened."));
}
