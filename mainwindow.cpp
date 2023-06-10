 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timerId1 = startTimer(1000);
    timerId2 = startTimer(5000);

    //QTimer * timer = new QTimer(this);


    connect(this,&MainWindow::timeOut,this,[=](){
        QMessageBox::StandardButton ret1  =QMessageBox::information(this,"information","时间到!");
        if(ret1)
            this->close();
    });

    connect(ui->btnRight,&MyBtn::isEnter,this,[=]{
        if(ui->btnLeft->text() == "是")
        {
            ui->btnRight->setText(QString("是"));
            ui->btnLeft->setText(QString("否"));
        }
    });
    connect(ui->btnRight,&MyBtn::clicked,this,[=]{
        if(ui->btnLeft->text() == "是")
        {
            ui->btnRight->setText(QString("是"));
            ui->btnLeft->setText(QString("否"));
        }
        else
            {
            QMessageBox::information(this,"information","为什么不选否");
        }
    });


    connect(ui->btnLeft,&MyBtn::isEnter,this,[=]{
        if(ui->btnRight->text() == "是")
        {
            ui->btnLeft->setText(QString("是"));
            ui->btnRight->setText(QString("否"));
        }
    });
    connect(ui->btnLeft,&MyBtn::clicked,this,[=]{
        if(ui->btnRight->text() == "是")
        {
            ui->btnLeft->setText(QString("是"));
            ui->btnRight->setText(QString("否"));
        }
        else
        {
            QMessageBox::information(this,"information","为什么不选否");
        }
    });

}

void MainWindow::timerEvent(QTimerEvent *tEvent)
{
    if(tEvent->timerId() == timerId1)
    {
        static int time = 20;
        ui->lblTimer->setText(QString::number(--time)+"秒");
        if(time == 0)
        {
            emit timeOut();
            killTimer(timerId1);
        }
    }
    if(tEvent->timerId() == timerId2)
    {
        static int time = 0;
        QMessageBox::information(this,"information",QString("时间已过")+QString::number(time+=5)+QString("秒"));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

