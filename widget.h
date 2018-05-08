#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QLCDNumber>
#include "games.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    Ui::Widget *ui;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //constants
    //(null)

    //member functions
    Game* game;
    void createGame(QWidget* parent);

protected:

    void mousePressEvent(QMouseEvent *);

private slots:

    void on_Start_Button_clicked();

};

#endif // WIDGET_H
