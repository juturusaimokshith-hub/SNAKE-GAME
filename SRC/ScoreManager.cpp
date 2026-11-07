#include "../include/ScoreManager.h"

#include <fstream>

ScoreManager::ScoreManager() : score(0), highScore(0) {
    loadHighScore();
}

void ScoreManager::increaseScore(int points) {
    score += points;

    if (score > highScore) {
        highScore = score;
        saveHighScore();
    }
}

int ScoreManager::getScore() const {
    return score;
}

int ScoreManager::getHighScore() const {
    return highScore;
}

void ScoreManager::loadHighScore() {
    std::ifstream file("highscore.txt");

    if (file.is_open()) {
        file >> highScore;
    }
}

void ScoreManager::saveHighScore() const {
    std::ofstream file("highscore.txt");

    if (file.is_open()) {
        file << highScore;
    }
}

void ScoreManager::reset() {
    score = 0;
}
