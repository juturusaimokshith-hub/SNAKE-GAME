#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "Point.h"
#include "Direction.h"
#include "GameEntity.h"

class Snake : public GameEntity {
private:
    std::deque<Point> body;
    Direction direction;
    bool pendingGrowth;

public:
    Snake(int startX, int startY);

    Point getNextHead() const;
    Point getHead() const;
    const std::deque<Point>& getBody() const;

    void changeDirection(Direction newDirection);
    void move();
    void grow();
    bool checkCollision(const Point& nextPosition, bool willGrow) const;

    void update() override;
    char symbol() const override;
};

#endif
