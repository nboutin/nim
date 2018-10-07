
#pragma once

#include <cstdint>

namespace nim
{
class Board
{
public:
    using move_t = uint8_t;
    using grid_t = int8_t;

    static constexpr grid_t TOKEN_COUNT = 15;
    static constexpr grid_t TOKEN_MIN   = 0;
    static constexpr move_t MOVE_MIN    = 1;
    static constexpr move_t MOVE_MAX    = 3;

    Board(grid_t n_token = TOKEN_COUNT) : tokens_default(n_token), tokens_current(n_token) {}

    bool play(move_t m);
    void unplay(move_t m);

    grid_t get_tokens() const { return tokens_current; }
    grid_t get_default_tokens() const { return tokens_default; }

private:
    grid_t tokens_default = TOKEN_COUNT;
    grid_t tokens_current = TOKEN_COUNT;
};
}
