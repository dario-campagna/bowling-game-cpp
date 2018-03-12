#include "game.h"

void Game::roll(int pins) {
    rolled.push_back(pins);
}

int Game::score() {
    int score = 0;
    for (int roll = 0; roll < rolled.size(); roll++){
        if (isSpareFrame(roll) && !isLastFrame(roll)) {
            score += 10 + spareBonus(roll);
            roll++;
        } else if (isStrikeFrame(roll) && !isLastFrame(roll)) {
            score += 10 + strikeBonus(roll);
        } else {
            score += rolled[roll];
        }
    }
    return score;
}

int Game::spareBonus(int roll) const { return rolled[roll + 2]; }

int Game::strikeBonus(int roll) const { return rolled[roll+1] + rolled[roll + 2]; }

bool Game::isStrikeFrame(int roll) const { return rolled[roll] == 10; }

bool Game::isLastFrame(int roll) const { return roll + 2 >= rolled.size() - 1; }

bool Game::isSpareFrame(int roll) const { return rolled[roll] + rolled[roll + 1] == 10; }
