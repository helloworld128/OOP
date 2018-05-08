#include "games.h"
#include <QDebug>

QPoint Game::vertexTopLeft = QPoint(70,50);
int Game::gridSize = 60;
QPoint Game::vertexBottomRight = QPoint(530,550);

Game::~Game()
{

}

void Game::drawChess(int x,int y,int player)
{
    QImage* img;
    if(player == 0) img = new QImage("./images/stoneB.png");
    else img = new QImage("./images/stoneW.png");
    pictures[x][y]->setPixmap(QPixmap::fromImage(*img));
    pictures[x][y]->show();
    board[x][y] = player;
}

void Game::init()
{
    for(int i = 0;i < 8;i++)
        for(int j = 0;j < 8;j++)
        {
            board[i][j] = -1;
            pictures[i][j]->hide();
        }
    activePlayer = 0;
    drawChess(3,3,0);
    drawChess(4,4,0);
    drawChess(3,4,1);
    drawChess(4,3,1);
    black->display(2);
    white->display(2);
}

bool Game::canPut(int xpos, int ypos)
{
    if(board[xpos][ypos] == -1)
    {
        int dir[8][2]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        for(int i = 0;i < 8;i++)
        {
            bool flag = false;
            int x = xpos, y = ypos;
            while(0 <= x && x <= 7 && 0 <= y && y <= 7)
            {
                x += dir[i][0]; y += dir[i][1];
                if(!(0 <= x && x <= 7 && 0 <= y && y <= 7)) break;
                if(board[x][y] == -1) break;
                if(board[x][y] == 1 - activePlayer) flag = true;
                if(board[x][y] == activePlayer)
                {
                    if(flag) return true;
                    else break;
                }
            }
        }
    }
    return false;
}

void Game::update(int xpos, int ypos)
{
    int reverseList[6][2] = {0};
    int dir[8][2]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    for(int i = 0;i < 8;i++)
    {
        int x = xpos, y = ypos;
        int p = 0;
        bool valid = false;
        while(0 <= x && x <= 7 && 0 <= y && y <= 7)
        {
            x += dir[i][0]; y += dir[i][1];
            if(!(0 <= x && x <= 7 && 0 <= y && y <= 7)) break;
            if(board[x][y] != 1 - activePlayer)
            {
                if(board[x][y] == activePlayer) valid = true;
                break;
            }
            reverseList[p][0] = x; reverseList[p][1] = y; p++;
        }
        if(valid)
            for(int j = 0;j < p;j++)
                drawChess(reverseList[j][0],reverseList[j][1],activePlayer);
    }

    //Calculate chess numbers & display
    int b = 0, w = 0;
    for(int i = 0;i < 8;i++)
        for(int j = 0;j < 8;j++)
        {
            if(board[i][j] == 0) b++;
            if(board[i][j] == 1) w++;
        }
    black->display(b);
    white->display(w);
}

void Game::putChess(const QPoint &pos)
{
    int x = (pos.x() - Game::vertexTopLeft.x()) / Game::gridSize;
    int y = (pos.y() - Game::vertexTopLeft.y()) / Game::gridSize;
    //qDebug() << x << y << QString("activePlayer:") << activePlayer;

    if(canPut(x,y))
    {
        drawChess(x,y,activePlayer);
        update(x,y);
        activePlayer = 1 - activePlayer;
    }
}
