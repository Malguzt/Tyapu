#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Tyapu-interface/tyapuinterface.h"

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

private:
    Ui::MainWindow *ui;
    Tyapuinterface* core;
};

#endif // MAINWINDOW_H
