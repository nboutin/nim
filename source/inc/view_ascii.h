
#pragma once

#include "board.h"
#include "nim.h"
#include "player.h"

#include <optional>
#include <string>
#include <vector>

namespace nim
{
class View_ASCII
{
public:
    View_ASCII(const Board& b);

    void display(bool clear = true);
    void message(const std::string& msg);

    void set_history(const Nim::moves_t& h) { history = h; }
    void set_current_player(const Player& p) { current_player = p; }

private:
    void print_grid(const Board& b) const;
    void print_history() const;

    const Board& board;
    std::vector<std::string> msgs;
    Nim::moves_t history;
    Player current_player;
};
}
