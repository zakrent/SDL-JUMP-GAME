//
// Created by zakrent on 2/27/18.
//

#include <cmath>
#include "ScoreManager.h"

void ScoreManager::registerScore(double xPos) {
    double givenScore = fabs(xPos);
    if(givenScore > currentScore){
        currentScore = givenScore;
    }
    if(currentScore > highScore){
        highScore = currentScore;
    }
}

double ScoreManager::getCurrentScore() {
    return currentScore;
}

ScoreManager::ScoreManager() {
    currentScore = 0;
    highScore = 0;
}

void ScoreManager::restart() {
    currentScore = 0;
}

double ScoreManager::getHighScore() {
    return highScore;
}
