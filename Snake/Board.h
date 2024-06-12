#ifndef BOARD_H
#define BOARD_H

#include "Snake.h"
#include "Fruit.h"

class Board {
public:
    Board(int width, int height);
    void Draw(const Snake& snake, const Fruit& fruit) const;

private:
    int width;
    int height;
};

#endif // BOARD_H
