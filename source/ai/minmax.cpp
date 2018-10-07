
#include "minmax.h"

using namespace ai;
using namespace nim;

nim::Board::move_t Minmax::minmax(nim::Nim& game) const
{
    auto max = std::numeric_limits<eval_t>::min();
    Board::move_t best_move{};

    for(auto m : generate_moves())
    {
        if(game.play(m))
        {
            auto val = minmax(game, depth, false);
            if(val > max)
            {
                max       = val;
                best_move = m;
            }
        }
        game.undo();
    }
    return best_move;
}
