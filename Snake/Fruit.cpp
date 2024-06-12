#include "Fruit.h"
#include <cstdlib>
#include <algorithm>

Fruit::Fruit(int width, int height) : width(width), height(height) {
    GenerateNewPosition({});
}

void Fruit::GenerateNewPosition(const std::vector<std::pair<int, int>>& snakeBody) {
    do {
        position.first = rand() % (width - 2) + 1;
        position.second = rand() % (height - 2) + 1;
    } while (std::find(snakeBody.begin(), snakeBody.end(), position) != snakeBody.end());
}

std::pair<int, int> Fruit::GetPosition() const {
    return position;
}

