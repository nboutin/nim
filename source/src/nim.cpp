
#include "nim.h"

#include <cassert>

using namespace nim;
using namespace std;

Nim::Nim(Board::grid_t n_token)
    : p1("Player 1"), p2("Player 2"), current_player(&p1), board(n_token)
{}

bool Nim::play(const Board::move_t m)
{
    if(finished)
    {
        moves.push_back({});    // bad move
        return false;
    }

    if(!board.play(m))
    {
        moves.push_back({});    // bad move
        return false;
    }

    moves.push_back({m});
    compute_ending();
    next_player();

    return true;
}

void Nim::undo()
{
    auto last_move = moves.back();
    moves.pop_back();

    if(last_move)
    {
        board.unplay(last_move.value());
        next_player();
    }
    finished = false;
}

bool Nim::compute_ending()
{
    // The player who takes the last token loose
    finished = (board.get_tokens() == Board::TOKEN_MIN);
    if(finished)
    {
        if(*current_player == p1)
            winner_player = &p2;
        else
            winner_player = &p1;
    }
    return finished;
}

void Nim::next_player()
{
    if(*current_player == p1)
        current_player = &p2;
    else
        current_player = &p1;
}

std::optional<Player> Nim::get_winner_player() const
{
    if(winner_player == nullptr)
        return {};
    else
        return *winner_player;
}

const Player& Nim::get_player(const player_e p)
{
    switch(p)
    {
    case player_e::p1: return p1;
    case player_e::p2: return p2;
    default:;
    }
    assert(false);
}

void Nim::set_player(const player_e p, const Player& player)
{
    switch(p)
    {
    case player_e::p1: p1 = player; break;
    case player_e::p2: p2 = player; break;
    }
}
