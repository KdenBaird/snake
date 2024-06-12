#ifndef FRUIT_H
#define FRUIT_H

#include <utility>
#include <vector>

class Fruit {
public:
    Fruit(int width, int height);
    void GenerateNewPosition(const std::vector<std::pair<int, int>>& snakeBody);
    std::pair<int, int> GetPosition() const;

private:
    int width;
    int height;
    std::pair<int, int> position;
};

#endif // FRUIT_H
