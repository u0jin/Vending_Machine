#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int n)
{

    money+=n;
    ui->lcdNumber->display(QString::number(money));


    if(money<0)
    {

        ui->lcdNumber->display(QString::number(money=0));
    }


    if(money<100)
    {
        ui->apple_100->setEnabled(false);
    }
    if(money>=100)
    {
        ui->apple_100->setEnabled(true);

    }


    if(money<200)
    {
        ui->ice_200->setEnabled(false);
    }
    if(money>=200)
    {
        ui->ice_200->setEnabled(true);

    }

    if(money<10)
    {
        ui->icecream_10->setEnabled(false);
    }
    if(money>=10)
    {
        ui->icecream_10->setEnabled(true);
    }


    if(money<150)
    {
        ui->soda_150->setEnabled(false);
    }
    if(money>=150)
    {
        ui->soda_150->setEnabled(true);
    }




}



void Widget::on_btn_10_clicked()
{
    changeMoney(10);
}

void Widget::on_apple_100_clicked()
{

   changeMoney(-100);

}

void Widget::on_ice_200_clicked()
{
    changeMoney(-200);

}

void Widget::on_soda_150_clicked()
{
    changeMoney(-150);
}

void Widget::on_icecream_10_clicked()
{

    changeMoney(-10);

}

void Widget::on_btn_50_clicked()
{
    changeMoney(+50);

}


void Widget::on_btn_100_clicked()
{
    changeMoney(+100);

}


void Widget::on_btn_500_clicked()
{
    changeMoney(+500);

}

void Widget::on_btn_return_clicked()
{
    QMessageBox msgBox;
    QString msg = "change: \n";

    int change;
    int origin_money;

    change=money%500;

    origin_money=money;

    if(money/500>=0)
    {
        msg+="$500 ="+QString::number(money/500)+"\n";
        money%=500;
    }

    if(money/100>=0||change<=0)
    {
        msg+="$100 ="+QString::number(money/100)+"\n";
        money%=100;
        change=money%100;
    }

   if(money/50>=0||change<=0)
    {
           msg+="$50 ="+QString::number(change/50)+"\n";
           money%=50;
           change=money%50;

    }

   if(money/10>=0&&change/50>=0)
   {
       msg+="$10 ="+QString::number(change/10)+"\n";
       money/=10;
       change=money%10;

    }
    msgBox.information(nullptr,"balance",msg);

    changeMoney(origin_money);

}
