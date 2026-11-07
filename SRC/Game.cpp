#include "../include/Game.h"

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <windows.h>

Game::Game()
    : snake(15, 7), board(30, 15),
      gameOver(false), paused(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    food.generate(board, snake);
}

void Game::start() {
    while (true) {
        run();

        std::cout << "\n\nGAME OVER!\n";
        std::cout << "Final score: " << scoreManager.getScore() << '\n';
        std::cout << "High score: " << scoreManager.getHighScore() << '\n';
        std::cout << "\nPress R to restart or Q to quit.\n";

        char choice = static_cast<char>(
            std::tolower(static_cast<unsigned char>(_getch()))
        );

        if (choice == 'r') {
            restart();
        } else {
            break;
        }
    }
}

void Game::run() {
    while (!gameOver) {
        update();
        render();

        if (paused) {
            Sleep(50); // Avoid busy-waiting while paused.
        } else {
            Sleep(120);
        }
    }
}

void Game::update() {
    char key = inputHandler.getInput();

    if (key == 'q') {
        gameOver = true;
        return;
    }

    if (key == 'p') {
        paused = !paused;
        return;
    }

    if (paused) {
        return;
    }

    inputHandler.processInput(key, snake);

    Point nextHead = snake.getNextHead();
    bool eatingFood = (nextHead == food.getPosition());

    if (!board.isInside(nextHead) ||
        snake.checkCollision(nextHead, eatingFood)) {
        gameOver = true;
        return;
    }

    if (eatingFood) {
        snake.grow();
    }

    updateEntities();

    if (eatingFood) {
        scoreManager.increaseScore(10);

        if (!food.generate(board, snake)) {
            gameOver = true; // No empty cell remains.
        }
    }
}

void Game::updateEntities() {
    // Runtime polymorphism: both objects are updated through base pointers.
    GameEntity* entities[] = { &snake, &food };

    for (GameEntity* entity : entities) {
        entity->update();
    }
}

void Game::render() const {
    board.draw(snake, food, scoreManager.getScore(),
               scoreManager.getHighScore(), paused);
}

bool Game::gameOverCheck() const {
    return gameOver;
}

void Game::restart() {
    snake = Snake(15, 7);
    scoreManager.reset();
    gameOver = false;
    paused = false;
    food.generate(board, snake);
}

void Game::pauseGame() {
    paused = true;
}

void Game::resumeGame() {
    paused = false;
}
