#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include "../Tyapu-daemon/core.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    core = new Core();
    ui->setupUi(this);
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
