#include <iostream>
#include <vector>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep() and console functions
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point
{
    int x, y;
};

class SnakeGame
{
private:
    vector<Point> snake;
    Point food;
    int width, height;
    int score;
    char direction; // 'L', 'R', 'U', 'D'
    bool gameOver;

    void generateFood()
    {
        while (true)
        {
            food.x = rand() % width;
            food.y = rand() % height;

            bool onSnake = false;
            for (auto &s : snake)
            {
                if (s.x == food.x && s.y == food.y)
                {
                    onSnake = true;
                    break;
                }
            }

            if (!onSnake)
                break;
        }
    }

    void draw()
    {
        // Clear only the console screen area being used
        COORD coord = {0, 0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        for (int i = 0; i < width + 2; ++i)
            cout << "#";
        cout << endl;

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width + 2; ++x)
            {
                if (x == 0 || x == width + 1)
                {
                    cout << "#";
                }
                else
                {
                    bool printed = false;
                    if (x - 1 == food.x && y == food.y)
                    {
                        cout << "*";
                        printed = true;
                    }
                    else
                    {
                        for (size_t i = 0; i < snake.size(); ++i)
                        {
                            if (snake[i].x == x - 1 && snake[i].y == y)
                            {
                                cout << (i == 0 ? "0" : "o");
                                printed = true;
                                break;
                            }
                        }
                    }
                    if (!printed)
                        cout << " ";
                }
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; ++i)
            cout << "#";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void update()
    {
        Point newHead = snake[0];
        if (direction == 'L')
            --newHead.x;
        else if (direction == 'R')
            ++newHead.x;
        else if (direction == 'U')
            --newHead.y;
        else if (direction == 'D')
            ++newHead.y;

        if (newHead.x < 0 || newHead.x >= width || newHead.y < 0 || newHead.y >= height)
        {
            gameOver = true;
            return;
        }

        for (auto &s : snake)
        {
            if (s.x == newHead.x && s.y == newHead.y)
            {
                gameOver = true;
                return;
            }
        }

        snake.insert(snake.begin(), newHead);

        if (newHead.x == food.x && newHead.y == food.y)
        {
            score++;
            generateFood();
        }
        else
        {
            snake.pop_back();
        }
    }

    char getArrowKey()
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == -32 || key == 224)
            { // Arrow key prefix
                char arrow = _getch();
                if (arrow == 72)
                    return 'U'; // Up arrow
                if (arrow == 80)
                    return 'D'; // Down arrow
                if (arrow == 75)
                    return 'L'; // Left arrow
                if (arrow == 77)
                    return 'R'; // Right arrow
            }
        }
        return 0;
    }

    void hideCursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(consoleHandle, &cursorInfo);
        cursorInfo.bVisible = false; // Hide the cursor
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }

    void showCursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(consoleHandle, &cursorInfo);
        cursorInfo.bVisible = true; // Show the cursor
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }

public:
    SnakeGame(int w, int h) : width(w), height(h), score(0), direction('R'), gameOver(false)
    {
        snake.push_back({w / 2, h / 2});
        srand(time(0));
        generateFood();
    }

    void run()
    {
        hideCursor(); // Hide cursor at the start of the game
        while (!gameOver)
        {
            char key = getArrowKey();
            if (key && key != direction)
            {
                if (key == 'L' && direction != 'R')
                    direction = 'L';
                else if (key == 'R' && direction != 'L')
                    direction = 'R';
                else if (key == 'U' && direction != 'D')
                    direction = 'U';
                else if (key == 'D' && direction != 'U')
                    direction = 'D';
            }

            update();
            draw();
            Sleep(100); // Adjust speed
        }
        showCursor(); // Restore cursor visibility when the game ends

        cout << "GAME OVER!" << endl;
        // score = 10000000;
        cout << "Final Score: " << score << endl;
    }
};

int main()
{
    SnakeGame game(30, 15); // 30x15 grid
    game.run();
    return 0;
}