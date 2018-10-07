
#pragma once

#include "nim.h"

#include <array>
#include <chrono>

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(0);
    enum class algo { minmax, minmax_parallel };

    using depth_t = int16_t;
    using eval_t  = int16_t;

    Minmax(const nim::Player& p, depth_t depth);

    nim::Board::move_t
    compute(nim::Nim game, algo algo, std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    std::array<nim::Board::move_t, nim::Board::MOVE_MAX> generate_moves() const;
    bool is_leaf(const nim::Nim& game, depth_t depth) const;

    eval_t minmax(nim::Nim& game, depth_t depth, bool is_max) const;
    nim::Board::move_t minmax_parallel(nim::Nim& game) const;
    eval_t minmax_copy(nim::Nim game, const depth_t depth, bool is_max) const;

    depth_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const nim::Player& player;
};
}
