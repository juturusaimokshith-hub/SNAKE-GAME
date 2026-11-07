#include "../include/Food.h"
#include "../include/Board.h"
#include "../include/Snake.h"

#include <cstdlib>
#include <vector>

Food::Food() : position(0, 0) {}

bool Food::generate(const Board& board, const Snake& snake) {
    std::vector<Point> emptyCells;

    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
            Point candidate(x, y);
            bool occupied = false;

            for (const Point& segment : snake.getBody()) {
                if (segment == candidate) {
                    occupied = true;
                    break;
                }
            }

            if (!occupied) {
                emptyCells.push_back(candidate);
            }
        }
    }

    if (emptyCells.empty()) {
        return false; // The snake has filled the board.
    }

    const std::size_t index =
        static_cast<std::size_t>(std::rand()) % emptyCells.size();

    position = emptyCells[index];
    return true;
}

Point Food::getPosition() const {
    return position;
}

void Food::update() {
    // Food remains stationary; generate() changes its position.
}

char Food::symbol() const {
    return '*';
}
