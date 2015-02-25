#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include "../Tyapu-daemon/core.h"
#include <QDebug>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkSession(0)
{
    core = new Core();
    ui->setupUi(this);
    ui->messages->setText(tr("Iniciando"));

    QString name = QHostInfo::localHostName();

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    tcpSocket = new QTcpSocket(this);
    tcpSocket->setProperty("name", "Gui interface");

    tcpSocket->abort();
    tcpSocket->connectToHost(QHostInfo::localHostName(), 50000);
    tcpSocket->waitForConnected();

    if (tcpSocket->state() == 3)
    {
        ui->messages->setText(tr("Se conecto el demonio."));
    }

}

MainWindow::~MainWindow()
{
    delete core;
    delete ui;
}

void MainWindow::on_add_clicked()
{
    QStringList options = QFileDialog::getOpenFileNames();
    options.insert(0, "add"); //The fires option is the command.

    sendToDaemon(options);
//    addItems(core->addSong());
}

void MainWindow::addItems(const QList<QString> &items)
{
    ui->playlist->clear();
    ui->playlist->addItems(items);
}

void MainWindow::sendToDaemon(QString command)
{
    QStringList options;
    options.append(command);

    sendToDaemon(options);
}

void MainWindow::sendToDaemon(QVariant options)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);

    out << QJsonDocument::fromVariant(options).toJson(QJsonDocument::Compact);

    tcpSocket->write(block);
    if(!tcpSocket->flush()){
        ui->messages->setText(tr("No se puede conectar con el servidor"));
    }
}

void MainWindow::on_play_clicked()
{
    sendToDaemon(QString("play"));
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
