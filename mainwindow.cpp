#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(calcClicked()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(calcClicked()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(calcClicked()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(calcClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculate(const QString& op){
    bool ok_1;
    bool ok_2;
    int num1 = ui->lineEdit_num1->text().toInt(&ok_1);
    int num2 = ui->lineEdit_num2->text().toInt(&ok_2);
    if(ok_1 && ok_2){
        if(op == "+"){
            return QString::number(num1 + num2);
        }
        if(op == "-"){
            return QString::number(num1 - num2);
        }

        if(op == "*"){
            return QString::number(num1 * num2);
        }
        if(op == "/"){
            if( num2 == 0) return "Error";
            return QString::number(num1 / num2);
        }
    }

    return "Error";
}



void MainWindow::calcClicked(){
    QPushButton  *button = (QPushButton *)sender(); //возвращает кнопку
    ui->lineEdit_operator->setText(button->text());
    ui->lineEdit_result->setText(calculate(button->text()));
}




