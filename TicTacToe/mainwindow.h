#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setSimbol(QPushButton *bt, int buttonIndex);
    void Winner();
    void NewGame();

private slots:
    void on_bf_clicked();

    void on_kf_clicked();

    void on_jk_clicked();

    void on_jf_clicked();

    void on_bk_clicked();

    void on_kk_clicked();

    void on_bl_clicked();

    void on_kl_clicked();

    void on_jl_clicked();

private:
    Ui::MainWindow *ui;
    bool szimbol = true;
    int clickcounter = 0;
    int clickedB [9] = {0,0,0,0,0,0,0,0,0};
    int winComb [8][3] = {{0,1,2},
                          {3,4,5},
                          {6,7,8},
                          {0,3,6},
                          {1,4,7},
                          {2,5,8},
                          {2,4,6},
                          {0,4,8}};
    bool win = true;
    int player;
};
#endif // MAINWINDOW_H
