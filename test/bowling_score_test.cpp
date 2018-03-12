#include "gtest/gtest.h"
#include "../src/game.h"

TEST(BowlingScoreTest, AllZerosIsZero) {
    Game game;
    for(int i = 0; i < 20; i++){
        game.roll(0);
    }
	ASSERT_EQ(game.score(), 0);
}
