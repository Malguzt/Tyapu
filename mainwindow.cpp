#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMediaPlayer"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    player(new QMediaPlayer)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_boton_clicked(){

}

void MainWindow::on_Add_clicked()
{
    QStringList filesNames = QFileDialog::getOpenFileNames(this, tr("Open File"), "/home/likewise-open/GLOBANT/jose.lenscak/Music", tr("Mp3 Files (*.mp3)"));
    ui->files->addItems(filesNames);
}

void MainWindow::on_Play_clicked()
{
//    ui->label->setText(ui->files->selectedItems().at(0)->text().toStdWString());
    player->setMedia(QUrl::fromLocalFile(ui->files->selectedItems().at(0)->text()));
    player->setVolume(100);
    player->play();
}
