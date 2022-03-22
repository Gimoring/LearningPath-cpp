#include <iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N = 5;

enum DIR
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
};

void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++) 
        {
            cout << setfill('0') << setw(2) << board[y][x] << " ";
        }
        cout << endl;
    }
}

bool CanGo(int y, int x)
{
    if (y < 0 || y >= N)
        return false;
    if (x < 0 || x >= N)
        return false;
    if (board[y][x] != 0)
        return false;
    return true;
}

void SetBoard()
{
    int dir = RIGHT;
    int num = 1;
    int y = 0;
    int x = 0;

    while (true)
    {
        board[y][x] = num;
        cout << num << endl;
        if(num == N * N)
            break;
        
        int nextY;
        int nextX;

        
        switch(dir)
        {
        case RIGHT:
            nextY = y;
            nextX = x+1;
            break;
        case DOWN:
            nextY = y+1;
            nextX = x;
            break;
        case LEFT:
            nextY = y;
            nextX = x-1;
            break;
        case UP:
            nextY = y-1;
            nextX = x;
            break;   
        }
        
        
        if (CanGo(nextY, nextX))
        {
            y = nextY;
            x = nextX;
            num++;
        }
        else
        {
            switch(dir)
            {
            case RIGHT:
                dir = DOWN;
                break;
            case DOWN:
                dir = LEFT;
                break;
            case LEFT:
                dir = UP;
                break;
            case UP:
                dir = RIGHT;
                break;
            }
        }
        
    }
}

int main()
{
    // cin >> N;

    SetBoard();

    PrintBoard();
}
