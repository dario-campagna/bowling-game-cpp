#include "gtest/gtest.h"
#include "../src/game.h"

void rollMany(Game *game, int times, int pins) {
    for(int i = 0; i < times; i++){
        game->roll(pins);
    }
}

void spare(Game* game){
    game->roll(5);
    game->roll(5);
}

TEST(BowlingScoreTest, GutterGame) {
    Game game;
    rollMany(&game, 20, 0);
	ASSERT_EQ(game.score(), 0);
}

TEST(BowlingScoreTest, AllOnes) {
    Game game;
    rollMany(&game, 20, 1);
    ASSERT_EQ(game.score(), 20);
}

TEST(BowlingScoreTest, OneSpare){
    Game game;
    spare(&game);
    game.roll(6);
    rollMany(&game, 17, 0);
    ASSERT_EQ(game.score(), 22);
}

TEST(BowlingScoreTest, TwoSpares){
    Game game;
    spare(&game);
    game.roll(6);
    game.roll(0);
    spare(&game);
    game.roll(8);
    rollMany(&game, 13, 0);
    ASSERT_EQ(game.score(), 48);
}

TEST(BowlingScoreTest, SpareOnLastFrame) {
    Game game;
    rollMany(&game, 18, 0);
    spare(&game);
    game.roll(3);
    ASSERT_EQ(game.score(), 13);
}

TEST(BowlingScoreTest, OneStrike) {
    Game game;
    game.roll(10);
    game.roll(2);
    game.roll(7);
    rollMany(&game, 16, 0);
    ASSERT_EQ(game.score(), 28);
}

TEST(BowlingScoreTest, PerfectGame) {
    Game game;
    rollMany(&game, 12, 10);
    ASSERT_EQ(game.score(), 300);
}
