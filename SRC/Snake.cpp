#include "../include/Snake.h"

Snake::Snake(int startX, int startY)
    : direction(Direction::RIGHT), pendingGrowth(false) {
    body.push_back(Point(startX, startY));
    body.push_back(Point(startX - 1, startY));
    body.push_back(Point(startX - 2, startY));
}

Point Snake::getNextHead() const {
    Point next = body.front();

    switch (direction) {
        case Direction::UP:    --next.y; break;
        case Direction::DOWN:  ++next.y; break;
        case Direction::LEFT:  --next.x; break;
        case Direction::RIGHT: ++next.x; break;
    }

    return next;
}

Point Snake::getHead() const {
    return body.front();
}

const std::deque<Point>& Snake::getBody() const {
    return body;
}

void Snake::changeDirection(Direction newDirection) {
    // Prevent an immediate 180-degree turn.
    if ((direction == Direction::UP && newDirection == Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection == Direction::UP) ||
        (direction == Direction::LEFT && newDirection == Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection == Direction::LEFT)) {
        return;
    }

    direction = newDirection;
}

void Snake::move() {
    body.push_front(getNextHead());

    if (!pendingGrowth) {
        body.pop_back();
    }

    pendingGrowth = false;
}

void Snake::grow() {
    pendingGrowth = true;
}

bool Snake::checkCollision(const Point& nextPosition, bool willGrow) const {
    // If the snake is not growing, its current tail moves away.
    // Therefore, moving into that tail cell is allowed.
    std::size_t segmentsToCheck = body.size();

    if (!willGrow && segmentsToCheck > 0) {
        --segmentsToCheck;
    }

    for (std::size_t i = 0; i < segmentsToCheck; ++i) {
        if (body[i] == nextPosition) {
            return true;
        }
    }

    return false;
}

void Snake::update() {
    move();
}

char Snake::symbol() const {
    return 'O';
}
