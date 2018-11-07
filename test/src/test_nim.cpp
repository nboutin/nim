
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

    REQUIRE_FALSE(n.play(3));
}

TEST_CASE("winner", "[nim]")
{
    Nim n;
    REQUIRE_FALSE(n.get_winner_player());
    n.play(3);
    n.play(3);
    n.play(3);
    n.play(3);
    n.play(3);
    REQUIRE(n.get_winner_player());
    REQUIRE(n.get_winner_player().value() == n.get_player(player_e::p2));
}

TEST_CASE("get player", "[nim]")
{
	Nim n;
	REQUIRE(n.get_player(player_e(3)) == n.get_player(player_e::p1));
}
