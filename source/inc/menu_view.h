
#pragma once

#include "player.h"

#include <vector>

namespace nim
{
class Menu_View
{
public:
    void display();

    std::vector<Player> get_players() const { return players; }

private:
    void construct_player(int player_num);

    std::vector<Player> players;
};
}
