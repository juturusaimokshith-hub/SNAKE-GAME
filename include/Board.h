#ifndef BOARD_H
#define BOARD_H

#include "Point.h"

class Snake;
class Food;

class Board {
private:
    int width;
    int height;

public:
    Board(int width, int height);

    bool isInside(const Point& position) const;
    int getWidth() const;
    int getHeight() const;

    void draw(const Snake& snake, const Food& food,
              int score, int highScore, bool paused) const;
};

#endif
