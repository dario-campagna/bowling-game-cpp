#include "game.h"

void Game::roll(int pins) {
    rolled.push_back(pins);
}

int Game::score() {
    int score = 0;
    for (int i = 0; i < rolled.size(); i++){
        if (rolled[i] + rolled[i+1] == 10){
            score += 10 + rolled[i+2];
            i++;
        } else {
            score += rolled[i];
        }
    }
    return score;
}
