#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "InputHandler.h"
#include "ScoreManager.h"

class Game {
private:
    Snake snake;
    Food food;
    Board board;
    InputHandler inputHandler;
    ScoreManager scoreManager;

    bool gameOver;
    bool paused;

    void updateEntities();

public:
    Game();

    void start();
    void run();
    void update();
    void render() const;

    bool gameOverCheck() const;
    void restart();
    void pauseGame();
    void resumeGame();
};

#endif
