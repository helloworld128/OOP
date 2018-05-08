#ifndef GAMES_H
#define GAMES_H
#include <QPoint>
#include <QLabel>
#include <QLCDNumber>

class Game
{
public:
    Game(QWidget* parent)
    {
        for(int i = 0;i < 8;i++)
            for(int j = 0;j < 8;j++)
            {
                pictures[i][j] = new QLabel(parent);
                pictures[i][j]->move(Game::vertexTopLeft.x() + i * Game::gridSize, Game::vertexTopLeft.y() + j * Game::gridSize);
            }
    }
    virtual ~Game();

    //0-Reversi; 1-Gobang; 2-Go
    int gameType = 0;

    //0-Black; 1-White
    int activePlayer = 0;

    QLCDNumber *black, *white;
    void drawChess(int x,int y, int player);
    void putChess(const QPoint& pos);
    void init();
    bool canPut(int xpos, int ypos);
    void update(int x, int y);
    static QPoint vertexTopLeft;
    static QPoint vertexBottomRight;
    static int gridSize;
private:
    QLabel* pictures[9][9];
    int board[9][9];
};

#endif // GAMES_H
