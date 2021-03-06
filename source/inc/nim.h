
#pragma once

#include "board.h"
#include "player.h"

#include <optional>
#include <vector>

namespace nim
{
enum class player_e { p1, p2 };

class Nim
{
public:
    using moves_t = std::vector<std::optional<Board::move_t>>;

    Nim(Board::grid_t n_token = Board::TOKEN_COUNT);
    bool play(Board::move_t m);
    void undo();

    bool is_finished() const { return finished; };

    const Board& get_board() const { return board; }

    void set_player(player_e p, const Player& player);

    const Player& get_current_player() const { return *current_player; }
    const Player& get_player(player_e p);
    std::optional<Player> get_winner_player() const;

    moves_t get_history() const { return moves; }

private:
    void next_player();
    bool compute_ending();

    Player p1;
    Player p2;
    Player* current_player = nullptr;
    Player* winner_player  = nullptr;

    Board board;
    bool finished = false;
    moves_t moves;
};
}
