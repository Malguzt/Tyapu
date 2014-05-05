#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMediaPlayer"

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
    void on_boton_clicked();

    void on_Add_clicked();

    void on_Play_clicked();

    void on_Stop_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
