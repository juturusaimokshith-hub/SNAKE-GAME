#ifndef FOOD_H
#define FOOD_H

#include "Point.h"
#include "GameEntity.h"

class Board;
class Snake;

class Food : public GameEntity {
private:
    Point position;

public:
    Food();

    bool generate(const Board& board, const Snake& snake);
    Point getPosition() const;

    void update() override;
    char symbol() const override;
};

#endif
