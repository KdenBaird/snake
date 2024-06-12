#include "Board.h"
#include <iostream>

Board::Board(int width, int height) : width(width), height(height) {}

void Board::Draw(const Snake& snake, const Fruit& fruit) const {
    std::vector<std::vector<char>> screen(height, std::vector<char>(width, ' '));

    for (int i = 0; i < width; ++i) {
        screen[0][i] = '#';
        screen[height - 1][i] = '#';
    }
    for (int i = 0; i < height; ++i) {
        screen[i][0] = '#';
        screen[i][width - 1] = '#';
    }

    for (const auto& segment : snake.GetBody()) {
        screen[segment.second][segment.first] = 'o';
    }

    auto head = snake.GetHeadPosition();
    screen[head.second][head.first] = 'O';

    auto fruitPos = fruit.GetPosition();
    screen[fruitPos.second][fruitPos.first] = 'F';

    // This code ChatGPT assisted with as a result of my initial code cout << "cls" which clears the screen this line of code was an attempt
    // to not have the board or screen be so glitchy...
    std::cout << "\033[2J\033[H";
    for (const auto& row : screen) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << '\n';
    }
}
