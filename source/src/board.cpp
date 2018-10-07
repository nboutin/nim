
#include "board.h"

using namespace nim;

bool Board::play(const move_t m)
{
    if((m < MOVE_MIN) || (m > MOVE_MAX) || (tokens_current - m) < TOKEN_MIN)
        return false;

    tokens_current -= m;
    return true;
}

void Board::unplay(const move_t m) { tokens_current += m; }
