#include "Snake.h"

Snake::Snake(int startX, int startY) : direction(' ') {
    body.push_back({ startX, startY });
}

void Snake::Move() {
    std::pair<int, int> head = body.front();
    switch (direction) {
    case 'w': head.second--; break;
    case 's': head.second++; break;
    case 'a': head.first--; break;
    case 'd': head.first++; break;
    }
    body.insert(body.begin(), head);
    body.pop_back();
}

void Snake::Grow() {
    body.push_back(body.back());
}

bool Snake::CheckCollision() const {
    const std::pair<int, int>& head = body.front();
    for (size_t i = 1; i < body.size(); ++i) {
        if (head == body[i]) {
            return true;
        }
    }
    return false;
}

bool Snake::CheckSelfCollision() const {
    return CheckCollision();
}

std::pair<int, int> Snake::GetHeadPosition() const {
    return body.front();
}

const std::vector<std::pair<int, int>>& Snake::GetBody() const {
    return body;
}

void Snake::SetDirection(char dir) {
    direction = dir;
}
