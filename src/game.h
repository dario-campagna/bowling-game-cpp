#ifndef BOWLINGGAME_GAME_H
#define BOWLINGGAME_GAME_H

#include <vector>

class Game {
    std::vector<int> rolled;
    bool isSpareFrame(int roll) const;
    bool isStrikeFrame(int roll) const;
    bool isLastFrame(int roll) const;
    int spareBonus(int roll) const;
    int strikeBonus(int roll) const;

public:

    void roll(int pins);

    int score();
};

#endif //BOWLINGGAME_GAME_H
