#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h> // For fcntl, F_GETFL, F_SETFL, and O_NONBLOCK
#include <vector>
#include <ctime>
using namespace std;

class SnakeGame
{
private:
    enum Direction
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    const int width;
    const int height;
    int headX, headY, fruitX, fruitY, score;
    vector<pair<int, int>> tail;
    Direction dir;
    bool gameOver;

    int _kbhit()
    {
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (ch != EOF)
        {
            ungetc(ch, stdin);
            return 1;
        }

        return 0;
    }

public:
    SnakeGame(int w, int h) : width(w), height(h), score(0), dir(STOP), gameOver(false)
    {
        setup();
    }

    void setup()
    {
        gameOver = false;
        dir = STOP;
        headX = width / 2;
        headY = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail.clear();
        score = 0;
    }

    void draw()
    {
        system("clear");

        // Upper Border
        for (int i = 0; i < width; ++i)
            cout << "#";
        cout << endl;

        // Middle Rows
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (j == 0 || j == width - 1)
                {
                    cout << "#"; // Borders
                }
                else if (i == headY && j == headX)
                {
                    cout << "O"; // Snake Head
                }
                else if (i == fruitY && j == fruitX)
                {
                    cout << "*"; // Fruit
                }
                else
                {
                    bool isTail = false;
                    for (auto segment : tail)
                    {
                        if (segment.first == j && segment.second == i)
                        {
                            cout << "o"; // Snake Tail
                            isTail = true;
                            break;
                        }
                    }
                    if (!isTail)
                        cout << " ";
                }
            }
            cout << endl;
        }

        // Lower Border
        for (int i = 0; i < width; ++i)
            cout << "#";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            switch (getchar())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            }
        }
    }

    void logic()
    {
        // Update Tail
        if (!tail.empty())
        {
            tail.insert(tail.begin(), {headX, headY});
            tail.pop_back();
        }

        // Move Snake
        switch (dir)
        {
        case LEFT:
            headX--;
            break;
        case RIGHT:
            headX++;
            break;
        case UP:
            headY--;
            break;
        case DOWN:
            headY++;
            break;
        default:
            break;
        }

        // Wrap Around Walls
        if (headX >= width)
            headX = 0;
        if (headX < 0)
            headX = width - 1;
        if (headY >= height)
            headY = 0;
        if (headY < 0)
            headY = height - 1;

        // Check Collision with Tail
        for (auto segment : tail)
        {
            if (segment.first == headX && segment.second == headY)
            {
                gameOver = true;
                return;
            }
        }

        // Check if Fruit is Eaten
        if (headX == fruitX && headY == fruitY)
        {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            tail.push_back({-5, -5});
        }
    }

    bool isGameOver() const
    {
        return gameOver;
    }
};

int main()
{
    srand(time(0));
    SnakeGame game(20, 20);

    while (!game.isGameOver())
    {
        game.draw();
        game.input();
        game.logic();
        usleep(100000); // Sleep for 100ms
    }

    cout << "Game Over!" << endl;
    return 0;
}
