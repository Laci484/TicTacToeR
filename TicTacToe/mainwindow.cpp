#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NewGame(){
    clickcounter = 0;
    for(int i=0;i<9;i++){
        clickedB[i] = 0;
    }
    ui->bf->setEnabled(true);
    ui->bf->setText("");

    ui->kf->setEnabled(true);
    ui->kf->setText("");

    ui->jf->setEnabled(true);
    ui->jf->setText("");

    ui->bk->setEnabled(true);
    ui->bk->setText("");

    ui->kk->setEnabled(true);
    ui->kk->setText("");

    ui->jk->setEnabled(true);
    ui->jk->setText("");

    ui->bl->setEnabled(true);
    ui->bl->setText("");

    ui->kl->setEnabled(true);
    ui->kl->setText("");

    ui->jl->setEnabled(true);
    ui->jl->setText("");

    ui->label->setText("1. Játékos lép!");

    szimbol = true;
    win=true;
}

void MainWindow::Winner(){
    if(clickcounter == 9){
        ui->label->setText("");
        QMessageBox::warning(nullptr, QString("Játék Vége!"), QString("Döntetlen!"));
        NewGame();
        return;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<3;j++){
            if(clickedB[winComb[i][j]] != player){
                win = false;
                break;
            }
        }
        if(win){
            ui->label->setText("");
            QMessageBox::warning(nullptr, QString("Játék Vége!"),QString("Győztes: "+QString::number(player)+". játékos"));
            NewGame();
            break;
        }
        win = true;
    }
    return;
}


void MainWindow::setSimbol(QPushButton* bt, int buttonIndex){
    if(szimbol){
        bt->setText("X");
        bt->setDisabled(true);
        szimbol = false;
        clickcounter++;
        player = 1;
        clickedB[buttonIndex] = 1;
        ui->label->setText("2. Játékos lép!");
    }
    else{
        bt->setText("O");
        bt->setDisabled(true);
        szimbol = true;
        clickcounter++;
        player=2;
        clickedB[buttonIndex] = 2;
        ui->label->setText("1. Játékos lép!");
    }
    Winner();
}

void MainWindow::on_bf_clicked()
{
    setSimbol(ui->bf,0);
}

void MainWindow::on_kf_clicked()
{
    setSimbol(ui->kf,1);
}



void MainWindow::on_jf_clicked()
{
    setSimbol(ui->jf,2);
}


void MainWindow::on_bk_clicked()
{
    setSimbol(ui->bk,3);
}

void MainWindow::on_kk_clicked()
{
    setSimbol(ui->kk,4);
}

void MainWindow::on_jk_clicked()
{
    setSimbol(ui->jk,5);
}

void MainWindow::on_bl_clicked()
{
    setSimbol(ui->bl,6);
}

void MainWindow::on_kl_clicked()
{
    setSimbol(ui->kl,7);
}

void MainWindow::on_jl_clicked()
{
    setSimbol(ui->jl,8);
}

