
#include "minmax.h"

using namespace ai;
using namespace p4;
using namespace std;

Minmax::Minmax(const p4::Player& p, uint8_t depth) : depth(depth), player(p) {}

uint8_t Minmax::compute(p4::Game_P4& game)
{
    int16_t max       = std::numeric_limits<int16_t>::min();
    uint8_t best_move = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        auto token = make_unique<Token>(game.get_current_player().get_color());
        game.play(m, move(token));

        int16_t val = min(game, depth);
        if(val > max)
        {
            max       = val;
            best_move = m;
        }

        game.unplay(m);
    }

    return best_move;
}

int16_t Minmax::min(p4::Game_P4& game, uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game);

    int16_t min = std::numeric_limits<int16_t>::max();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        auto token = make_unique<Token>(game.get_current_player().get_color());
        game.play(m, move(token));

        int16_t val = max(game, _depth - 1);
        if(val < min)
            min = val;

        game.unplay(m);
    }
    return min;
}

int16_t Minmax::max(p4::Game_P4& game, uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game);

    int16_t max = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        auto token = make_unique<Token>(game.get_current_player().get_color());
        game.play(m, move(token));

        int16_t val = min(game, _depth - 1);
        if(val > max)
            max = val;

        game.unplay(m);
    }
    return max;
}

int16_t Minmax::evaluate(const p4::Game_P4& game)
{
    int16_t score           = 0;
    Token::color_e ai_color = player.get_color();
    const auto& b           = game.get_board().get_board();

    array<Cell, 4> v3;
    v3[1] = move(make_unique<Token>(ai_color));
    v3[2] = move(make_unique<Token>(ai_color));
    v3[3] = move(make_unique<Token>(ai_color));

    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        int ai = 0;
        int op = 0;    // opponent
        for(int y = 0; y < Board::N_ROW; ++y)
        {
            array<Cell, 4> test;
            std::copy(b[x].begin() + y, b[x].begin() + y + 4, test);
            if(v3 == test)
                ai += 3;
        }
        score += ai;
    }

    return score;
}
