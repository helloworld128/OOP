#include "widget.h"
#include <QApplication>
#include "games.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget;
    w->show();
    w->createGame(w);

    return a.exec();
}
