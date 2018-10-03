
#include "board.h"

#include <catch.hpp>

using namespace nim;

TEST_CASE("default", "[board]")
{
    Board b;
    REQUIRE(b.get_tokens() == Board::TOKEN_COUNT);
}

TEST_CASE("play", "[board]")
{
    Board b;
    REQUIRE(b.play(1));
    REQUIRE(b.play(2));
    REQUIRE(b.play(3));
}

TEST_CASE("unplay", "[board]")
{
    Board b;
    b.play(3);
    b.unplay(1);
    REQUIRE(b.get_tokens() == Board::TOKEN_COUNT - 3 + 1);
}

TEST_CASE("boundaries", "[board]")
{
    Board b;
    REQUIRE_FALSE(b.play(0));
    REQUIRE_FALSE(b.play(4));
}

TEST_CASE("tokens", "[board]")
{
    Board b;
    b.play(3);
    REQUIRE(b.get_tokens() == Board::TOKEN_COUNT - 3);

    b.play(2);
    REQUIRE(b.get_tokens() == Board::TOKEN_COUNT - 3 - 2);

    b.play(1);
    REQUIRE(b.get_tokens() == Board::TOKEN_COUNT - 3 - 2 - 1);
}
