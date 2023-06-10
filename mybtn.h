#ifndef MYBTN_H
#define MYBTN_H

#include <QPushButton>

class MyBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit MyBtn(QWidget *parent = nullptr);

    void enterEvent(QEnterEvent *);

    void leaveEvent(QEvent *);

signals:
    void isEnter();

    void isLeave();
};

#endif // MYBTN_H
