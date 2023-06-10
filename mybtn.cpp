#include "mybtn.h"

MyBtn::MyBtn(QWidget *parent)
    : QPushButton{parent}
{

}

void MyBtn::enterEvent(QEnterEvent *)
{
    emit isEnter();
}

void MyBtn::leaveEvent(QEvent *)
{
    emit isLeave();
}
