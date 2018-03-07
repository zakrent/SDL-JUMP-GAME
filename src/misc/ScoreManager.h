//
// Created by zakrent on 2/27/18.
//

#ifndef SDL_JUMP_SCOREMANAGER_H
#define SDL_JUMP_SCOREMANAGER_H


class ScoreManager {
    double currentScore;
    double highScore;
public:
    void restart();
    void registerScore(double xPos);
    double getCurrentScore();
    double getHighScore();
    ScoreManager();
};


#endif //SDL_JUMP_SCOREMANAGER_H
