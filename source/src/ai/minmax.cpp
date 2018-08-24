
#include "minmax.h"

#include <iostream>
#include <limits>

#include "evaluate.h"
//#include "view_ascii.h"

using namespace ai;
using namespace p4;
using namespace std;

Minmax::Minmax(const p4::Player& p, const uint8_t depth) : depth(depth), player(p) {}

uint8_t Minmax::compute(p4::Game_P4 game)
{
    int16_t max       = std::numeric_limits<int16_t>::min();
    uint8_t best_move = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.get_current_player().get_color() != player.get_color())
        {
            cout << "error compute m:" << m << endl;
            abort();
        }

        if(game.play(m))
        {
            //        view::View_ASCII v(game.get_board());
            //        v.display(false);
            //        cout << __PRETTY_FUNCTION__ << endl;

            int16_t val = min(game, depth);

            if(val > max)
            {
                max       = val;
                best_move = m;
            }
        }
        game.undo();
        //        cout << "compute:: m:" << m << ", val:" << val << ", max:" << max
        //        << endl;
    }

    return best_move;
}

int16_t Minmax::min(p4::Game_P4& game, const uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
    {
        const auto score = evaluate(game.get_board().get_grid(), player.get_color());
        //        cout << "min out:" << score << endl;
        return score;
    }

    int16_t min = std::numeric_limits<int16_t>::max();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.get_current_player().get_color() == player.get_color())
        {
            cout << "min compute m:" << m << endl;
            abort();
        }

        if(game.play(m))
        {
            int16_t val = max(game, _depth - 1);
            if(val < min)
                min = val;

            //        view::View_ASCII v(game.get_board());
            //        v.display(false);

            //        cout << "min:: m:" << m << ", val:" << val << ", min:" << min <<
            //        endl;
        }
        game.undo();
    }
    return min;
}

int16_t Minmax::max(p4::Game_P4& game, const uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t max = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.get_current_player().get_color() != player.get_color())
        {
            cout << "max compute m:" << m << endl;
            abort();
        }

        if(game.play(m))
        {
            int16_t val = min(game, _depth - 1);
            if(val > max)
                max = val;
        }
        game.undo();
    }
    return max;
}
