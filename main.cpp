#include "widget.h"
#include <QApplication>
#include "games.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Widget* wptr = &w;
    w.createGame(wptr);

    return a.exec();
}
