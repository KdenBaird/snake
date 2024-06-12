#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Fruit.h"
#include "Board.h"

class Game {
public:
    Game(int width, int height);
    void Run();

private:
    void Setup();
    void Input();
    void Logic();
    void Draw();

    bool gameOver;
    Snake snake;
    Fruit fruit;
    Board board;
    int score;
};

#endif // GAME_H
