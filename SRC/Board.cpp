#include "../include/Board.h"
#include "../include/Snake.h"
#include "../include/Food.h"

#include <cstdlib>
#include <iostream>

Board::Board(int boardWidth, int boardHeight)
    : width(boardWidth), height(boardHeight) {}

bool Board::isInside(const Point& position) const {
    return position.x >= 0 && position.x < width &&
           position.y >= 0 && position.y < height;
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

void Board::draw(const Snake& snake, const Food& food,
                 int score, int highScore, bool paused) const {
    std::system("cls");

    std::cout << "========== SNAKE GAME ==========\n";
    std::cout << "Score: " << score
              << "    High score: " << highScore << "\n\n";

    const auto& body = snake.getBody();

    for (int y = -1; y <= height; ++y) {
        for (int x = -1; x <= width; ++x) {
            if (x == -1 || x == width || y == -1 || y == height) {
                std::cout << '#';
                continue;
            }

            Point cell(x, y);

            if (cell == food.getPosition()) {
                std::cout << food.symbol();
                continue;
            }

            bool foundSnake = false;

            for (std::size_t i = 0; i < body.size(); ++i) {
                if (body[i] == cell) {
                    std::cout << (i == 0 ? snake.symbol() : 'o');
                    foundSnake = true;
                    break;
                }
            }

            if (!foundSnake) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    std::cout << "\nControls: Arrow keys or W/A/S/D | P: pause | Q: quit\n";

    if (paused) {
        std::cout << "\n*** PAUSED - press P to resume ***\n";
    }
}
