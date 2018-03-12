#include "gtest/gtest.h"
#include "../src/game.h"

void roll(Game* game, int times, int pins) {
    for(int i = 0; i < times; i++){
        game->roll(pins);
    }
}

TEST(BowlingScoreTest, AllZerosIsZero) {
    Game game;
    roll(&game, 20, 0);
	ASSERT_EQ(game.score(), 0);
}

TEST(BowlingScoreTest, AllOnesIsTwenty) {
    Game game;
    roll(&game, 20, 1);
    ASSERT_EQ(game.score(), 20);
}
