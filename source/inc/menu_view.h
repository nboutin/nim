
#pragma once

#include "player.h"

#include <vector>

namespace nim
{
class Menu_View
{
public:
    void display();

    int get_token_count() const { return tokens_count; }
    std::vector<Player> get_players() const { return players; }
    int get_ai_level() const { return ai_level; }

private:
    void construct_player(int player_num);

    int tokens_count = 15;
    std::vector<Player> players{};
    int ai_level = 6;
};
}
