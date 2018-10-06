
#include "minmax.h"
#include "nim.h"

#include <catch.hpp>

using namespace nim;
using namespace ai;

TEST_CASE("minmax", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};

    SECTION("")
    {
        Nim n(2);
        n.set_player(player_e::p1, players.at(0));
        n.set_player(player_e::p2, players.at(1));

        Minmax m(n.get_player(player_e::p1), 0);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("")
    {
        Nim n(2);
        n.set_player(player_e::p1, players.at(0));
        n.set_player(player_e::p2, players.at(1));

        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }
}
