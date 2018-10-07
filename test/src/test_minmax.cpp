
#include "minmax.h"
#include "nim.h"

#include <catch.hpp>

using namespace nim;
using namespace ai;

TEST_CASE("ai is 2nd player, nim = 7", "[minmax]")
{
    std::vector<Player> players{{"p1", false}, {"ai", true}};
    Nim n(7);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    n.play(1);

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p2), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p2), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 3")
    {
        Minmax m(n.get_player(player_e::p2), 3);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 4")
    {
        Minmax m(n.get_player(player_e::p2), 4);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }
}

TEST_CASE("ai is 2nd player, nim = 5", "[minmax]")
{
    std::vector<Player> players{{"p1", false}, {"ai", true}};
    Nim n(5);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    n.play(1);

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p2), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 3);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p2), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 3);
    }
}

TEST_CASE("ai is 2nd player, nim = 4", "[minmax]")
{
    std::vector<Player> players{{"p1", false}, {"ai", true}};
    Nim n(4);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    n.play(1);

    SECTION("depth 0")
    {
        Minmax m(n.get_player(player_e::p2), 0);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p2), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 2);
    }
}

TEST_CASE("ai is 2nd player, nim = 3", "[minmax]")
{
    std::vector<Player> players{{"p1", false}, {"ai", true}};
    Nim n(3);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    n.play(1);

    SECTION("depth 0")
    {
        Minmax m(n.get_player(player_e::p2), 0);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p2), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }
}

TEST_CASE("nim = 7", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};
    Nim n(7);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p1), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 3")
    {
        Minmax m(n.get_player(player_e::p1), 3);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 2);
    }
}

TEST_CASE("nim = 6", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};
    Nim n(6);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p1), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 3")
    {
        Minmax m(n.get_player(player_e::p1), 3);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }
}

TEST_CASE("nim = 5", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};
    Nim n(5);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p1), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }
}

TEST_CASE("nim = 4", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};
    Nim n(4);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    SECTION("depth 0")
    {
        Minmax m(n.get_player(player_e::p1), 0);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 3);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p1), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 3);
    }

    SECTION("depth 3")
    {
        Minmax m(n.get_player(player_e::p1), 3);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 3);
    }
}

TEST_CASE("nim = 3", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};
    Nim n(3);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    SECTION("depth 0")
    {
        Minmax m(n.get_player(player_e::p1), 0);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 2);
    }

    SECTION("depth 2")
    {
        Minmax m(n.get_player(player_e::p1), 2);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 2);
    }
}

TEST_CASE("nim = 2", "[minmax]")
{
    std::vector<Player> players{{"ai", true}, {"p2", false}};
    Nim n(2);
    n.set_player(player_e::p1, players.at(0));
    n.set_player(player_e::p2, players.at(1));

    SECTION("depth 0")
    {
        Minmax m(n.get_player(player_e::p1), 0);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }

    SECTION("depth 1")
    {
        Minmax m(n.get_player(player_e::p1), 1);
        auto move = m.compute(n, Minmax::algo::minmax);

        REQUIRE(move == 1);
    }
}
