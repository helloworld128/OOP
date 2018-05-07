#ifndef GAMES_H
#define GAMES_H
#include <QPoint>
#include <QLabel>

class Game
{
public:

    Game::Game(QWidget* parent)
    {
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++)
            {
                pictures[i][j] = new QLabel(parent);
                pictures[i][j]->setText("hi");
                pictures[i][j]->move(700,280);
                pictures[i][j]->show();
            }
    }
    virtual ~Game();
    //0-Reversi; 1-Gobang; 2-Go
    int gameType = 0;
    void putChess(const QPoint& pos);
    static QPoint vertexTopLeft;
    static QPoint vertexBottomRight;
    static int gridSize;
private:
    QLabel* pictures[9][9];
    int board[9][9];
};

#endif // GAMES_H
