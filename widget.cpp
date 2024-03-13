#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEnabled(){
    ui->pbReset->setEnabled(money != 0);
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=200);
    ui->pbTang->setEnabled(money>=300);
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
    changeEnabled();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int five_hundred, hundred, fifty, ten;
    five_hundred = money / 500;
    money %= 500;
    hundred = money / 100;
    money %= 100;
    fifty = money / 50;
    money %= 50;
    ten = money / 10;

    QString msg = "";

    msg += QString::number(five_hundred);
    msg += " 500won, ";
    msg += QString::number(hundred);
    msg += " 100won, ";
    msg += QString::number(fifty);
    msg += " 50won, ";
    msg += QString::number(ten);
    msg += " 10won, ";

    mb.information(nullptr, "title", msg);

    changeMoney(0);
}

