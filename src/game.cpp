#include "game.h"

void Game::roll(int pins) {
    rolled.push_back(pins);
}

int Game::score() {
    int score = 0;
    for (int i = 0; i < rolled.size(); i++){
        if (isSpareFrame(i) && i+2 < rolled.size()-1) {
            score += spare(i);
            i++;
        } else if (rolled[i] == 10 && i+2 < rolled.size()-1) {
            score += 10 + rolled[i+1] + rolled[i+2];
        } else {
            score += rolled[i];
        }
    }
    return score;
}

int Game::spare(int i) const { return 10 + rolled[i + 2]; }

bool Game::isSpareFrame(int i) const { return rolled[i] + rolled[i + 1] == 10; }
