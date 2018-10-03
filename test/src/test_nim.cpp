
#include "nim.h"

#include <catch.hpp>

using namespace nim;

TEST_CASE("finish", "[nim]")
{
    Nim n;
    REQUIRE_FALSE(n.is_finished());
    n.play(3);
    REQUIRE_FALSE(n.is_finished());
    n.play(3);
    REQUIRE_FALSE(n.is_finished());
    n.play(3);
    REQUIRE_FALSE(n.is_finished());
    n.play(3);
    REQUIRE_FALSE(n.is_finished());
    n.play(3);
    REQUIRE(n.is_finished());
}

TEST_CASE("winner", "[nim]")
{
    Nim n;
    REQUIRE(n.get_winner_player() == nullptr);
    n.play(3);
    n.play(3);
    n.play(3);
    n.play(3);
    n.play(3);
    REQUIRE(n.get_winner_player() != nullptr);
    REQUIRE(*n.get_winner_player() == n.get_player(player_e::p2));
}
