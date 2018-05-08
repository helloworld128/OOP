#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->Board->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createGame(QWidget *parent)
{
    game = new Game(parent);
    game->black = ui->BCount_LCD;
    game->white = ui->WCount_LCD;
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


void Widget::on_Start_Button_clicked()
{
    game->init();
}
