//
// Created by zakrent on 2/27/18.
//

#include "ScoreManager.h"

void ScoreManager::registerScore(double xPos) {
    double givenScore = xPos;
    if(givenScore > currentScore){
        currentScore = givenScore;
    }
}

double ScoreManager::getCurrentScore() {
    return currentScore;
}

ScoreManager::ScoreManager() {
    currentScore = 0;
}
