
#include "evaluate.h"

using namespace nim;

namespace ai
{
int16_t evaluate(const Nim& g, const Player& ai_player)
{
    if(g.is_finished() && g.get_winner_player())
    {
        if(g.get_winner_player() == ai_player)
            return WIN_POINT;
        else
            return LOOSE_POINT;
    }
    return 0;
}
}
