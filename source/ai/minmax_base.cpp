
#include "evaluate.h"
#include "minmax.h"

#include <algorithm>
#include <future>
#include <iostream>
#include <limits>
#include <utility>

using namespace ai;
using namespace nim;
using namespace std;

Minmax::Minmax(const Player& p, const depth_t depth) : depth(depth), player(p) {}

Board::move_t
Minmax::compute(Nim game, const algo algo, const std::chrono::seconds _duration_min) const
{
    start        = chrono::high_resolution_clock::now();
    duration_min = _duration_min;

    switch(algo)
    {
    case algo::minmax: return minmax(game);
    case algo::minmax_parallel: return minmax_parallel(game);
    }
    return {0};
}

std::array<nim::Board::move_t, Board::MOVE_MAX> Minmax::generate_moves() const { return {1, 2, 3}; }

bool Minmax::is_leaf(const Nim& game, const depth_t _depth) const
{
    auto d = chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - start);
    return (game.is_finished() || (_depth <= 0 && d >= duration_min));
}

Minmax::eval_t Minmax::minmax(Nim& game, const depth_t _depth, bool is_max) const
{
    if(is_leaf(game, _depth))
        return evaluate(game, player);

    if(!is_max)    // min
    {
        eval_t min = std::numeric_limits<int16_t>::max();
        auto moves = generate_moves();
        for(auto m : moves)
        {
            if(game.play(m))
                // TODO why cast ?
                min = std::min(min, static_cast<int16_t>(minmax(game, _depth - 1, true) - _depth));
            game.undo();
        }
        return min;
    }
    else
    {
        eval_t max = std::numeric_limits<int16_t>::min();
        auto moves = generate_moves();
        for(auto m : moves)
        {
            if(game.play(m))
                max = std::max(max, static_cast<int16_t>(minmax(game, _depth - 1, false) + _depth));
            game.undo();
        }
        return max;
    }
}
