
// These two lines of codes are called header guards. This is important to include because it ensures that this header file is only
// processed once. I was confused as to why my program wasn't running, so I chat GPT'd how to fix these errors, and it mentioned to include
// these header guards to all of my header files. This seemed to fix my errors. 
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY);
    void Move();
    void Grow();
    bool CheckCollision() const;
    bool CheckSelfCollision() const;
    std::pair<int, int> GetHeadPosition() const;
    const std::vector<std::pair<int, int>>& GetBody() const;
    void SetDirection(char dir);

private:
    std::vector<std::pair<int, int>> body;
    char direction;
};

#endif // SNAKE_H

