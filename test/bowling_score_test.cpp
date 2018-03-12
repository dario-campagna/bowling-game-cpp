#include "gtest/gtest.h"
#include "../src/game.h"

void roll(Game* game, int times, int pins) {
    for(int i = 0; i < times; i++){
        game->roll(pins);
    }
}

void spare(Game* game){
    game->roll(5);
    game->roll(5);
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

TEST(BowlingScoreTest, OneSpareOneSixAndAllZerosIsTwentytwo){
    Game game;
    game.roll(3);
    game.roll(7);
    game.roll(6);
    roll(&game, 17, 0);
    ASSERT_EQ(game.score(), 22);
}

TEST(BowlingScoreTest, OneSpareOneSixOneSpareOneEightAndAllZerosIsTwentytwo){
    Game game;
    spare(&game);
    game.roll(6);
    game.roll(0);
    spare(&game);
    game.roll(8);
    roll(&game, 13, 0);
    ASSERT_EQ(game.score(), 48);
}

TEST(BowlingScoreTest, AllZerosSpareOnLastFrameAndThreeIsSixteen) {
    Game game;
    roll(&game, 18, 0);
    spare(&game);
    game.roll(3);
    ASSERT_EQ(game.score(), 16);
}

TEST(BowlingScoreTest, OneStrikeOneTwoOneSevenAndAllZerosIsTwentyeight) {
    Game game;
    game.roll(10);
    game.roll(2);
    game.roll(7);
    roll(&game, 16, 0);
    ASSERT_EQ(game.score(), 28);
}

TEST(BowlingScoreTest, AllStrikesIsThreehundred) {
    Game game;
    roll(&game, 12, 10);
    ASSERT_EQ(game.score(), 300);
}
