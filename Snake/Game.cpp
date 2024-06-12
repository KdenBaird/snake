#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

Game::Game(int width, int height)
    : gameOver(false), snake(width / 2, height / 2), fruit(width, height), board(width, height), score(0) {}

void Game::Setup() {
    gameOver = false;
    score = 0;
}

void Game::Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': snake.SetDirection('a'); break;
        case 'd': snake.SetDirection('d'); break;
        case 'w': snake.SetDirection('w'); break;
        case 's': snake.SetDirection('s'); break;
        case 'x': gameOver = true; break;
        }
    }
}

void Game::Logic() {
    snake.Move();

    if (snake.CheckSelfCollision()) {
        gameOver = true;
    }

    auto head = snake.GetHeadPosition();
    auto fruitPos = fruit.GetPosition();

    if (head == fruitPos) {
        score += 10;
        fruit.GenerateNewPosition(snake.GetBody());
        snake.Grow();
    }
}

void Game::Draw() {
    board.Draw(snake, fruit);
    std::cout << "Score: " << score << std::endl;
}

void Game::Run() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // ChatGPT helped with syntax of this line:
    }
    Draw();
    std::cout << "Game Over!" << std::endl;
}
