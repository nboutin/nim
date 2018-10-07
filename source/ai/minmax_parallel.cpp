
#include "minmax.h"

#include <future>
#include <utility>
#include <vector>

using namespace ai;
using namespace nim;

int16_t Minmax::minmax_copy(Nim game, const depth_t depth, bool is_max) const
{
    return minmax(game, depth, is_max);
}

nim::Board::move_t Minmax::minmax_parallel(nim::Nim& game) const
{
    Board::move_t best_move{};
    auto max    = std::numeric_limits<eval_t>::min();
    using f_min = std::pair<Board::move_t, std::future<int16_t>>;
    std::vector<f_min> vf_mins;

    auto moves = generate_moves();
    for(auto move : moves)
    {
        if(game.play(move))
        {
            vf_mins.push_back(make_pair(
                move,
                std::async(std::launch::async, &Minmax::minmax_copy, this, game, depth, false)));
        }
        game.undo();
    }

    for(auto&& mr : vf_mins)
    {
        auto val = mr.second.get();
        if(val > max)
        {
            max       = val;
            best_move = mr.first;
        }
    }
    return best_move;
}
