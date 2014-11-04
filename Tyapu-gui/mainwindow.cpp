#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include "../Tyapu-daemon/core.h"

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
    ui->playlist->addItems(core->addSong(QFileDialog::getOpenFileNames()));
}

void MainWindow::on_play_clicked()
{

}
