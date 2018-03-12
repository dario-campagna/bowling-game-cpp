#ifndef BOWLINGGAME_GAME_H
#define BOWLINGGAME_GAME_H

class Game {
    int rolled = 0;
public:
    void roll(int pins);
    int score();
};

#endif //BOWLINGGAME_GAME_H
