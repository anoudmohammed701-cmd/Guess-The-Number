#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secretNumber = QRandomGenerator::global()->bounded(1, 101);
    attempts = 0;
    ui->spinBox->setRange(1, 100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int guess = ui->spinBox->value();

    attempts++;

    ui->attemptsLabl->setText(
        "Attempts: " + QString::number(attempts)
        );

    if (guess > secretNumber)
    {
        ui->resultLabel->setText("Too High! Try Again!");
    }
    else if (guess < secretNumber)
    {
        ui->resultLabel->setText("Too Low! Try Again!");
    }
    else
    {
        ui->resultLabel->setText("YOU WIN! Congratulations!");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    secretNumber = QRandomGenerator::global()->bounded(1, 101);

    attempts = 0;

    ui->attemptsLabl->setText("Attempts: 0");

    ui->resultLabel->setText("Make Your First Guess");

    ui->spinBox->setValue(1);
}

