#ifndef BOWLINGGAME_GAME_H
#define BOWLINGGAME_GAME_H

#include <vector>

class Game {
    std::vector<int> rolled;
public:
    void roll(int pins);
    int score();
};

#endif //BOWLINGGAME_GAME_H
