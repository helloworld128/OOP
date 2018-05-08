#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool operator <(const QPoint& left,const QPoint& right)
{
    return left.x() < right.x() && left.y() < right.y();
}

void Widget::mousePressEvent(QMouseEvent *qme)
{
    if(qme->button() & Qt::LeftButton)
    {
        QPoint presspos(qme->x(),qme->y());
        qDebug() << presspos;
        if(game && Game::vertexTopLeft < presspos && presspos < Game::vertexBottomRight)
        {
            game->putChess(presspos);
        }
    }
}
