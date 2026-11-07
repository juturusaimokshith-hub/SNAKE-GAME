#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

class ScoreManager {
private:
    int score;
    int highScore;

public:
    ScoreManager();

    void increaseScore(int points);
    int getScore() const;
    int getHighScore() const;

    void loadHighScore();
    void saveHighScore() const;
    void reset();
};

#endif
