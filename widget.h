#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "games.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //constants
    //(null)

    //member functions
    Game* game;
    void createGame(QWidget* parent){game = new Game(parent); game->init();}

protected:

    void mousePressEvent(QMouseEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
