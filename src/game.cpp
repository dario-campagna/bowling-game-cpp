#include "game.h"

void Game::roll(int pins) {
    Game::rolled += pins;
}

int Game::score() {
    return rolled;
}
